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
#ifndef _AT_MNTN_H_
#define _AT_MNTN_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"
#include "TafTypeDef.h"
#include "mdrv.h"
#include "AtInternalMsg.h"
#include "AtPrivate.h"
#include "MnClient.h"
#include "msp_diag_comm.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)


/*****************************************************************************
  2 宏定义
*****************************************************************************/

/* Log Print Module Define */
#ifndef THIS_MODU
#define THIS_MODU    ps_nas
#endif

/* 1.1: OM_GreenChannel的第二个参数usPrimId的定义*/
#define     AT_OM_GREEN_CHANNEL_PS      (0xC001)                                /* PS相关 */

/* 封装可维可测事件消息头 */
#define AT_MNTN_CFG_MSG_HDR(pstMsg, enEventId, ulEventLen)\
            (pstMsg)->ulSenderCpuId   = VOS_LOCAL_CPUID;\
            (pstMsg)->ulSenderPid     = WUEPS_PID_AT;\
            (pstMsg)->ulReceiverCpuId = VOS_LOCAL_CPUID;\
            (pstMsg)->ulReceiverPid   = WUEPS_PID_AT;\
            (pstMsg)->ulLength        = (ulEventLen);\
            (pstMsg)->enMsgId         = (enEventId)


/* C核单独复位统计信息 */
#define AT_DBG_SET_SEM_INIT_FLAG(flag)              (g_stAtStatsInfo.stCCpuResetStatsInfo.ulSemInitFlg = (flag))
#define AT_DBG_SAVE_BINARY_SEM_ID(sem_id)           (g_stAtStatsInfo.stCCpuResetStatsInfo.hBinarySemId = (sem_id))
#define AT_DBG_CREATE_BINARY_SEM_FAIL_NUM(n)        (g_stAtStatsInfo.stCCpuResetStatsInfo.ulCreateBinarySemFailNum += (n))
#define AT_DBG_LOCK_BINARY_SEM_FAIL_NUM(n)          (g_stAtStatsInfo.stCCpuResetStatsInfo.ulLockBinarySemFailNum += (n))
#define AT_DBG_SAVE_LAST_BIN_SEM_ERR_RSLT(rslt)     (g_stAtStatsInfo.stCCpuResetStatsInfo.ulLastBinarySemErrRslt = (rslt))
#define AT_DBG_SAVE_CCPU_RESET_BEFORE_NUM(n)        (g_stAtStatsInfo.stCCpuResetStatsInfo.ulResetBeforeNum += (n))
#define AT_DBG_SAVE_CCPU_RESET_AFTER_NUM(n)         (g_stAtStatsInfo.stCCpuResetStatsInfo.ulResetAfterNum += (n))
#define AT_DBG_SAVE_HIFI_RESET_NUM(n)               (g_stAtStatsInfo.stCCpuResetStatsInfo.ulHifiResetNum += (n))

/* MODEM上行统计信息 */
#define AT_MODEM_DBG_UL_DATA_READ_CB_NUM(n)         (g_stAtStatsInfo.stModemStats.ulUlDataReadCBNum += (n))
#define AT_MODEM_DBG_UL_GET_RD_FAIL_NUM(n)          (g_stAtStatsInfo.stModemStats.ulUlGetRDFailNum += (n))
#define AT_MODEM_DBG_UL_GET_RD_SUCC_NUM(n)          (g_stAtStatsInfo.stModemStats.ulUlGetRDSuccNum += (n))
#define AT_MODEM_DBG_UL_INVALID_RD_NUM(n)           (g_stAtStatsInfo.stModemStats.ulUlInvalidRDNum += (n))
#define AT_MODEM_DBG_UL_RETURN_BUFF_SUCC_NUM(n)     (g_stAtStatsInfo.stModemStats.ulUlReturnBuffSuccNum += (n))
#define AT_MODEM_DBG_UL_RETURN_BUFF_FAIL_NUM(n)     (g_stAtStatsInfo.stModemStats.ulUlReturnBuffFailNum += (n))

