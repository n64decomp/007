#include <PR/os_internal.h>
#include <PR/rcp.h>
#include <io/piint.h>

void __osDevMgrMain(void *args)
{
  OSIoMesg *mb;
  OSMesg em;
  OSMesg dummy;
  s32 ret;
  OSDevMgr *dm;
  s32 messageSend;

  messageSend = 0;
  mb = NULL;
  ret = 0;
  dm = (OSDevMgr *)args;
  while (TRUE)
  {
    osRecvMesg(dm->cmdQueue, (OSMesg)&mb, OS_MESG_BLOCK);
    if (mb->piHandle != NULL &&
        mb->piHandle->type == DEVICE_TYPE_64DD &&
        (mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_0 ||
         mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_1))
    {
      __OSBlockInfo *blockInfo;
      __OSTranxInfo *info;
      info = &mb->piHandle->transferInfo;
      blockInfo = &info->block[info->blockNum];
      info->sectorNum = -1;
      if (info->transferMode != LEO_SECTOR_MODE)
      {
        blockInfo->dramAddr = (void *)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
      }
      if (info->transferMode == LEO_TRACK_MODE && mb->piHandle->transferInfo.cmdType == LEO_CMD_TYPE_0)
        messageSend = 1;
      else
        messageSend = 0;
      osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
      __osResetGlobalIntMask(OS_IM_PI);
      osEPiRawWriteIo(mb->piHandle, LEO_BM_CTL, (info->bmCtlShadow | 0x80000000));
      while (TRUE)
      {

        osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
        osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);

        if (messageSend != 1)
          break;
        if (mb->piHandle->transferInfo.block[0].errStatus != LEO_ERROR_GOOD)
          break;
        messageSend = 0;
      }
      osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
      if (mb->piHandle->transferInfo.blockNum == 1)
        osYieldThread();
    }
    else
    {
      switch (mb->hdr.type)
      {
      case OS_MESG_TYPE_DMAREAD:
        osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
        ret = dm->dma(OS_READ, mb->devAddr, mb->dramAddr, mb->size);
        break;
      case OS_MESG_TYPE_DMAWRITE:
        osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
        ret = dm->dma(OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
        break;
      case OS_MESG_TYPE_EDMAREAD:
        osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
        ret = dm->edma(mb->piHandle, OS_READ, mb->devAddr, mb->dramAddr,
                       mb->size);
        break;
      case OS_MESG_TYPE_EDMAWRITE:
        osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
        ret = dm->edma(mb->piHandle, OS_WRITE, mb->devAddr, mb->dramAddr,
                       mb->size);
        break;
      case OS_MESG_TYPE_LOOPBACK:
        osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
        ret = -1;
        break;
      default:
        ret = -1;
        break;
      }
      if (ret == 0)
      {
        osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
        osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
        osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
      }
    }
  }
}
