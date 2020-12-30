#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_macros.h"

#include "NVIC_interface.h"
#include "NVIC_macros.h"

#include "DMA_interface.h"
#include "DMA_macros.h"

void DMA_ISR(void)
{
	MDMA_VidClearFlag(DMA_CH1);
}

u16 i;
int main (void)
{
	/******ARRAYS FOR PROCESSOR*****/
	u32 Arr1[1000]={0};
	u32 Arr2[1000];
	/*******************************/
	/*********ARRAYS FOR DMA********/
	u32 Arr3[1000]={0};
	u32 Arr4[1000];
	/*******************************/
	/******DMA SET CALL BACK******/
	MDMA_VidSetCallBack(DMA_ISR,DMA_CH1);
	/*******RCC INIT*******/
	MRCC_VidInit();
	/******ENABLE CLOCK FOR DMA*****/
	MRCC_VidEnableClock(RCC_AHB,DMA1_RCC);
	/******DMA INIT******/
	MDMA_VidSetConfiguration(DMA_CH1,READ_FROM_MEMORY,MEM_TO_MEM,DMA_INC_ENABLED,DMA_INC_ENABLED,DMA_32_BITS,DMA_32_BITS,DMA_VERY_HIGH_PIRIORITY,DMA_CIRCULAR_OFF);
	/*******NVIC INIT**************/
    MNVIC_VidInit();
    /******ENABLE NVIC FLAG FOR DMA******/
    MNVIC_u8Enable(VECT_DMA1_Channel1);
    /********START DMA OPERATION********/
    MDMA_VidStartTransfer(DMA_CH1,Arr3,Arr4,1000);

    /*******START PROCESSOR********/
    for( i=0; i<1000; i++)
    {
    	Arr2[i]=Arr1[i];
    }
	
	while(1)
	{
		asm("NOP");
	}
	return 0;
}




