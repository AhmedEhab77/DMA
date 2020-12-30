/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_macros.h"

/**GLOBAL ARRAY POINTER TO FUNCTION**/
static void (*Gpfunc[7])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL};
/*******************************/

void MDMA_VidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority,u8 Copy_u8CircularMode)
{
	/***********CHANNEL IS DISABLED TO WRITE ADDRESSES************/
	CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,0);
	/*********DMA MODE*******/
	if  (Copy_u8DMAMode ==   MEM_TO_MEM)
	{
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR,14);
	}
    else if (Copy_u8DMAMode == PRE_TO_MEM)
	{
	CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,14);
	}
    else if (Copy_u8DMAMode == MEM_TO_PRE)
	{
	CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,14);
	}
	/*********DIRCTION OF TRANSFER*******/
	 if  (Copy_u8Direction ==   READ_FROM_PREPHERAL )
	 {
	CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,14);
	 }
    else if (Copy_u8Direction ==   READ_FROM_PREPHERAL )
	{
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR,14);
	}
	/***********MEMORY SIZE**************/
	if  (Copy_MEMSize ==   DMA_8_BITS )
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_8_BITS <<10);
	}
    else if (Copy_MEMSize ==   DMA_16_BITS) 
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_16_BITS <<10);
	}
    else if (Copy_MEMSize==   DMA_32_BITS) 
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_32_BITS <<10);
	}
    else if (Copy_MEMSize ==   DMA_RESERVED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_RESERVED<<10);
	}
	/***********PERIPHERAL SIZE**********/
	if  (Copy_u8PERSize ==   DMA_8_BITS) 
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_8_BITS<<8);
	}
    else if (Copy_u8PERSize ==   DMA_16_BITS)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_16_BITS<<8);
	}
    else if (Copy_u8PERSize ==  DMA_32_BITS)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_32_BITS<<8);
	}
    else if (Copy_u8PERSize ==   DMA_RESERVED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_RESERVED<<8);
	}
	/*************MEMORY INCREMENT MODE(MINC)********/
	if  (Copy_u8MINC ==  DMA_INC_ENABLED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_INC_ENABLED<<7);
	}
	else if  (Copy_u8MINC ==  DMA_INC_DISABLED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_INC_DISABLED<<7);
	}
	/*************PERIPHERAL INCREMENT MODE(PINC)********/
	if  (Copy_u8PINC ==  DMA_INC_ENABLED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_INC_ENABLED<<6);
	}
	else if  (Copy_u8PINC ==  DMA_INC_DISABLED)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_INC_DISABLED<<6);
	}
	/**********CHANNEL PIRIORITY*********/
	if  (Copy_u8ChannelPriority ==   DMA_LOW_PIRIORITY)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_LOW_PIRIORITY<<12);
	}
    else if (Copy_u8ChannelPriority ==   DMA_MEDIUM_PIRIORITY)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_MEDIUM_PIRIORITY<<12);
	}
    else if (Copy_u8ChannelPriority ==   DMA_HIGH_PIRIORITY)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_HIGH_PIRIORITY<<12);
	}
    else if (Copy_u8ChannelPriority ==   DMA_VERY_HIGH_PIRIORITY)
	{
    DMA->Channel[Copy_u8Channel].CCR |= (DMA_VERY_HIGH_PIRIORITY<<12);
	}	
	/**********CIRCULAR MODE*********/
	if  (Copy_u8CircularMode ==   DMA_CIRCULAR_ON)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_CIRCULAR_ON<<5);
	}
    else if  (Copy_u8CircularMode ==   DMA_CIRCULAR_OFF)
	{
	DMA->Channel[Copy_u8Channel].CCR |= (DMA_CIRCULAR_OFF<<5);
	}
	/**********TRANSFER COMPLETE INTERRUPT ENABLE*********/
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR,1);
}
void MDMA_VidStartTransfer(u8 Copy_u8Channel,u32 *Copy_u32SourceAdd,u32* Copy_u32DestinationAdd,u16 Copy_u16BlockLength)
{
	/**********MAKE SURE THAT THE CHANNEL IS DISABLED*********/
	CLR_BIT(DMA->Channel[Copy_u8Channel].CCR,0);
	/********LOAD ADDRESS IN MEMORY REGISTER******/
	DMA->Channel[Copy_u8Channel].CMAR=(u32)Copy_u32SourceAdd;
	/********LOAD ADDRESS IN PERIPHERAL REGISTER******/
	DMA->Channel[Copy_u8Channel].CPAR=(u32)Copy_u32DestinationAdd;
	/********LOAD NUM OF TRANSFER IN BLOCK LENGTH REGISTER******/
	DMA->Channel[Copy_u8Channel].CNDTR=Copy_u16BlockLength;
	
	/**********ENABLE CHANNEL OF DMA***********/
	SET_BIT(DMA->Channel[Copy_u8Channel].CCR,0);
	
}
void MDMA_VidClearFlag(u8 Copy_u8ChannelNum)
{
	DMA->IFCR |= ( (0b1111) <<(Copy_u8ChannelNum*4) );
}

void MDMA_VidSetCallBack(void (*Lpfunc)(void) , u8 Copy_u8ChannelNum)
{
	Gpfunc[Copy_u8ChannelNum]=Lpfunc;
}

void DMA1_Channel1_IRQHandler(void)
{
	if(Gpfunc[0] != NULL)
	{
	Gpfunc[0]();
	}
}

void DMA1_Channel2_IRQHandler(void)
{
	if(Gpfunc[1] != NULL)
	{
	Gpfunc[1]();
	}
}

void DMA1_Channel3_IRQHandler(void)
{
	if(Gpfunc[2] != NULL)
	{
	Gpfunc[2]();
	}
}

void DMA1_Channel4_IRQHandler(void)
{
	if(Gpfunc[3] != NULL)
	{
	Gpfunc[3]();
	}
}


void DMA1_Channel5_IRQHandler(void)
{
	if(Gpfunc[4] != NULL)
	{
	Gpfunc[4]();
	}
}


void DMA1_Channel6_IRQHandler(void)
{
	if(Gpfunc[5] != NULL)
	{
	Gpfunc[5]();
	}
}


void DMA1_Channel7_IRQHandler(void)
{
	if(Gpfunc[6] != NULL)
	{
	Gpfunc[6]();
	}
}