/* MODEM下行数据统计信息 */
#define AT_MODEM_DBG_DL_WRITE_ASYNC_SUCC_NUM(n)     (g_stAtStatsInfo.stModemStats.ulDlWriteAsyncSuccNum += (n))
#define AT_MODEM_DBG_DL_WRITE_ASYNC_FAIL_NUM(n)     (g_stAtStatsInfo.stModemStats.ulDlWriteAsyncFailNum += (n))
#define AT_MODEM_DBG_DL_FREE_BUFF_NUM(n)            (g_stAtStatsInfo.stModemStats.ulDlFreeBuffNum += (n))

/* HSUART NV读写统计信息 */
#define AT_HSUART_DBG_NV_READ_ERR(n)                (g_stAtStatsInfo.stHsUartStats.ucReadNvFailNum += (n))
#define AT_HSUART_DBG_NV_WRITE_ERR(n)               (g_stAtStatsInfo.stHsUartStats.ucWriteNvFailNum += (n))
#define AT_HSUART_DBG_NV_BAUDRATE_ERR(n)            (g_stAtStatsInfo.stHsUartStats.ucBaudRateERR += (n))
#define AT_HSUART_DBG_NV_FORMAT_ERR(n)              (g_stAtStatsInfo.stHsUartStats.ucFormatERR += (n))

/* HSUART IOCTL统计信息 */
#define AT_HSUART_DBG_IOCTL_SET_READ_CB_ERR(n)      (g_stAtStatsInfo.stHsUartStats.ucSetReadCbERR += (n))
#define AT_HSUART_DBG_IOCTL_RELLOC_READ_BUFF_ERR(n) (g_stAtStatsInfo.stHsUartStats.ucRellocReadBuffERR += (n))
#define AT_HSUART_DBG_IOCTL_SET_FREE_CB_ERR(n)      (g_stAtStatsInfo.stHsUartStats.ucSetFreeBuffCbERR += (n))
#define AT_HSUART_DBG_IOCTL_SET_MSC_READ_CB_ERR(n)  (g_stAtStatsInfo.stHsUartStats.ucSetMscReadCbERR += (n))
#define AT_HSUART_DBG_IOCTL_SET_SWITCH_CB_ERR(n)    (g_stAtStatsInfo.stHsUartStats.ucSetSwitchCmdCbERR += (n))
#define AT_HSUART_DBG_IOCTL_SET_WATER_CB_ERR(n)     (g_stAtStatsInfo.stHsUartStats.ucSetWaterCbERR += (n))
#define AT_HSUART_DBG_IOCTL_SET_BAUD_FAIL_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulSetBaudRateFailNum += (n))
#define AT_HSUART_DBG_IOCTL_SET_WLEN_FAIL_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulSetWlenFailNum += (n))
#define AT_HSUART_DBG_IOCTL_SET_STP_FAIL_NUM(n)     (g_stAtStatsInfo.stHsUartStats.ulSetStpFailNum += (n))
#define AT_HSUART_DBG_IOCTL_SET_PARITY_FAIL_NUM(n)  (g_stAtStatsInfo.stHsUartStats.ulSetParityFailNum += (n))
#define AT_HSUART_DBG_IOCTL_MSC_READ_CB_NUM(n)      (g_stAtStatsInfo.stHsUartStats.ulMscReadCBNum += (n))
#define AT_HSUART_DBG_IOCTL_MSC_WRITE_SUCC_NUM(n)   (g_stAtStatsInfo.stHsUartStats.ulMscWriteSuccNum += (n))
#define AT_HSUART_DBG_IOCTL_MSC_WRITE_FAIL_NUM(n)   (g_stAtStatsInfo.stHsUartStats.ulMscWriteFailNum += (n))
#define AT_HSUART_DBG_IOCTL_SWITCH_CB_NUM(n)        (g_stAtStatsInfo.stHsUartStats.ulSwitchCmdCBNum += (n))
#define AT_HSUART_DBG_IOCTL_CFG_FC_SUCC_NUM(n)      (g_stAtStatsInfo.stHsUartStats.ulCfgFlowCtrlSuccNum += (n))
#define AT_HSUART_DBG_IOCTL_CFG_FC_FAIL_NUM(n)      (g_stAtStatsInfo.stHsUartStats.ulCfgFlowCtrlFailNum += (n))
#define AT_HSUART_DBG_IOCTL_CLEAR_BUFF_SUCC_NUM(n)  (g_stAtStatsInfo.stHsUartStats.ulClearBuffSuccNum += (n))
#define AT_HSUART_DBG_IOCTL_CLEAR_BUFF_FAIL_NUM(n)  (g_stAtStatsInfo.stHsUartStats.ulClearBuffFailNum += (n))

