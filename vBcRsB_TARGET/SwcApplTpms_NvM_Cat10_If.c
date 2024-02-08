#include "Std_Types.hpp"

#include "iTpms_Interface.hpp"
#include "SwcApplTpms_NvM_If.hpp"
#include "SwcApplTpms_Rte.hpp"
#include "SwcApplTpms_NvM.hpp"

void NvM_WriteData_ECUDefect(
   uint8 lptru8Data){
  WriteMember2Blocks  (10,2,&lptru8Data );
}

void NvM_ReadData_ECUDefect(
   uint8* ucpData){
  ReadBlock2Member (10,2,ucpData);
}

