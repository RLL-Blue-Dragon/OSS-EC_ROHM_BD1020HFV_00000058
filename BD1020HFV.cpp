// License       : License.txt
// Specifications: Spec-BD1020HFV.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : BD1020HFV.cpp
// Reason for change: 01.00.00 : 24/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "BD1020HFV.h"

#if     iBD1020HFV_ma == iSMA                           // Simple moving average filter
static float32 BD1020HFV_sma_buf[iBD1020HFV_SMA_num];
static sma_f32_t BD1020HFV_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iBD1020HFV_SMA_num ,                            // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &BD1020HFV_sma_buf[0]                           // buffer
};

#elif   iBD1020HFV_ma == iEMA                           // Exponential moving average filter
static ema_f32_t BD1020HFV_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iBD1020HFV_EMA_K                                // Exponential smoothing factor
};

#elif   iBD1020HFV_ma == iWMA                           // Weighted moving average filter
static float32 BD1020HFV_wma_buf[iBD1020HFV_WMA_num];
static wma_f32_t BD1020HFV_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iBD1020HFV_WMA_num ,                            // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iBD1020HFV_WMA_num * (iBD1020HFV_WMA_num + 1)/2 ,     // kn sum
        &BD1020HFV_wma_buf[0]                           // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_BD1020HFV =
{
        iBD1020HFV              ,
        iBD1020HFV_pin          ,
        iBD1020HFV_xoff         ,
        iBD1020HFV_yoff         ,
        iBD1020HFV_gain         ,
        iBD1020HFV_max          ,
        iBD1020HFV_min          ,
        iBD1020HFV_ma           ,
        
#if     iBD1020HFV_ma == iSMA                           // Simple moving average filter
        &BD1020HFV_Phy_SMA      ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iBD1020HFV_ma == iEMA                           // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &BD1020HFV_Phy_EMA      ,
        (wma_f32_t*)iDummy_adr
#elif   iBD1020HFV_ma == iWMA                           // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &BD1020HFV_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
