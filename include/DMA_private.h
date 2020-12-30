/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _DMA_PRIVATE_H_
#define   _DMA_PRIVATE_H_

typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
	
}DMA_CHANNEL;



typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_CHANNEL Channel[7];
	
}DMA_TYPE;

#define        DMA          ((volatile DMA_TYPE*)0x40020000)
/***********************************************************
************************************************************/


/******************************************************************************/
/***************************MOODS OF DMA TYPES ********************************/
/******************************************************************************/
#define                            MEM_TO_MEM                                  0
#define                            PRE_TO_MEM                                  1
#define                            MEM_TO_PRE                                  2
/******************************************************************************/

/******************************************************************************/
/***************************DIRECTION OF TRANSFER *****************************/
/******************************************************************************/
#define                            READ_FROM_PREPHERAL                         0
#define                            READ_FROM_MEMORY                            1
/******************************************************************************/


/******************************************************************************/
/**************************MEMORY AND PREHPHERAL SIZES ************************/
/******************************************************************************/
#define                           DMA_8_BITS                              0b00
#define                           DMA_16_BITS                             0b01
#define                           DMA_32_BITS                             0b10
#define                           DMA_RESERVED                            0b11
/******************************************************************************/


/******************************************************************************/
/***************************CHANNEL PIRIORITES ********************************/
/******************************************************************************/
#define                            DMA_LOW_PIRIORITY                      0b00
#define                            DMA_MEDIUM_PIRIORITY                   0b01
#define                            DMA_HIGH_PIRIORITY                     0b10
#define                            DMA_VERY_HIGH_PIRIORITY                0b11
/******************************************************************************/

/******************************************************************************/
/***************************MOODS OF INCREMENT ********************************/
/******************************************************************************/
#define                            DMA_INC_ENABLED                           1
#define                            DMA_INC_DISABLED                          0
/******************************************************************************/

/******************************************************************************/
/***************************MOODS OF CIRCULAR *********************************/
/******************************************************************************/
#define                            DMA_CIRCULAR_ON                           1
#define                            DMA_CIRCULAR_OFF                          0
/******************************************************************************/




#endif