/* HSUART上行数据统计信息 */
#define AT_HSUART_DBG_UL_DATA_READ_CB_NUM(n)        (g_stAtStatsInfo.stHsUartStats.ulUlDataReadCBNum += (n))
#define AT_HSUART_DBG_UL_GET_RD_SUCC_NUM(n)         (g_stAtStatsInfo.stHsUartStats.ulUlGetRDSuccNum += (n))
#define AT_HSUART_DBG_UL_GET_RD_FAIL_NUM(n)         (g_stAtStatsInfo.stHsUartStats.ulUlGetRDFailNum += (n))
#define AT_HSUART_DBG_UL_INVALID_RD_NUM(n)          (g_stAtStatsInfo.stHsUartStats.ulUlInvalidRDNum += (n))
#define AT_HSUART_DBG_UL_INVALID_CMD_DATA_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulUlRcvInvalidCmdNum += (n))
#define AT_HSUART_DBG_UL_VALID_CMD_DATA_NUM(n)      (g_stAtStatsInfo.stHsUartStats.ulUlValidCmdNum += (n))
#define AT_HSUART_DBG_UL_PPP_DATA_NUM(n)            (g_stAtStatsInfo.stHsUartStats.ulUlPppDataNum += (n))
#define AT_HSUART_DBG_UL_IP_DATA_NUM(n)             (g_stAtStatsInfo.stHsUartStats.ulUlIpDataNum += (n))
#define AT_HSUART_DBG_UL_OM_DATA_NUM(n)             (g_stAtStatsInfo.stHsUartStats.ulUlOmDataNum += (n))
#define AT_HSUART_DBG_UL_DIAG_DATA_NUM(n)           (g_stAtStatsInfo.stHsUartStats.ulUlDiagDataNum += (n))
#define AT_HSUART_DBG_UL_INVALID_DATA_NUM(n)        (g_stAtStatsInfo.stHsUartStats.ulUlInvalidModeDataNum += (n))
#define AT_HSUART_DBG_UL_RETURN_BUFF_SUCC_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulUlReturnBuffSuccNum += (n))
#define AT_HSUART_DBG_UL_RETURN_BUFF_FAIL_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulUlReturnBuffFailNum += (n))

/* HSUART下行数据统计信息 */
#define AT_HSUART_DBG_DL_WRITE_ASYNC_SUCC_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulDlWriteAsyncSuccNum += (n))
#define AT_HSUART_DBG_DL_WRITE_ASYNC_FAIL_NUM(n)    (g_stAtStatsInfo.stHsUartStats.ulDlWriteAsyncFailNum += (n))
#define AT_HSUART_DBG_DL_WRITE_SYNC_SUCC_NUM(n)     (g_stAtStatsInfo.stHsUartStats.ulDlWriteSyncSuccNum += (n))
#define AT_HSUART_DBG_DL_WRITE_SYNC_FAIL_NUM(n)     (g_stAtStatsInfo.stHsUartStats.ulDlWriteSyncFailNum += (n))
#define AT_HSUART_DBG_DL_WRITE_SYNC_SUCC_LEN(n)     (g_stAtStatsInfo.stHsUartStats.ulDlWriteSyncSuccLen += (n))
#define AT_HSUART_DBG_DL_WRITE_SYNC_FAIL_LEN(n)     (g_stAtStatsInfo.stHsUartStats.ulDlWriteSyncFailLen += (n))
#define AT_HSUART_DBG_DL_FREE_BUFF_NUM(n)           (g_stAtStatsInfo.stHsUartStats.ulDlFreeBuffNum += (n))

