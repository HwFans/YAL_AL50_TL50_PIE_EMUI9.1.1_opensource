/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifdef BSP_CONFIG_PHONE_TYPE
#include "../../adrv/adrv.h"
#else
#include <linux/hisi/rdr_pub.h>
#endif

#ifndef __DUMP_EXC_TYPE_H__
#define __DUMP_EXC_TYPE_H__
#include "bsp_dump.h"
/*modem cp�쳣��rdr id*/
#define RDR_MODEM_CP_DRV_MOD_ID_START           0x00000000
#define RDR_MODEM_CP_DRV_MOD_ID_END             0x0fffffff
#define RDR_MODEM_CP_OSA_MOD_ID_START           0x10000000
#define RDR_MODEM_CP_OSA_MOD_ID_END             0x1fffffff
#define RDR_MODEM_CP_OAM_MOD_ID_START           0x20000000
#define RDR_MODEM_CP_OAM_MOD_ID_END             0x2fffffff
#define RDR_MODEM_CP_GUL2_MOD_ID_START          0x30000000
#define RDR_MODEM_CP_GUL2_MOD_ID_END            0x3effffff
#define RDR_MODEM_CP_CTTF_MOD_ID_START          0x3f000000
#define RDR_MODEM_CP_CTTF_MOD_ID_END            0x3fffffff
#define RDR_MODEM_CP_GUWAS_MOD_ID_START         0x40000000
#define RDR_MODEM_CP_GUWAS_MOD_ID_END           0x4dffffff
#define RDR_MODEM_CP_CAS_MOD_ID_START           0x4e000000
#define RDR_MODEM_CP_CAS_MOD_ID_END             0x4effffff
#define RDR_MODEM_CP_CPROC_MOD_ID_START         0x4f000000
#define RDR_MODEM_CP_CPROC_MOD_ID_END           0x4fffffff
#define RDR_MODEM_CP_GUGAS_MOD_ID_START         0x50000000
#define RDR_MODEM_CP_GUGAS_MOD_ID_END           0x5fffffff
#define RDR_MODEM_CP_GUCNAS_MOD_ID_START        0x60000000
#define RDR_MODEM_CP_GUCNAS_MOD_ID_END          0x6fffffff
#define RDR_MODEM_CP_GUDSP_MOD_ID_START         0x70000000
#define RDR_MODEM_CP_GUDSP_MOD_ID_END           0x75ffffff
#define RDR_MODEM_CP_EASYRF_MOD_ID_START        0x76000000
#define RDR_MODEM_CP_EASYRF_MOD_ID_END          0x7fffffff
#define RDR_MODEM_CP_LPS_MOD_ID_START           0xa0000000
#define RDR_MODEM_CP_LPS_MOD_ID_END             0xafffffff
#define RDR_MODEM_CP_MSP_MOD_ID_START           0xb0000000
#define RDR_MODEM_CP_MSP_MOD_ID_END             0xbfffffff
#define RDR_MODEM_CP_TLDSP_MOD_ID_START         0xc0000000
#define RDR_MODEM_CP_TLDSP_MOD_ID_END           0xcfffffff
#define RDR_MODEM_CP_CPHY_MOD_ID_START          0xd0000000
#define RDR_MODEM_CP_CPHY_MOD_ID_END            0xdfffffff
#define RDR_MODEM_CP_IMS_MOD_ID_START           0xe0000000
#define RDR_MODEM_CP_IMS_MOD_ID_END             0xefffffff




