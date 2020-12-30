/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_macros.h"
#include "RCC_private.h"
#include "RCC_config.h"




void MRCC_VidInit(void)
{
	/********************************/
	/**CHOOSING SYSTEM CLOCK SOURCE**/
	/********************************/
	
	/*********************************/
	#if      SYS_CLOCK_SOURCE==RCC_HSI
	{
	/**CHOOSING HSI AS CLOCK SOURCE**/	
    CLR_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);
	/** ENABLE THE HSI CLOCK**/
	SET_BIT(RCC->CR,0);
	/** POLLING ON HSI FLAG**/
	while(HSI_FLAG_NOT_READY);	//WAITING UNTIL FLAG IS READY
	RCC_VidCalibrationHSI();
	}
	/********************************/
	
	/********************************/
    #elif    SYS_CLOCK_SOURCE==RCC_HSE
	{	
	/**CHOOSING HSE AS CLOCK SOURCE**/
    SET_BIT(RCC->CFGR,0);
    CLR_BIT(RCC->CFGR,1);
	/**CHOOSING BYPASS OR NOT BYPASS**/
	#if      EXTERNAL_CLOCK_SOURCE ==EXTERNAL_RC
    SET_BIT(RCC->CR,18);
    #elif    EXTERNAL_CLOCK_SOURCE ==EXTERNAL_CRYSTAL 
    CLR_BIT(RCC->CR,18);
	#endif
	/** ENABLE THE HSE CLOCK**/
	SET_BIT(RCC->CR,16);
	/** POLLING ON HSE FLAG**/
	while(HSE_FLAG_NOT_READY);  //WAITING UNTIL FLAG IS READY
	}
	/********************************/
	
	/********************************/
    #elif    SYS_CLOCK_SOURCE==RCC_PLL
	{
	/**CHOOSING PLL AS CLOCK SOURCE**/
    CLR_BIT(RCC->CFGR,0);
    SET_BIT(RCC->CFGR,1);
	/**CHOOSING PLL SOURCE**/
	#if      PLL_SOURCE == HSE_CLOCK
    SET_BIT(RCC->CFGR,16); //CHOOSE HSE AS SOURCE 
	CLR_BIT(RCC->CFGR,17); //HSE NOT DIVIDED
	SET_BIT(RCC->CR,16);   //HSE ON
    #elif    PLL_SOURCE == HSE_CLOCK_2
	SET_BIT(RCC->CFGR,16); //CHOOSE HSE AS SOURCE 
    SET_BIT(RCC->CFGR,17); //HSE/2
	SET_BIT(RCC->CR,16);   //HSE ON
	#elif    PLL_SOURCE == HSI_CLOCK_2
	SET_BIT(RCC->CR,0);    //HSI ON
    CLR_BIT(RCC->CFGR,16); //CHOOSE HSI/2 AS SOURCE
    SET_BIT(RCC->CR,0);	  //HSI ON 
	#endif
	/**CHOOSING PLL FACTOR**/
	#if      PLL_FACTOR == PLL_2
    RCC->CFGR |= (0<<18);
    #elif    PLL_FACTOR == PLL_3
    RCC->CFGR |= (1<<18);
	#elif    PLL_FACTOR == PLL_4
    RCC->CFGR |= (2<<18);
	#elif    PLL_FACTOR == PLL_5
    RCC->CFGR |= (3<<18);
	#elif    PLL_FACTOR == PLL_6
    RCC->CFGR |= (4<<18);
	#elif    PLL_FACTOR == PLL_7
    RCC->CFGR |= (5<<18);
	#elif    PLL_FACTOR == PLL_8
    RCC->CFGR |= (6<<18);
	#elif    PLL_FACTOR == PLL_9
    RCC->CFGR |= (7<<18);
	#elif    PLL_FACTOR == PLL_10
    RCC->CFGR |= (8<<18);
	#elif    PLL_FACTOR == PLL_11
    RCC->CFGR |= (9<<18);
	#elif    PLL_FACTOR == PLL_12
    RCC->CFGR |= (10<<18);
	#elif    PLL_FACTOR == PLL_13
    RCC->CFGR |= (11<<18);
	#elif    PLL_FACTOR == PLL_14
    RCC->CFGR |= (12<<18);
	#elif    PLL_FACTOR == PLL_15
    RCC->CFGR |= (13<<18);
	#elif    PLL_FACTOR == PLL_16
    RCC->CFGR |= (14<<18);
	#endif
	/** ENABLE THE PLL CLOCK**/
	SET_BIT(RCC->CR,24);
	/** POLLING ON PLL FLAG**/
	while(PLL_FLAG_NOT_READY); //WAITING UNTIL FLAG IS READY
	}
	#endif
	/**********************************/
	/**CHOOSING SPEED OF AHB**/
	#if      AHB_SPEED == SYSCLK_not_divided
    RCC->CFGR |= (0<<4);
    #elif    AHB_SPEED == SYSCLK_divided_by_2
    RCC->CFGR |= (1<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_4
    RCC->CFGR |= (2<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_8
    RCC->CFGR |= (3<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_16
    RCC->CFGR |= (4<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_64
    RCC->CFGR |= (5<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_128
    RCC->CFGR |= (6<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_256
    RCC->CFGR |= (7<<4);
	#elif    AHB_SPEED == SYSCLK_divided_by_512
    RCC->CFGR |= (8<<4);
	#endif
	
	/**CHOOSING SPEED OF APB1**/
	#if      APB1_SPEED == HCLK_not_divided
    RCC->CFGR |= (0<<8);
    #elif    APB1_SPEED == HCLK_divided_by_2
    RCC->CFGR |= (1<<8);
	#elif    APB1_SPEED == HCLK_divided_by_4
    RCC->CFGR |= (2<<8);
	#elif    APB1_SPEED == HCLK_divided_by_8
    RCC->CFGR |= (3<<8);
	#elif    APB1_SPEED == HCLK_divided_by_16
    RCC->CFGR |= (4<<8);
	#endif
	
	/**CHOOSING SPEED OF APB2**/
	#if      APB2_SPEED == HCLK_not_divided
	RCC->CFGR |= (0<<11);
	#elif    APB2_SPEED == HCLK_divided_by_2
	RCC->CFGR |= (1<<11);
	#elif    APB2_SPEED == HCLK_divided_by_4
	RCC->CFGR |= (2<<11);
	#elif    APB2_SPEED == HCLK_divided_by_8
	RCC->CFGR |= (3<<11);
	#elif    APB2_SPEED == HCLK_divided_by_16
	RCC->CFGR |= (4<<11);
	#endif
	
		
}

void MRCC_VidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId < 32)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  :SET_BIT(RCC->AHBENR,Copy_u8PeripheralId);
			break;                    
			case RCC_APB1 :SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
			break;                    
			case RCC_APB2 :SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId); 
			break;
		}
	}
}

