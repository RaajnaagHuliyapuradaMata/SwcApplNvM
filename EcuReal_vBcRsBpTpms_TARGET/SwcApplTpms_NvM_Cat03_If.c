#include "Std_Types.hpp"

#include "iTpms_Interface.hpp"
#include "SwcApplTpms_Rte.hpp"
#include "SwcApplTpms_NvM.hpp"
#include "SwcApplTpms_NvM_If.hpp"
#include "WallocX.hpp"

void NvM3_PUTucAutolocationFailedCounter(
   uint8 ucCounterValue){
  WriteMember2Blocks(CATEGORY3, INDEX5, &ucCounterValue);
}

uint8 NvM3_GETucAutolocationFailedCounter(void){
  uint8 l_ucaData[NVM_CAT03_IDX05_REAL_SIZE];
  l_ucaData[0] = 0;
  ReadBlock2Member(CATEGORY3, INDEX5, l_ucaData);
  return (l_ucaData[0]);
}

void NvM3_PUTHistoryIdsInEE(
   uint32* ulData){
  WriteMember2Blocks(CATEGORY3, cHistorySet1, (uint8*)ulData);
}

void NvM3_GETHistoryIdsFromEE(
   uint32* ulData){
  ReadBlock2Member(CATEGORY3, cHistorySet1, (uint8*)ulData );
}

void NvM3_PUTHistoryWPInEE(
   uint8* lptru8Data){
  WriteMember2Blocks(CATEGORY3, cHistoryWPSet1, lptru8Data);
}

void NvM3_GETHistoryWPFromEE(
   uint8* lptru8Data){
  ReadBlock2Member (CATEGORY3, cHistoryWPSet1, lptru8Data );
}

void NvM3_PUTWAParametersInEE(
   WAParameter sWheelAllocParamData){
  WriteMember2Blocks(CATEGORY3, cWAParameter, (uint8*)&sWheelAllocParamData);
}

void NvM3_GETWAParametersFromEE(
   WAParameter* sWheelAllocParamData){
  ReadBlock2Member (CATEGORY3, cWAParameter, (uint8*)sWheelAllocParamData);
}

void NvM3_PUTABSTicksInEE(
   WAABSTicksInOneRevolution sABSTicks){
  WriteMember2Blocks(CATEGORY3, cWAABSTicksInOneRevolution, (uint8*)&sABSTicks);
}

void NvM3_GETABSTicksFromEE(
   WAABSTicksInOneRevolution* sABSTicks){
  ReadBlock2Member(CATEGORY3, cWAABSTicksInOneRevolution, (uint8*)sABSTicks);
}

void GetWADataEE(
   unsigned char ucId,
   unsigned char* pRamAdr){
   if((ucId > 0) && (ucId < 5)){
      ReadBlock2Member(
         CATEGORY3,
         ucId,
         pRamAdr);
  }
}

void PutWADataEE(
   unsigned char ucId,
   unsigned char* pRamAdr){
   if((ucId > 0) && (ucId < 5)){
      WriteMember2Blocks(
         CATEGORY3,
         ucId,
         pRamAdr);
  }
}

