// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : BD1020HFV_00000058.cpp
// BSL              : 00000058
// Model number     : ROHM BD1020HFV
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 24/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "BD1020HFV.h"

AnalogIn BD1020HFV_adc( iBD1020HFV_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t BD1020HFV_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( BD1020HFV_adc , tbl_BD1020HFV );
        return( res );
}
