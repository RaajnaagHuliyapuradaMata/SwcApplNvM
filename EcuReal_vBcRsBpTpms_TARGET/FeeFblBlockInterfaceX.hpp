#ifndef FEE_FBL_BLOCK_INTERFACE_X_H
#define FEE_FBL_BLOCK_INTERFACE_X_H

#include "types.hpp"
#include "WrapNv_Cfg.hpp"

extern uint8 FEEFBL_GetProgAttemptsCounter(uint8* lptru8Data);
extern uint8 FEEFBL_GetMaxProgAttemptsCounter(uint8* lptru8Data);
extern uint8 FEEFBL_GetUdsAppKey(uint8* lptru8Data);
extern uint8 FEEFBL_GetUdsBootKey(uint8* lptru8Data);
extern uint8 FEEFBL_GetUdsMsgKey(uint8* lptru8Data);
extern uint8 FEEFBL_GetProgrammingDate(uint8* lptru8Data, uint8 ucAppFbl);
extern uint8 FEEFBL_GetTesterSerialNumber(uint8* lptru8Data, uint8 ucAppFbl);

extern uint8 FEEFBL_PutUdsAppKey(const uint8* lptru8Data);
extern uint8 FEEFBL_PutUdsBootKey(const uint8* lptru8Data);
extern uint8 FEEFBL_PutUdsMsgKey(const uint8* lptru8Data);

#endif //FEE_FBL_BLOCK_INTERFACE_X_H