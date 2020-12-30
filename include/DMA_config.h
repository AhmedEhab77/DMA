/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _DMA_CONFIG_H_
#define   _DMA_CONFIG_H

/******************************************************************************/
/***************************MOODS OF DMA TYPES ********************************/
/******************************************************************************/
/**                           MEMORY_TO_MEMORY                                */ 
/**                           PREHPHERAL_TO_MEMORY                            */ 
/**                           MEMORY_TO_PREHPHERAL                            */
/******************************************************************************/
  #define  DMA_TYPE_OF_TRANSFER   MEMORY_TO_MEMORY
/******************************************************************************/

/******************************************************************************/
/*************************MEMORY AND PREHPHERAL SIZES *************************/
/******************************************************************************/
/**                           DMA_8                                           */ 
/**                           DMA_16                                          */ 
/**                           DMA_32                                          */
/**                           DMA_RESERVED                                    */
/******************************************************************************/
#define  DMA_MEMORY_SIZE       DMA_32
/******************************************************************************/
#define  DMA_PERIPHERAL_SIZE   DMA_32
/******************************************************************************/

/******************************************************************************/
/***************************DIRECTION OF TRANSFER *****************************/
/******************************************************************************/
/**                        ADDRESS_PERIPHERAL_REG_IS_SOURCE                   */ 
/**                        ADDRESS_MEMORY_REG_IS_SOURCE                       */ 
/******************************************************************************/
#define  DMA_DIRCTION_OF_TRANSFER       ADDRESS_MEMORY_REG_IS_SOURCE
/******************************************************************************/

/******************************************************************************/
/***************************CHANNEL PIRIORITES ********************************/
/******************************************************************************/
/**                            DMA_LOW_PIRIORITY                             **/
/**                            DMA_MEDIUM_PIRIORITY                          **/
/**                            DMA_HIGH_PIRIORITY                            **/
/**                            DMA_VERY_HIGH_PIRIORITY                       **/
/******************************************************************************/
#define  DMA_CHANNEL_PIRIORITY       DMA_VERY_HIGH_PIRIORITY
/******************************************************************************/

/******************************************************************************/
/***************************MOODS OF INCREMENT ********************************/
/******************************************************************************/
/**                            DMA_INC_ENABLED                               **/
/**                            DMA_INC_DISABLED                              **/
/******************************************************************************/
#define  DMA_MEMORY_INCREMENT_MODE          DMA_INC_ENABLED
/******************************************************************************/
#define  DMA_PREPHERAL_INCREMENT_MODE       DMA_INC_ENABLED
/******************************************************************************/

/******************************************************************************/
/***************************MOODS OF CIRCULAR *********************************/
/******************************************************************************/
/**                            DMA_CIRCULAR_ON                               **/
/**                            DMA_CIRCULAR_OFF                              **/
/******************************************************************************/
#define  DMA_CIRCULAR_MODE       DMA_CIRCULAR_OFF  
/******************************************************************************/


#endif
