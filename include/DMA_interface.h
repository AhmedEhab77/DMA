/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _DMA_INTERFACE_H_
#define   _DMA_INTERFACE_H_


void MDMA_VidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority,u8 Copy_u8CircularMode);
void MDMA_VidStartTransfer(u8 Copy_u8Channel,u32 *Copy_u32SourceAdd,u32* Copy_u32DestinationAdd,u16 Copy_u16BlockLength);
void MDMA_VidSetCallBack(void (*Lpfunc)(void) , u8 Copy_u8ChannelNum);
void MDMA_VidClearFlag(u8 Copy_u8ChannelNum);

/*****************DMA CHANNELS**************/                    
#define          DMA_CH1                     0        
#define          DMA_CH2                     1        
#define          DMA_CH3                     2        
#define          DMA_CH4                     3        
#define          DMA_CH5                     4        
#define          DMA_CH6                     5        
#define          DMA_CH7                     6        
/********************************************/                   
                                                                 




#endif