/* AT记录Msg的最大个数 */
#define AT_MNTN_MSG_RECORD_MAX_NUM                  (100)


#ifndef TAF_LOG
#define   TAF_LOG(Mod, SubMod, Level, String) \
          (VOS_VOID)DIAG_LogReport( DIAG_GEN_LOG_MODULE(MODEM_ID_0, DIAG_MODE_UMTS, (Level)), \
                          (Mod), NULL, __LINE__, "%s \r\n", (String) )

#define   TAF_LOG1(Mod, SubMod, Level, String, Para1) \
          (VOS_VOID)DIAG_LogReport( DIAG_GEN_LOG_MODULE(MODEM_ID_0, DIAG_MODE_UMTS, (Level)), \
                          (Mod), NULL, __LINE__, "%s, %d \r\n", (String), (VOS_INT32)(Para1) )

#define   TAF_LOG2(Mod, SubMod, Level, String, Para1, Para2) \
          (VOS_VOID)DIAG_LogReport( DIAG_GEN_LOG_MODULE(MODEM_ID_0, DIAG_MODE_UMTS, (Level)), \
                          (Mod), NULL, __LINE__, "%s, %d, %d \r\n", (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2) )

#define   TAF_LOG3(Mod, SubMod, Level, String, Para1, Para2, Para3) \
          (VOS_VOID)DIAG_LogReport( DIAG_GEN_LOG_MODULE(MODEM_ID_0, DIAG_MODE_UMTS, (Level)), \
                          (Mod), NULL, __LINE__, "%s, %d, %d, %d \r\n", (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3) )

#define   TAF_LOG4(Mod, SubMod, Level, String, Para1, Para2, Para3, Para4) \
          (VOS_VOID)DIAG_LogReport( DIAG_GEN_LOG_MODULE(MODEM_ID_0, DIAG_MODE_UMTS, (Level)), \
                          (Mod), NULL, __LINE__, "%s, %d, %d, %d, %d \r\n", (String), (VOS_INT32)(Para1), (VOS_INT32)(Para2), (VOS_INT32)(Para3), (VOS_INT32)(Para4) )
#endif


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
 结构名称: AT_FC_DEVICE_TYPE_ENUM
 结构说明: 流控设备类型
*****************************************************************************/
enum AT_FC_DEVICE_TYPE_ENUM
{
    AT_FC_DEVICE_TYPE_MODEM             = 0x00,             /* MODEM */
    AT_FC_DEVICE_TYPE_NCM               = 0x01,             /* NCM */
    AT_FC_DEVICE_TYPE_RMNET             = 0x02,             /* RMNET */
    AT_FC_DEVICE_TYPE_HSUART            = 0x03,             /* HSUART */

    AT_FC_DEVICE_TYPE_BUTT
};
typedef VOS_UINT32 AT_FC_DEVICE_TYPE_ENUM_UINT32;

/*****************************************************************************
 结构名称: AT_FC_POINT_TYPE_ENUM
 结构说明: 流控点类型
*****************************************************************************/
enum AT_FC_POINT_TYPE_ENUM
{
    AT_FC_POINT_TYPE_MODEM_PS           = 0x00,             /* MODEM PS */
    AT_FC_POINT_TYPE_MODEM_VP           = 0x01,             /* MODEM VP */
    AT_FC_POINT_TYPE_NDIS               = 0x02,             /* NCM */
    AT_FC_POINT_TYPE_RMNET              = 0x03,             /* RMNET */
    AT_FC_POINT_TYPE_HSIC               = 0x04,             /* HSIC */

    AT_FC_POINT_TYPE_BUTT
};
typedef VOS_UINT32 AT_FC_POINT_TYPE_ENUM_UINT32;