/* rdrΪCP�����ID��ΧΪ0x82000000~0x82ffffff��������rdr_pub.h��*/
#define RDR_MODEM_AP_MOD_ID                     0x82000000  /* AP�쳣������log��������λ��phone��mbb���� */
#define RDR_MODEM_CP_MOD_ID                     0x82000001  /* CP�쳣������log��phone��mbb���� */
#define RDR_MODEM_CP_WDT_MOD_ID                 0x82000003  /* CP���Ź��쳣������log��phone��mbb���� */
#define RDR_MODEM_CP_RESET_SIM_SWITCH_MOD_ID    0x82000005  /* �п������CP������λ��������log��phone���� */
#define RDR_MODEM_CP_RESET_FAIL_MOD_ID          0x82000006  /* CP������λʧ�ܣ�����log��phone���� */
#define RDR_MODEM_CP_RESET_RILD_MOD_ID          0x82000007  /* RILD�����CP������λ������log��phone����*/
#define RDR_MODEM_CP_RESET_3RD_MOD_ID           0x82000008  /* 3rd modem�����CP������λ������log��phone����*/
#define RDR_MODEM_CP_RESET_REBOOT_REQ_MOD_ID    0x82000009  /* CP������λΪ׮ʱ��������λ������log��phone����*/
#define RDR_MODEM_CP_RESET_USER_RESET_MOD_ID    0x82000010  /* CP������λ,�û����𣬲�����log,PHONE ����*/
#define RDR_MODEM_CP_RESET_DLOCK_MOD_ID         0x82000011  /* modem���߹���*/
#define RDR_MODEM_CP_NOC_MOD_ID                 0x82000012  /* modem�ڲ�����noc */
#define RDR_MODEM_AP_NOC_MOD_ID                 0x82000013  /* modem����AP����noc */
#define RDR_MODEM_CP_RESET_FREQUENTLY_MOD_ID    0x82000014  /* c ��Ƶ��������λ����������*/

#define RDR_MODEM_NOC_MOD_ID                    0x82000030  /* NOC�쳣, ����log��phone����, */
                                                            /* ���Ҫ�޸��߶���һ��Ҫ֪��AP��ͬ���޸ģ�����ᵼ��NOC�쳣log�洢������ */
#define RDR_MODEM_DMSS_MOD_ID                   0x82000031  /* DMSS�쳣, ����log��phone����, */
                                                            /* ���Ҫ�޸��߶���һ��Ҫ֪��AP��ͬ���޸ģ�����ᵼ��DMSS�쳣log�洢������ */


#define RDR_MODEM_CP_DRV_MOD_ID                 0x82000041
#define RDR_MODEM_CP_OSA_MOD_ID                 0x82000042
#define RDR_MODEM_CP_OAM_MOD_ID                 0x82000043
#define RDR_MODEM_CP_GUL2_MOD_ID                0x82000044
#define RDR_MODEM_CP_CTTF_MOD_ID                0x82000045
#define RDR_MODEM_CP_GUWAS_MOD_ID               0x82000046
#define RDR_MODEM_CP_CAS_MOD_ID                 0x82000047
#define RDR_MODEM_CP_CPROC_MOD_ID               0x82000048
#define RDR_MODEM_CP_GUGAS_MOD_ID               0x82000049
#define RDR_MODEM_CP_GUCNAS_MOD_ID              0x8200004a
#define RDR_MODEM_CP_GUDSP_MOD_ID               0x8200004b
#define RDR_MODEM_CP_LPS_MOD_ID                 0x8200004c
#define RDR_MODEM_CP_LMSP_MOD_ID                0x8200004d
#define RDR_MODEM_CP_TLDSP_MOD_ID               0x8200004e
#define RDR_MODEM_CP_CPHY_MOD_ID                0x8200004f
#define RDR_MODEM_CP_IMS_MOD_ID                 0x82000050
#define RDR_MODEM_AP_DRV_MOD_ID                 0x82000051
#define RDR_MODEM_CP_EASYRF_MOD_ID              0x82000060


#define RDR_MODEM_CODE_PATCH_REVERT_MOD_ID      0x82000100
#define RDR_MODEM_DRV_BUTT_MOD_ID               0x82ffffff


#define RDR_DUMP_FILE_PATH_LEN                128
#define RDR_DUMP_FILE_CP_PATH                 "cp_log/"
#define RDR_MODEM_CP_RESET_TIMEOUT            (30000)


#define RDR_MODEM_NR_MOD_ID_START          0xb0000000
#define RDR_MODEM_NR_MOD_ID_END            0xbfffffff



