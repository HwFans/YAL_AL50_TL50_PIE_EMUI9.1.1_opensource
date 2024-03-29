#ifndef __NPU_BLACK_BOX_H
#define __NPU_BLACK_BOX_H

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sysfs.h>
#include <linux/semaphore.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/stat.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

#include <linux/hisi/rdr_pub.h>
#include "npu_manager_common.h"
#include "npu_common.h"
#include "drv_log.h"

/* AI DRD */
#define DEVDRV_NPU_BUF_LEN_MAX        (256)

/* TSCPU : 256K, inside Aicore : 128K, LiteOS : 5K, TaskScheduler : 64K */
#define DEVDRV_NPU_BBOX_MEM_MAX       (0x40000) /* 256K */

/* AICPU : 64K */
#define DEVDRV_AICPU_BBOX_MEM_MAX       (0x10000) /* 64K */

#define BBOX_ADDR_LEN  (0x40000) /* 256K */

/* aicpu resume addr and len */
#define AICPU_BUFF_OFFSET (0xb3000) /* 0x2E3F3000 */
#define AICPU_BUFF_LEN (0x4000) /* 16K */

#define MODULE_INFO_OFFSET (64)  /* = sizeof(exce_module_info_t) in TSCH */

enum rdr_npu_system_error_type {
    EXC_TYPE_NO_ERROR = 0x0,
    MODID_NPU_START = HISI_BB_MOD_NPU_START, /* HISI_BB_MOD_NPU_START == 0xc0000000 */

    /* OS exception code 0xc0000000-0xc00000ff */
    EXC_TYPE_OS_DATA_ABORT = MODID_NPU_START,
    EXC_TYPE_OS_INSTRUCTION_ABORT = 0xc0000001,
    EXC_TYPE_OS_PC_ALIGN_FAULT = 0xc0000002,
    EXC_TYPE_OS_SP_ALIGN_FAULT = 0xc0000003,
    EXC_TYPE_OS_INFINITE_LOOP = 0xc0000004,
    EXC_TYPE_OS_UNKNOWN_EXCEPTION = 0xc0000005,
    RDR_EXC_TYPE_OS_EXCEPTION = 0xc0000006,

    /* AICPU exception code 0xc0000100-0xc00001ff, only for AICPU use */
    MODID_NPU_AICPU_START = 0xc0000100,
    MODID_NPU_AICPU_END = 0xc00001ff,

    /* AICORE exception code 0xc0000200-0xc00002ff */
    EXC_TYPE_TS_AICORE_EXCEPTION = 0xc0000200,
    EXC_TYPE_TS_AICORE_TIMEOUT = 0xc0000201,

    /* SDMA exception code 0xc0000300-0xc00003ff */
    EXC_TYPE_TS_SDMA_EXCEPTION = 0xc0000300,
    EXC_TYPE_TS_SDMA_TIMEOUT = 0xc0000301,

    /* TS exception code 0xc0000400-0xc00004ff */
    RDR_EXC_TYPE_TS_RUNNING_EXCEPTION = 0xc0000400,
    RDR_EXC_TYPE_TS_RUNNING_TIMEOUT = 0xc0000401,
    RDR_EXC_TYPE_TS_INIT_EXCEPTION = 0xc0000402,

    /* AICPU exception code 0xc0000500-0xc00005ff */
    RDR_EXC_TYPE_AICPU_INIT_EXCEPTION = 0xc0000500,
    RDR_EXC_TYPE_AICPU_HEART_BEAT_EXCEPTION = 0xc0000501,

    /* driver exception code 0xc0000600-0xc00006ff, only for driver */
    RDR_EXC_TYPE_NPU_POWERUP_FAIL = 0xc0000600,
    RDR_EXC_TYPE_NPU_POWERDOWN_FAIL = 0xc0000601,
    RDR_EXC_TYPE_NPU_SMMU_EXCEPTION = 0xc0000602,