enum AT_OM_GREENCHANNEL_ERR_ENUM
{
    AT_OM_GREENCHANNEL_PS_CID_NOT_DEFINE = 0,
    AT_OM_GREENCHANNEL_PS_CREATE_PPP_REQ_ERR,
    AT_OM_GREENCHANNEL_PS_CREATE_RAW_DATA_PPP_REQ_ERR,
    AT_OM_GREENCHANNEL_PS_IP_TYPE_DIAL_FAIL,
    AT_OM_GREENCHANNEL_PS_PPP_TYPE_DIAL_FAIL,
    AT_OM_GREENCHANNEL_PS_DEACTIVE_PDP_ERR_EVT,
    AT_OM_GREENCHANNEL_PS_ACTIVE_PDP_REJ,
    AT_OM_GREENCHANNEL_PS_MODIFY_PDP_REJ,
    AT_OM_GREENCHANNEL_PS_NET_ORIG_DEACTIVE_IND,

    AT_OM_GREENCHANNEL_ERR_BUTT
};
typedef VOS_UINT32 AT_OM_GREENCHANNEL_ERR_ENUM_UINT32;


/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/


/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/




typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    AT_INTER_MSG_ID_ENUM_UINT32         enMsgId;            /* 消息类型     */  /* _H2ASN_Skip */
    VOS_UINT32                          ulPortId;           /* 端口ID */
    AT_FC_DEVICE_TYPE_ENUM_UINT32       enDevice;

} AT_MNTN_FLOW_CTRL_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    AT_INTER_MSG_ID_ENUM_UINT32         enMsgId;            /* 消息类型     */  /* _H2ASN_Skip */
    VOS_UINT32                          ulPortId;           /* 端口ID */
    AT_FC_POINT_TYPE_ENUM_UINT32        enPoint;

} AT_MNTN_FC_POINT_STRU;


typedef struct
{
    AT_CLIENT_TAB_INDEX_UINT8           enAtClientTabIndex;
    VOS_UINT8                           ucReportFlg;                            /* 该端口是否允许主动上报，VOS_TRUE为允许，VOS_FALSE为不允许，默认允许 */
    MODEM_ID_ENUM_UINT16                enModemId;                              /* 该端口属于哪个modem */
} AT_RPT_PORT_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    AT_INTER_MSG_ID_ENUM_UINT32         enMsgId;
    AT_RPT_PORT_STRU                    astAtRptPort[AT_MAX_CLIENT_NUM];
} AT_MNTN_RPTPORT_STRU;


typedef struct
{
    /* 上行统计信息 */
    VOS_UINT32                          ulUlDataReadCBNum;
    VOS_UINT32                          ulUlGetRDSuccNum;
    VOS_UINT32                          ulUlGetRDFailNum;
    VOS_UINT32                          ulUlInvalidRDNum;
    VOS_UINT32                          ulUlReturnBuffSuccNum;
    VOS_UINT32                          ulUlReturnBuffFailNum;

    /* 下行统计信息 */
    VOS_UINT32                          ulDlWriteAsyncSuccNum;
    VOS_UINT32                          ulDlWriteAsyncFailNum;
    VOS_UINT32                          ulDlFreeBuffNum;
    VOS_UINT32                          ulReserved;
} AT_MNTN_MODEM_STATS_STRU;


