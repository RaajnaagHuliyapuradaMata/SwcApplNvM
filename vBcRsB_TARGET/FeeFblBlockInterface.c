#include "Std_Types.hpp"

#include "FeeFblBlockInterface.hpp"
#include "rba_DiagLib_MemUtils.hpp"

static const uint8 aucDefaultKey[16] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
   ,     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};

uint8 FEEFBL_GetProgAttemptsCounter(uint8* lptru8Data)
{
  uint8 U8_Counter;

  for(U8_Counter=0; U8_Counter<(kEepSizeProgAttemptsCounter); U8_Counter++)
  {
   lptru8Data[U8_Counter] = 0x00;
  }

  ApplFblNvReadProgAttemptsCounter(&lptru8Data[0]);

  return (kEepSizeProgAttemptsCounter);
}

uint8 FEEFBL_GetMaxProgAttemptsCounter(uint8* lptru8Data)
{
  uint8 U8_Counter;

  for(U8_Counter=0; U8_Counter<(kEepSizeMaxProgAttemptsCounter); U8_Counter++)
  {
   lptru8Data[U8_Counter] = 0x00;
  }

  ApplFblNvReadMaxProgAttemptsCounter(&lptru8Data[0]);

  return (kEepSizeMaxProgAttemptsCounter);
}

uint8 FEEFBL_GetProgrammingDate(uint8* lptru8Data, uint8 ucAppFbl)
{
  uint8 U8_Counter;

  for(U8_Counter=0; U8_Counter<(kEepSizeProgrammingDate); U8_Counter++)
  {
   lptru8Data[U8_Counter] = 0x00;
  }

  ApplFblNvReadProgrammingDate(ucAppFbl, &lptru8Data[0]);

  return (kEepSizeProgrammingDate);
}

uint8 FEEFBL_GetTesterSerialNumber(uint8* lptru8Data, uint8 ucAppFbl)
{
  uint8 U8_Counter;

  for(U8_Counter=0; U8_Counter<(kEepSizeTesterSerialNumber); U8_Counter++)
  {
   lptru8Data[U8_Counter] = 0x00;
  }

  ApplFblNvReadTesterSerialNumber(ucAppFbl, &lptru8Data[0]);

  return (kEepSizeTesterSerialNumber);
}

 uint8 FEEFBL_GetUdsAppKey(uint8* lptru8Data)
 {
  uint8 ucCounter;
  boolean bKeyInitialized = FALSE;

  ApplFblNvReadSecKey_UDSAPPKEY(&lptru8Data[0]);

  for(ucCounter = 0; ucCounter < kEepSizeSecKey_UDSAPPKEY; ucCounter++)
  {
   if(lptru8Data[ucCounter] != 0xff)
   {
      bKeyInitialized = TRUE;
   }
  }

  if(bKeyInitialized == FALSE)
  {
    rba_DiagLib_MemUtils_MemCpy(lptru8Data, aucDefaultKey, kEepSizeSecKey_UDSAPPKEY);
  }

  return (kEepSizeSecKey_UDSAPPKEY);
 }

 uint8 FEEFBL_GetUdsBootKey(uint8* lptru8Data)
 {
  uint8 ucCounter;
  boolean bKeyInitialized = FALSE;

  ApplFblNvReadSecKey_UDSBOOTKEY(&lptru8Data[0]);

  for(ucCounter = 0; ucCounter < kEepSizeSecKey_UDSBOOTKEY; ucCounter++)
  {
   if(lptru8Data[ucCounter] != 0xff)
   {
      bKeyInitialized = TRUE;
   }
  }

  if(bKeyInitialized == FALSE)
  {
    rba_DiagLib_MemUtils_MemCpy(lptru8Data, aucDefaultKey, kEepSizeSecKey_UDSBOOTKEY);
  }

  return (kEepSizeSecKey_UDSBOOTKEY);
 }

 uint8 FEEFBL_GetUdsMsgKey(uint8* lptru8Data)
 {
  uint8 ucCounter;
  boolean bKeyInitialized = FALSE;

  ApplFblNvReadSecKey_UDSMSGKEY(&lptru8Data[0]);

  for(ucCounter = 0; ucCounter < kEepSizeSecKey_UDSMSGKEY; ucCounter++)
  {
   if(lptru8Data[ucCounter] != 0xff)
   {
      bKeyInitialized = TRUE;
   }
  }

  if(bKeyInitialized == FALSE)
  {
    rba_DiagLib_MemUtils_MemCpy(lptru8Data, aucDefaultKey, kEepSizeSecKey_UDSMSGKEY);
  }

  return (kEepSizeSecKey_UDSMSGKEY);
 }

 uint8 FEEFBL_PutUdsAppKey(const uint8* lptru8Data)
 {
  uint8 ucRetVal;
  ucRetVal = ApplFblNvWriteSecKey_UDSAPPKEY(&lptru8Data[0]);
  return ucRetVal;
 }

 uint8 FEEFBL_PutUdsBootKey(const uint8* lptru8Data)
 {
  uint8 ucRetVal;
  ucRetVal = ApplFblNvWriteSecKey_UDSBOOTKEY(&lptru8Data[0]);
  return ucRetVal;
 }

 uint8 FEEFBL_PutUdsMsgKey(const uint8* lptru8Data)
 {
  uint8 ucRetVal;
  ucRetVal = ApplFblNvWriteSecKey_UDSMSGKEY(&lptru8Data[0]);
  return ucRetVal;
 }

 uint8 FEEFBL_PutApplicationSignature(uint8* lptru8Data)
 {
  uint8 ucRetVal;
  ucRetVal = ApplFblNvWriteApplicationSignature(0, &lptru8Data[0]);
  return ucRetVal;
 }