void MRCC_VidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId < 32)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  :CLR_BIT(RCC->AHBENR,Copy_u8PeripheralId);
			break;                    
			case RCC_APB1 :CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);
			break;                    
			case RCC_APB2 :CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId); 
    		break;
    	}
    }
}


void MRCC_VidCalibrationHSI(void)
{
	u8 HSI_VALUE_DECIMAL=0;
	u8 STEP=0;
	u32 HSI_VALUE;
		/**GET THE VALUE OF CLOCK IN DECIMAL**/
	HSI_VALUE_DECIMAL=((RCC->CR)>>8)+16; 
	     /**TURNING THE DECIMAL TO MHZ**/
	HSI_VALUE=HSI_VALUE_DECIMAL*STEP_SIZE;
		/**COMPARING VALUE OF CLOCK TO 8MHZ**/	
	if(HSI_VALUE > MAX_HSI)
	{
		/**TO KNOW HOW MUCH THE INCREMENT OF CLOCK**/
		HSI_VALUE=HSI_VALUE-MAX_HSI;
		STEP=HSI_VALUE/STEP_SIZE;
		/**DECREMENTING STEPS TO REACH 8MHZ**/
		RCC->CR|=((16-STEP) << 3 );
	}
	else if(HSI_VALUE < MAX_HSI)
	{
		/**TO KNOW HOW MUCH THE DECREMENT OF CLOCK**/
		HSI_VALUE=MAX_HSI-HSI_VALUE;
		STEP=HSI_VALUE/STEP_SIZE;
		/**INCREMENTING STEPS TO REACH 8MHZ**/
		RCC->CR|=((16+STEP) << 3 );
	}				
}