typedef struct
{
    /* NV读取统计信息 */
    VOS_UINT8                           ucReadNvFailNum;
    VOS_UINT8                           ucWriteNvFailNum;
    VOS_UINT8                           ucBaudRateERR;
    VOS_UINT8                           ucFormatERR;

    /* IOCTRL统计信息 */
    VOS_UINT8                           ucSetReadCbERR;
    VOS_UINT8                           ucRellocReadBuffERR;
    VOS_UINT8                           ucSetFreeBuffCbERR;
    VOS_UINT8                           ucSetMscReadCbERR;
    VOS_UINT8                           ucSetSwitchCmdCbERR;
    VOS_UINT8                           ucSetWaterCbERR;
    VOS_UINT8                           aucReserved1[2];
    VOS_UINT8                           ulSetBaudRateFailNum;
    VOS_UINT8                           ulSetWlenFailNum;
    VOS_UINT8                           ulSetStpFailNum;
    VOS_UINT8                           ulSetParityFailNum;
    VOS_UINT8                           aucReserved2[4];
    VOS_UINT32                          ulMscReadCBNum;
    VOS_UINT32                          ulMscWriteSuccNum;
    VOS_UINT32                          ulMscWriteFailNum;
    VOS_UINT32                          ulSwitchCmdCBNum;
    VOS_UINT32                          ulCfgFlowCtrlSuccNum;
    VOS_UINT32                          ulCfgFlowCtrlFailNum;
    VOS_UINT32                          ulClearBuffSuccNum;
    VOS_UINT32                          ulClearBuffFailNum;

    /* 上行统计信息 */
    VOS_UINT32                          ulUlDataReadCBNum;
    VOS_UINT32                          ulUlGetRDSuccNum;
    VOS_UINT32                          ulUlGetRDFailNum;
    VOS_UINT32                          ulUlInvalidRDNum;
    VOS_UINT32                          ulUlRcvInvalidCmdNum;
    VOS_UINT32                          ulUlValidCmdNum;
    VOS_UINT32                          ulUlIpDataNum;
    VOS_UINT32                          ulUlPppDataNum;
    VOS_UINT32                          ulUlRcvCsdDataNum;
    VOS_UINT32                          ulUlOmDataNum;
    VOS_UINT32                          ulUlDiagDataNum;
    VOS_UINT32                          ulUlInvalidModeDataNum;
    VOS_UINT32                          ulUlReturnBuffSuccNum;
    VOS_UINT32                          ulUlReturnBuffFailNum;

    /* 下行统计信息 */
    VOS_UINT32                          ulDlWriteAsyncSuccNum;
    VOS_UINT32                          ulDlWriteAsyncFailNum;
    VOS_UINT32                          ulDlWriteSyncSuccNum;
    VOS_UINT32                          ulDlWriteSyncFailNum;
    VOS_UINT32                          ulDlWriteSyncSuccLen;
    VOS_UINT32                          ulDlWriteSyncFailLen;
    VOS_UINT32                          ulDlFreeBuffNum;

} AT_MNTN_HSUART_STATS_STRU;


typedef struct
{
    VOS_UINT8                           ucPcuiCtrlConcurrentFlg;                /* PCUI和CTRL口并发标志 */
    VOS_UINT8                           ucPcuiPsCallFlg;                        /* PCUI口模拟NDISDUP拨号标志 */
    VOS_UINT8                           ucPcuiUserId;                           /* PCUI口模拟哪个端口拨号 */
    VOS_UINT8                           ucCtrlPsCallFlg;                        /* CTRL口模拟NDISDUP拨号标志 */
    VOS_UINT8                           ucCtrlUserId;                           /* CTRL口模拟哪个端口拨号 */
    VOS_UINT8                           ucPcui2PsCallFlg;                       /* PCUI2口模拟NDISDUP拨号标志 */
    VOS_UINT8                           ucPcui2UserId;                          /* PCUI2口模拟哪个端口拨号 */
    VOS_UINT8                           ucUnCheckApPortFlg;
}AT_DEBUG_INFO_STRU;


typedef struct
{
    /* 复位信号量信息 */
    VOS_SEM                 hBinarySemId;                                       /* 二进制信号量ID */
    VOS_UINT32              ulSemInitFlg;                                       /* 初始化标识, VOS_TRUE: 成功; VOS_FALSE: 失败 */
    VOS_UINT32              ulCreateBinarySemFailNum;                           /* 创建二进制信号量失败次数 */
    VOS_UINT32              ulLockBinarySemFailNum;                             /* 锁二进制信号量失败次数 */
    VOS_UINT32              ulLastBinarySemErrRslt;                             /* 最后一次锁二进制信号量失败结果 */
    VOS_UINT32              ulResetBeforeNum;                                   /* C核复位前的次数 */
    VOS_UINT32              ulResetAfterNum;                                    /* C核复位后的次数 */
    VOS_UINT32              ulHifiResetNum;                                     /* HIFI复位的次数 */
    VOS_UINT32              ulReserved;
}AT_RESET_STATS_INFO_STRU;