#define NRRDR_MODEM_NR_CCPU_START               (0xB1000000)
#define NRRDR_MODEM_NR_CCPU_END                 (0xB1FFFFFF)
#define NRRDR_MODEM_NR_L2HAC_START              (0xB2000000)
#define NRRDR_MODEM_NR_L2HAC_END                (0xB2FFFFFF)
#define NRRDR_MODEM_NR_HL1C_START               (0xB3000000)
#define NRRDR_MODEM_NR_HL1C_END                 (0xB3FFFFFF)
#define NRRDR_EXC_CCPU_DRV_MOD_ID           (NRRDR_MODEM_NR_CCPU_START)
#define NRRDR_EXC_CCPU_OSA_MOD_ID           (0xB1100000)
#define NRRDR_EXC_CCPU_OAM_MOD_ID           (0xB1200000)
#define NRRDR_EXC_CCPU_GUL2_MOD_ID          (0xB1300000)
#define NRRDR_EXC_CCPU_CTTF_MOD_ID          (0xB1400000)
#define NRRDR_EXC_CCPU_GUWAS_MOD_ID         (0xB1500000)
#define NRRDR_EXC_CCPU_CAS_MOD_ID           (0xB1600000)
#define NRRDR_EXC_CCPU_CPROC_MOD_ID         (0xB1700000)
#define NRRDR_EXC_CCPU_GUGAS_MOD_ID         (0xB1800000)
#define NRRDR_EXC_CCPU_NRNAS_MOD_ID         (0xB1900000)
#define NRRDR_EXC_CCPU_NRPHY_MOD_ID         (0xB1a00000)
#define NRRDR_EXC_CCPU_NRPS_MOD_ID           (0xB1b00000)
#define NRRDR_EXC_CCPU_NRDSP_MOD_ID         (0xB1d00000)
#define NRRDR_EXC_CCPU_IMS_MOD_ID           (0xB1f00000)
#define NRRDR_EXC_CCPU_END_ID               (NRRDR_MODEM_NR_CCPU_END)


#define RDR_MODEM_REVERSE_MOD_ID_START          0xF0000000
#define RDR_MODEM_REVERSE_MOD_ID_END            0xffffffff

#define WAIT_EXCEPTION_HANDLE_TIME     (45*1000*1000UL)  /*����log�͵�����λһ����ʱ��Ŀǰ�趨Ϊ45s*/

#define NRCCPU_EXCEPTION      ("NRCCPU EXCEPTION")
#define NRL2HAC_EXCEPTION     ("NRL2HAC EXCEPTION")

typedef struct
{
    u32     modid;
    u32     product_type;
    u64     coreid;
    char    log_path[RDR_DUMP_FILE_PATH_LEN];
    pfn_cb_dump_done    dump_done;
}rdr_exc_info_s;

typedef enum
{
    EXC_INFO_NORMAL = 0,
    EXC_INFO_NOC,
    EXC_INFO_DMSS,
    EXC_INFO_BUTT,
}EXC_INFO_INDEX;

typedef struct modid
{
    u32 mdm_id_start;
    u32 mdm_id_end;
    u32 rdr_id;
}DUMP_MOD_ID;


rdr_exc_info_s* dump_get_rdr_exc_info_by_modid(u32 modid);
u32 dump_match_rdr_mod_id(dump_exception_info_s* dump_exception_info);
s32 dump_register_modem_exc_info(void);
struct rdr_exception_info_s* dump_get_exception_info_node(u32 mod_id);
void dump_fill_excption_info(dump_exception_info_s* exception_info_s,
                                 u32 mod_id,u32 arg1,u32 arg2,char* data, u32 length,u32 core,
                                 u32 reason,char* desc,dump_reboot_ctx_t contex,
                                 u32 task_id,u32 int_no,u8* task_name);

void dump_get_nr_excinfo(u32 modid,void* exc_sub_type, void* desc);
dump_exception_info_s* dump_get_current_excpiton_info(u32 modid);
s32 dump_register_exception(dump_exception_info_s* exception_info);
s32 dump_exception_handler_init(void);
void dump_excption_handle_done(u32 modid);
u32 dump_get_exc_index(u32 modid);
rdr_exc_info_s* dump_get_rdr_exc_info_by_index(u32 index);



#endif