    MODID_NPU_EXC_END = HISI_BB_MOD_NPU_END, /* HISI_BB_MOD_NPU_END == 0xc0000fff */

    DMD_EXC_TYPE_EXCEPTION_START = 0xc0001000, /*for lite DMD*/
    DMD_EXC_TYPE_EXCEPTION_END = 0xc000101f, /*for lite DMD*/
};

typedef enum {
	NPU_CORE_0,
	NPU_CORE_1,
	MAX_SUPPORT_CORE_NUM,
} NPU_CORE_ID_E;

struct list_head_rdr {
	struct list_head_rdr *next, *prev;
};

/****************************** AICPU struct *******************************/
struct aicpu_excep_time_t {
	u64 tv_sec;
	u64 tv_usec;
};

struct exc_info_s {
	struct aicpu_excep_time_t e_clock;
	u32 e_excepid;
	u16 e_dump_status;
	u16 e_save_status;
};

struct exc_description_s {
	u32 e_modid;
	u8 e_process_level;
	u8 e_reboot_priority;
	u8 e_exce_type;
	u8 e_reentrant;
	u64 e_notify_core_mask;
	u8 e_desc[48];
};

struct exc_module_info_s {
	u32 magic;
	u16 e_mod_valid;
	u16 e_mod_num;
	u8 e_from_module[16];
	struct exc_info_s cur_info;
	u32 e_mini_offset;
	u32 e_mini_len;
	u32 e_info_offset;
	u32 e_info_len;
	struct exc_description_s e_description[0];
};
/****************************** AICPU struct *******************************/

typedef struct tag_bbox_exception_info
{
    uint32_t log_len; /* exception info len */
}bbox_exception_info_t;

struct devdrv_npu_peri_reg_s {
    unsigned int peri_stat;
    unsigned int ppll_select;
    unsigned int power_stat;
    unsigned int power_ack;
    unsigned int reset_stat;
    unsigned int perclken0;
    unsigned int perstat0;
};

struct devdrv_npu_mstr_reg_s {
    unsigned int rd_bitmap;
    unsigned int wr_bitmap;
    unsigned int rd_cmd_total_cnt0;
    unsigned int rd_cmd_total_cnt1;
    unsigned int rd_cmd_total_cnt2;
    unsigned int wr_cmd_total_cnt;
};

struct devdrv_npu_exc_info_s {
    unsigned int interrupt_status;
    unsigned int target_ip;
    int          result;
};

struct devdrv_npu_dump_info_s {
    u32 modid;
    u64 coreid;
    //devdrv_pfn_cb_dump_done cb;
    pfn_cb_dump_done cb;
    char *pathname;
};

struct devdrv_npu_mntn_info_s {
    unsigned int bbox_addr_offset;
    unsigned int aicpu_add_offset;
    struct rdr_register_module_result npu_ret_info;/*struct rdr_register_module_result npu_ret_info;*/
    struct devdrv_npu_dump_info_s dump_info;
    void   *rdr_addr;
};

struct devdrv_npu_reg_info_s {
    struct devdrv_npu_peri_reg_s peri_reg;
    struct devdrv_npu_mstr_reg_s mstr_reg;
};

struct devdrv_npu_mntn_private_s {
    unsigned int core_id;
    struct devdrv_npu_mntn_info_s mntn_info;
    struct devdrv_npu_reg_info_s  reg_info[MAX_SUPPORT_CORE_NUM];
    struct devdrv_npu_exc_info_s  exc_info[MAX_SUPPORT_CORE_NUM];
    struct work_struct     dump_work;
    struct workqueue_struct *rdr_wq;
};

int npu_black_box_init(void);
int npu_black_box_exit(void);
int npu_rdr_resource_init(void);
int npu_rdr_register_exception(void);
int npu_rdr_register_core(void);
int npu_rdr_addr_map(void);


#endif /* __NPU_BLACK_BOX_H */