/*****************************************************************************
 结构名    : AT_MNTN_STATS_STRU
 结构说明  : 记录AT模块的可维可测信息
*****************************************************************************/
typedef struct
{
    AT_RESET_STATS_INFO_STRU            stCCpuResetStatsInfo;
    AT_MNTN_MODEM_STATS_STRU            stModemStats;
    AT_MNTN_HSUART_STATS_STRU           stHsUartStats;

} AT_MNTN_STATS_STRU;


typedef struct
{
    VOS_UINT32                          ulSendPid;
    VOS_UINT32                          ulMsgName;
    VOS_UINT32                          ulSliceStart;
    VOS_UINT32                          ulSliceEnd;
} AT_MNTN_MSG_RECORD_STRU;


typedef struct
{
    AT_MNTN_MSG_RECORD_STRU             astAtMntnMsgRecord[AT_MNTN_MSG_RECORD_MAX_NUM];
    VOS_UINT32                          ulCurrentIndex;
} AT_MNTN_MSG_RECORD_INFO_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    AT_INTER_MSG_ID_ENUM_UINT32         enMsgId;

    VOS_UINT32                          ulUsedFlg;          /* 呼叫实体分配标志 */
    VOS_UINT8                           ucCurrPdpType;      /* 当前呼叫类型 */
    VOS_UINT8                           ucPortIndex;
    VOS_UINT8                           ucUserIndex;
    VOS_UINT8                           ucUsrType;
    VOS_UINT8                           ucUsrCid;
    VOS_UINT8                           ucUserPdpType;
    VOS_UINT8                           ucPdpTypeValidFlag;
    VOS_UINT8                           ucAPNLen;
    VOS_UINT16                          usUsernameLen;
    VOS_UINT16                          usPasswordLen;
    VOS_UINT16                          usAuthType;
    VOS_UINT8                           aucRsv1[2];
    VOS_UINT32                          ulIPv4ValidFlag;

    VOS_UINT8                           ucIpv4Cid;          /* IPv4 CID */
    VOS_UINT8                           ucIpv4State;        /* IPv4 状态 */
    VOS_UINT8                           ucIpv4DendRptFlg;   /* IPV4 DEND是否已经上报过 */
    VOS_UINT8                           aucRsv2[1];         /* 保留位 */

    VOS_UINT8                           ucIpv6Cid;          /* IPv6 CID */
    VOS_UINT8                           ucIpv6State;        /* IPv6 状态 */
    VOS_UINT8                           ucIpv6DendRptFlg;   /* IPV6 DEND是否已经上报过 */
    VOS_UINT8                           aucRsv3[1];         /* 保留位 */

} AT_MNTN_PS_CALL_ENTITY_STRU;

/*****************************************************************************
  7 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    AT_INTER_MSG_ID_ENUM_UINT32         enMsgId;                                /* _H2ASN_MsgChoice_Export AT_INTER_MSG_ID_ENUM_UINT32 */
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          AT_INTER_MSG_ID_ENUM_UINT32
    ****************************************************************************/
} AT_MNTN_MSG_DATA;
/* _H2ASN_Length UINT32 */

typedef struct
{
    VOS_MSG_HEADER
    AT_MNTN_MSG_DATA                    stMsgData;
} AtMntn_MSG;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 全局变量声明
*****************************************************************************/
extern AT_MNTN_STATS_STRU               g_stAtStatsInfo;
extern AT_DEBUG_INFO_STRU               g_stAtDebugInfo;


/*****************************************************************************
  10 函数声明
*****************************************************************************/

VOS_UINT8 AT_GetPcuiCtrlConcurrentFlag(VOS_VOID);
VOS_UINT8 AT_GetPcuiPsCallFlag(VOS_VOID);

