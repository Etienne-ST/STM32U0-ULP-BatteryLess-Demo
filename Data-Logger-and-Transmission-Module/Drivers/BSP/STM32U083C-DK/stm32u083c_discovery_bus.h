/**
  ******************************************************************************
  * @file    stm32u083c_discovery_bus.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for STM32U083C_DK bus.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U083C_DK_BUS_H
#define STM32U083C_DK_BUS_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u083c_discovery_conf.h"
#include "stm32u083c_discovery_errno.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32U083C_DK
  * @{
  */

/** @addtogroup STM32U083C_DK_BUS
  * @{
  */
   
/** @defgroup STM32U083C_DK_BUS_Exported_Types STM32U083C-DK BUS Exported Types
  * @{
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
typedef struct
{
  pI2C_CallbackTypeDef  pMspI2cInitCb;
  pI2C_CallbackTypeDef  pMspI2cDeInitCb;
} BSP_I2C_Cb_t;
#endif /* (USE_HAL_I2C_REGISTER_CALLBACKS == 1) */

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
typedef struct
{
  pSPI_CallbackTypeDef  pMspSpiInitCb;
  pSPI_CallbackTypeDef  pMspSpiDeInitCb;
}BSP_SPI1_Cb_t;
#endif /* (USE_HAL_SPI_REGISTER_CALLBACKS == 1) */
/**
  * @}
  */

/** @defgroup STM32U083C_DK_BUS_Exported_Constants STM32U083C-DK BUS Exported Constants
  * @{
  */
#define BUS_I2C1                        I2C1
#define BUS_I2C1_CLK_ENABLE()           __HAL_RCC_I2C1_CLK_ENABLE()
#define BUS_I2C1_CLK_DISABLE()          __HAL_RCC_I2C1_CLK_DISABLE()
#define BUS_I2C1_FORCE_RESET()          __HAL_RCC_I2C1_FORCE_RESET()
#define BUS_I2C1_RELEASE_RESET()        __HAL_RCC_I2C1_RELEASE_RESET()
#define BUS_I2C1_SCL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_I2C1_SCL_GPIO_PIN           GPIO_PIN_8
#define BUS_I2C1_SCL_GPIO_PORT          GPIOB
#define BUS_I2C1_SCL_GPIO_AF            GPIO_AF4_I2C1
#define BUS_I2C1_SDA_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#if defined (USE_STM32U083C_DISCO_REVB)
#define BUS_I2C1_SDA_GPIO_PIN           GPIO_PIN_7
#else
#define BUS_I2C1_SDA_GPIO_PIN           GPIO_PIN_9
#endif /* USE_STM32U083C_DISCO_REVB */
#define BUS_I2C1_SDA_GPIO_PORT          GPIOB
#define BUS_I2C1_SDA_GPIO_AF            GPIO_AF4_I2C1
#define BUS_I2C1_TIMEOUT                10000U
#if defined(HAL_SPI_MODULE_ENABLED)

/*##################### SPI1 ###################################*/
#define BUS_SPI1_INSTANCE                 SPI1
#define BUS_SPI1_CLOCK_ENABLE()           __HAL_RCC_SPI1_CLK_ENABLE()
#define BUS_SPI1_CLOCK_DISABLE()          __HAL_RCC_SPI1_CLK_DISABLE()
#define BUS_SPI1_GPIO_PORT                GPIOB                      /* GPIOB */
  
#define BUS_SPI1_GPIO_PORTA               GPIOA
#define BUS_SPI1_GPIO_PORTB               GPIOB
  
#define BUS_SPI1_AF                       GPIO_AF5_SPI1
#define BUS_SPI1_GPIO_CLK_ENABLE()        __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_SPI1_GPIO_CLK_DISABLE()       __HAL_RCC_GPIOB_CLK_DISABLE()
  
#define BUS_SPI1_GPIO_CLKA_ENABLE()        __HAL_RCC_GPIOA_CLK_ENABLE()
#define BUS_SPI1_GPIO_CLKA_DISABLE()       __HAL_RCC_GPIOA_CLK_DISABLE()

#define BUS_SPI1_GPIO_CLKB_ENABLE()        __HAL_RCC_GPIOB_CLK_ENABLE()
#define BUS_SPI1_GPIO_CLKB_DISABLE()       __HAL_RCC_GPIOB_CLK_DISABLE()

#define BUS_SPI1_GPIO_FORCE_RESET()       __HAL_RCC_SPI1_FORCE_RESET()
#define BUS_SPI1_GPIO_RELEASE_RESET()     __HAL_RCC_SPI1_RELEASE_RESET()
#define BUS_SPI1_SCK_PIN                  GPIO_PIN_3                 /* PB.03*/
#define BUS_SPI1_MOSI_PIN                 GPIO_PIN_7                 /* PA.07 */
#define BUS_SPI1_MISO_PIN                 GPIO_PIN_6                 /* PA.06 */

#define BUS_SPI1_TIMEOUT                  ((uint32_t)0x1000)

#ifndef BUS_SPI1_BAUDRATE
//   #define BUS_SPI1_BAUDRATE  12500000    /* baud rate of SPIn = 12.5 Mbps*/
   #define BUS_SPI1_BAUDRATE  8000000    /* baud rate of SPIn = 12.5 Mbps*/
#endif

#endif /* HAL_SPI_MODULE_ENABLED */

/**
  * @}
  */

/** @addtogroup STM32U083C_DK_BUS_Exported_Variables
  * @{
  */
extern I2C_HandleTypeDef hbus_i2c1;
extern SPI_HandleTypeDef hbus_spi1;
/**
  * @}
  */

/** @addtogroup STM32U083C_DK_BUS_Exported_Functions
  * @{
  */
int32_t BSP_I2C1_Init(void);
int32_t BSP_I2C1_DeInit(void);
int32_t BSP_I2C1_WriteReg(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C1_ReadReg(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C1_WriteReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C1_ReadReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length);
int32_t BSP_I2C1_IsReady(uint16_t DevAddr, uint32_t Trials);
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
int32_t BSP_I2C1_RegisterDefaultMspCallbacks(void);
int32_t BSP_I2C1_RegisterMspCallbacks(BSP_I2C_Cb_t *Callbacks);
#endif /* (USE_HAL_I2C_REGISTER_CALLBACKS == 1) */
HAL_StatusTypeDef MX_I2C1_Init(I2C_HandleTypeDef *hI2c, uint32_t timing);

int32_t BSP_SPI1_Init(void);
int32_t BSP_SPI1_DeInit(void);
int32_t BSP_SPI1_Send(uint8_t *pData, uint16_t Length);
int32_t BSP_SPI1_Recv(uint8_t *pData, uint16_t Length);
int32_t BSP_SPI1_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t Length);

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1)
int32_t BSP_SPI1_RegisterDefaultMspCallbacks (void);
int32_t BSP_SPI1_RegisterMspCallbacks (BSP_SPI1_Cb_t *Callbacks);
#endif /* (USE_HAL_SPI_REGISTER_CALLBACKS == 1) */

HAL_StatusTypeDef MX_SPI1_Init(SPI_HandleTypeDef* phspi, uint32_t BaudratePrescaler);

int32_t BSP_GetTick(void);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32U083C_DK_BUS_H */