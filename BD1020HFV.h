// License       : License.txt
// Specifications: Spec-BD1020HFV.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : BD1020HFV.h
// Reason for change: 01.00.00 : 24/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __BD1020HFV_H__
#define __BD1020HFV_H__

#include "user_define.h"

// Components number
#define iBD1020HFV              122U                    // ROHM BD1020HFV

// BD1020HFV System Parts definitions
#define iBD1020HFV_xoff         1.3F                    // X offset [V]
#define iBD1020HFV_yoff         30.0F                   // Y offset [degree celsius]
#define iBD1020HFV_gain         -0.0082F                // Gain [V/degree celsius]
#define iBD1020HFV_max          100.0F                  // Temperature Max [degree celsius]
#define iBD1020HFV_min          -30.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_BD1020HFV;

#endif /*__BD1020HFV_H__*/