VOS_UINT8 AT_GetPcuiUsertId(VOS_VOID);
VOS_UINT8 AT_GetCtrlPsCallFlag(VOS_VOID);
VOS_UINT8 AT_GetCtrlUserId(VOS_VOID);
VOS_UINT8 AT_GetPcui2PsCallFlag(VOS_VOID);
VOS_UINT8 AT_GetPcui2UserId(VOS_VOID);
VOS_VOID AT_MNTN_TraceRPTPORT(VOS_VOID);
VOS_VOID AT_SetUnCheckApPortFlg(
    VOS_UINT8                           ucFlag
);
VOS_UINT8 AT_GetUnCheckApPortFlg(VOS_VOID);


VOS_VOID AT_MNTN_TraceEvent(VOS_VOID *pMsg);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceStartFlowCtrl
 功能描述  : 启动流控可维可测
 输入参数  : ucIndex    - 端口索引
             enFcDevive - 流控设备
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceStartFlowCtrl(
    VOS_UINT8                           ucIndex,
    AT_FC_DEVICE_TYPE_ENUM_UINT32       enFcDevive
);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceStopFlowCtrl
 功能描述  : 停止流控可维可测
 输入参数  : ucIndex    - 端口索引
             enFcDevive - 流控设备
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceStopFlowCtrl(
    VOS_UINT8                           ucIndex,
    AT_FC_DEVICE_TYPE_ENUM_UINT32       enFcDevive
);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceRegFcPoint
 功能描述  : 注册流控点可维可测
 输入参数  : ucIndex   - 端口索引
             enFcPoint - 流控点
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceRegFcPoint(
    VOS_UINT8                           ucIndex,
    AT_FC_POINT_TYPE_ENUM_UINT32        enFcPoint
);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceDeregFcPoint
 功能描述  : 去注册流控点可维可测
 输入参数  : ucIndex   - 端口索引
             enFcPoint - 流控点
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceDeregFcPoint(
    VOS_UINT8                           ucIndex,
    AT_FC_POINT_TYPE_ENUM_UINT32        enFcPoint
);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceCmdResult
 功能描述  : AT命令回复可维可测
 输入参数  : ucIndex   - 端口索引
             pucData   - 数据内容
             usDataLen - 数据长度
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceCmdResult(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usDataLen
);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceContextData
 功能描述  : 把AT外部上下文作为SDT消息发送出去，以便在回放时通过桩函数还原
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceContextData(VOS_VOID);


/*****************************************************************************
 函 数 名  : AT_MNTN_TraceClientData
 功能描述  : 发送AT模块的客户端口数据
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_MNTN_TraceClientData(VOS_VOID);


/*****************************************************************************
 函 数 名  : AT_InitHsUartStats
 功能描述  : 初始化UART可维可测信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_InitHsUartStats(VOS_VOID);


/*****************************************************************************
 函 数 名  : AT_MODEM_Help
 功能描述  : 初始化UART可维可测信息
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
*****************************************************************************/
VOS_VOID AT_InitModemStats(VOS_VOID);

VOS_VOID AT_SetPcuiCtrlConcurrentFlag(VOS_UINT8 ucFlag);

VOS_VOID AT_ShowClientCtxInfo(VOS_VOID);

VOS_VOID AT_RecordAtMsgInfo(
    VOS_UINT32                          ulSendPid,
    VOS_UINT32                          ulMsgName,
    VOS_UINT32                          ulSliceStart,
    VOS_UINT32                          ulSliceEnd
);

VOS_VOID AT_InitMntnCtx(VOS_VOID);

VOS_VOID AT_SetPcuiPsCallFlag(
    VOS_UINT8                           ucFlag,
    VOS_UINT8                           ucIndex
);
VOS_VOID AT_SetCtrlPsCallFlag(
    VOS_UINT8                           ucFlag,
    VOS_UINT8                           ucIndex
);
VOS_VOID AT_SetPcui2PsCallFlag(
    VOS_UINT8                           ucFlag,
    VOS_UINT8                           ucIndex
);


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

