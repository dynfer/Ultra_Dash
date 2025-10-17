/*
    ChibiOS - Copyright (C) 2006..2025 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*
 * Setup for STMicroelectronics STM32 Nucleo144-H743ZI board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_NUCLEO144_H743ZI
#define BOARD_NAME                  "STMicroelectronics STM32 Nucleo144-H743ZI"

/*
 * Ethernet PHY type.
 */
#define BOARD_PHY_ID                MII_LAN8742A_ID
#define BOARD_PHY_RMII

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                32768U
#endif

#define STM32_LSEDRV                (3U << 3U)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                25000000U
#endif

/*
 * MCU type as defined in the ST header.
 */
#undef STM32H743xx
#define STM32H743xx

/*
 * IO pins assignments.
 */
#define GPIOA_PIN0                  0U
#define GPIOA_RMII_REF_CLK          1U
#define GPIOA_RMII_MDIO             2U
#define GPIOA_PIN3                  3U
#define GPIOA_PIN4                  4U
#define GPIOA_PIN5                  5U
#define GPIOA_PIN6                  6U
#define GPIOA_RMII_CRS_DV           7U
#define GPIOA_USB_SOF               8U
#define GPIOA_MCO1                  8U
#define GPIOA_USB_VBUS              9U
#define GPIOA_USB_ID                10U
#define GPIOA_USB_DM                11U
#define GPIOA_USB_DP                12U
#define GPIOA_SWDIO                 13U
#define GPIOA_SWCLK                 14U
#define GPIOA_T_JTDI                15U

#define GPIOB_LED1                  0U
#define GPIOB_LED_GREEN             0U
#define GPIOB_LED                   0U
#define GPIOB_PIN1                  1U
#define GPIOB_PIN2                  2U
#define GPIOB_SWO                   3U
#define GPIOB_PIN4                  4U
#define GPIOB_PIN5                  5U
#define GPIOB_PIN6                  6U
#define GPIOB_LED2                  7U
#define GPIOB_LED_BLUE              7U
#define GPIOB_PIN8                  8U
#define GPIOB_PIN9                  9U
#define GPIOB_PIN10                 10U
#define GPIOB_PIN11                 11U
#define GPIOB_PIN12                 12U
#define GPIOB_RMII_TXD1             13U
#define GPIOB_LED3                  14U
#define GPIOB_LED_RED               14U
#define GPIOB_PIN15                 15U

#define GPIOC_PIN0                  0U
#define GPIOC_RMII_MDC              1U
#define GPIOC_PIN2                  2U
#define GPIOC_PIN3                  3U
#define GPIOC_RMII_RXD0             4U
#define GPIOC_RMII_RXD1             5U
#define GPIOC_PIN6                  6U
#define GPIOC_PIN7                  7U
#define GPIOC_PIN8                  8U
#define GPIOC_PIN9                  9U
#define GPIOC_PIN10                 10U
#define GPIOC_PIN11                 11U
#define GPIOC_PIN12                 12U
#define GPIOC_BUTTON                13U
#define GPIOC_OSC32_IN              14U
#define GPIOC_OSC32_OUT             15U

#define GPIOD_PIN0                  0U
#define GPIOD_PIN1                  1U
#define GPIOD_PIN2                  2U
#define GPIOD_PIN3                  3U
#define GPIOD_PIN4                  4U
#define GPIOD_PIN5                  5U
#define GPIOD_PIN6                  6U
#define GPIOD_PIN7                  7U
#define GPIOD_USART3_RX             8U
#define GPIOD_STLK_RX               8U
#define GPIOD_USART3_TX             9U
#define GPIOD_STLK_TX               9U
#define GPIOD_PIN10                 10U
#define GPIOD_PIN11                 11U
#define GPIOD_PIN12                 12U
#define GPIOD_PIN13                 13U
#define GPIOD_PIN14                 14U
#define GPIOD_PIN15                 15U

#define GPIOE_PIN0                  0U
#define GPIOE_PIN1                  1U
#define GPIOE_PIN2                  2U
#define GPIOE_PIN3                  3U
#define GPIOE_PIN4                  4U
#define GPIOE_PIN5                  5U
#define GPIOE_PIN6                  6U
#define GPIOE_PIN7                  7U
#define GPIOE_PIN8                  8U
#define GPIOE_PIN9                  9U
#define GPIOE_PIN10                 10U
#define GPIOE_PIN11                 11U
#define GPIOE_PIN12                 12U
#define GPIOE_PIN13                 13U
#define GPIOE_PIN14                 14U
#define GPIOE_PIN15                 15U

#define GPIOF_PIN0                  0U
#define GPIOF_PIN1                  1U
#define GPIOF_PIN2                  2U
#define GPIOF_PIN3                  3U
#define GPIOF_PIN4                  4U
#define GPIOF_PIN5                  5U
#define GPIOF_PIN6                  6U
#define GPIOF_PIN7                  7U
#define GPIOF_PIN8                  8U
#define GPIOF_PIN9                  9U
#define GPIOF_PIN10                 10U
#define GPIOF_PIN11                 11U
#define GPIOF_PIN12                 12U
#define GPIOF_PIN13                 13U
#define GPIOF_PIN14                 14U
#define GPIOF_PIN15                 15U

#define GPIOG_PIN0                  0U
#define GPIOG_PIN1                  1U
#define GPIOG_PIN2                  2U
#define GPIOG_PIN3                  3U
#define GPIOG_PIN4                  4U
#define GPIOG_PIN5                  5U
#define GPIOG_USB_FS_PWR_EN         6U
#define GPIOG_USB_FS_OVCR           7U
#define GPIOG_PIN8                  8U
#define GPIOG_PIN9                  9U
#define GPIOG_PIN10                 10U
#define GPIOG_RMII_TX_EN            11U
#define GPIOG_PIN12                 12U
#define GPIOG_RMII_TXD0             13U
#define GPIOG_PIN14                 14U
#define GPIOG_PIN15                 15U

#define GPIOH_OSC_IN                0U
#define GPIOH_OSC_OUT               1U
#define GPIOH_PIN2                  2U
#define GPIOH_PIN3                  3U
#define GPIOH_PIN4                  4U
#define GPIOH_PIN5                  5U
#define GPIOH_PIN6                  6U
#define GPIOH_PIN7                  7U
#define GPIOH_PIN8                  8U
#define GPIOH_PIN9                  9U
#define GPIOH_PIN10                 10U
#define GPIOH_PIN11                 11U
#define GPIOH_PIN12                 12U
#define GPIOH_PIN13                 13U
#define GPIOH_PIN14                 14U
#define GPIOH_PIN15                 15U

#define GPIOI_PIN0                  0U
#define GPIOI_PIN1                  1U
#define GPIOI_PIN2                  2U
#define GPIOI_PIN3                  3U
#define GPIOI_PIN4                  4U
#define GPIOI_PIN5                  5U
#define GPIOI_PIN6                  6U
#define GPIOI_PIN7                  7U
#define GPIOI_PIN8                  8U
#define GPIOI_PIN9                  9U
#define GPIOI_PIN10                 10U
#define GPIOI_PIN11                 11U
#define GPIOI_PIN12                 12U
#define GPIOI_PIN13                 13U
#define GPIOI_PIN14                 14U
#define GPIOI_PIN15                 15U

#define GPIOJ_PIN0                  0U
#define GPIOJ_PIN1                  1U
#define GPIOJ_PIN2                  2U
#define GPIOJ_PIN3                  3U
#define GPIOJ_PIN4                  4U
#define GPIOJ_PIN5                  5U
#define GPIOJ_PIN6                  6U
#define GPIOJ_PIN7                  7U
#define GPIOJ_PIN8                  8U
#define GPIOJ_PIN9                  9U
#define GPIOJ_PIN10                 10U
#define GPIOJ_PIN11                 11U
#define GPIOJ_PIN12                 12U
#define GPIOJ_PIN13                 13U
#define GPIOJ_PIN14                 14U
#define GPIOJ_PIN15                 15U

#define GPIOK_PIN0                  0U
#define GPIOK_PIN1                  1U
#define GPIOK_PIN2                  2U
#define GPIOK_PIN3                  3U
#define GPIOK_PIN4                  4U
#define GPIOK_PIN5                  5U
#define GPIOK_PIN6                  6U
#define GPIOK_PIN7                  7U
#define GPIOK_PIN8                  8U
#define GPIOK_PIN9                  9U
#define GPIOK_PIN10                 10U
#define GPIOK_PIN11                 11U
#define GPIOK_PIN12                 12U
#define GPIOK_PIN13                 13U
#define GPIOK_PIN14                 14U
#define GPIOK_PIN15                 15U

/*
 * IO lines assignments.
 */
#define LINE_FMC_A0 PAL_LINE(GPIOF, 0U)
#define LINE_FMC_A1 PAL_LINE(GPIOF, 1U)
#define LINE_FMC_A10 PAL_LINE(GPIOG, 0U)
#define LINE_FMC_A11 PAL_LINE(GPIOG, 1U)
#define LINE_FMC_A12 PAL_LINE(GPIOG, 2U)
#define LINE_FMC_A14_BA0 PAL_LINE(GPIOG, 4U)
#define LINE_FMC_A15_BA1 PAL_LINE(GPIOG, 5U)
#define LINE_FMC_A2 PAL_LINE(GPIOF, 2U)
#define LINE_FMC_A3 PAL_LINE(GPIOF, 3U)
#define LINE_FMC_A4 PAL_LINE(GPIOF, 4U)
#define LINE_FMC_A5 PAL_LINE(GPIOF, 5U)
#define LINE_FMC_A6 PAL_LINE(GPIOF, 12U)
#define LINE_FMC_A7 PAL_LINE(GPIOF, 13U)
#define LINE_FMC_A8 PAL_LINE(GPIOF, 14U)
#define LINE_FMC_A9 PAL_LINE(GPIOF, 15U)
#define LINE_FMC_D0_DA0 PAL_LINE(GPIOD, 14U)
#define LINE_FMC_D10_DA10 PAL_LINE(GPIOE, 13U)
#define LINE_FMC_D11_DA11 PAL_LINE(GPIOE, 14U)
#define LINE_FMC_D12_DA12 PAL_LINE(GPIOE, 15U)
#define LINE_FMC_D13_DA13 PAL_LINE(GPIOD, 8U)
#define LINE_FMC_D14_DA14 PAL_LINE(GPIOD, 9U)
#define LINE_FMC_D15_DA15 PAL_LINE(GPIOD, 10U)
#define LINE_FMC_D1_DA1 PAL_LINE(GPIOD, 15U)
#define LINE_FMC_D2_DA2 PAL_LINE(GPIOD, 0U)
#define LINE_FMC_D3_DA3 PAL_LINE(GPIOD, 1U)
#define LINE_FMC_D4_DA4 PAL_LINE(GPIOE, 7U)
#define LINE_FMC_D5_DA5 PAL_LINE(GPIOE, 8U)
#define LINE_FMC_D6_DA6 PAL_LINE(GPIOE, 9U)
#define LINE_FMC_D7_DA7 PAL_LINE(GPIOE, 10U)
#define LINE_FMC_D8_DA8 PAL_LINE(GPIOE, 11U)
#define LINE_FMC_D9_DA9 PAL_LINE(GPIOE, 12U)
#define LINE_FMC_NBL0 PAL_LINE(GPIOE, 0U)
#define LINE_FMC_NBL1 PAL_LINE(GPIOE, 1U)
#define LINE_FMC_SDCKE0 PAL_LINE(GPIOH, 2U)
#define LINE_FMC_SDCLK PAL_LINE(GPIOG, 8U)
#define LINE_FMC_SDNCAS PAL_LINE(GPIOG, 15U)
#define LINE_FMC_SDNE0 PAL_LINE(GPIOH, 3U)
#define LINE_FMC_SDNRAS PAL_LINE(GPIOF, 11U)
#define LINE_FMC_SDNWE PAL_LINE(GPIOH, 5U)
#define LINE_LED PAL_LINE(GPIOC, 13U)
#define LINE_RCC_OSC_IN PAL_LINE(GPIOH, 0U)
#define LINE_RCC_OSC_OUT PAL_LINE(GPIOH, 1U)
#define LINE_USART1_RX PAL_LINE(GPIOA, 10U)
#define LINE_USART1_TX PAL_LINE(GPIOA, 9U)
#define PAD_FMC_A0 0
#define PAD_FMC_A1 1
#define PAD_FMC_A10 0
#define PAD_FMC_A11 1
#define PAD_FMC_A12 2
#define PAD_FMC_A14_BA0 4
#define PAD_FMC_A15_BA1 5
#define PAD_FMC_A2 2
#define PAD_FMC_A3 3
#define PAD_FMC_A4 4
#define PAD_FMC_A5 5
#define PAD_FMC_A6 12
#define PAD_FMC_A7 13
#define PAD_FMC_A8 14
#define PAD_FMC_A9 15
#define PAD_FMC_D0_DA0 14
#define PAD_FMC_D10_DA10 13
#define PAD_FMC_D11_DA11 14
#define PAD_FMC_D12_DA12 15
#define PAD_FMC_D13_DA13 8
#define PAD_FMC_D14_DA14 9
#define PAD_FMC_D15_DA15 10
#define PAD_FMC_D1_DA1 15
#define PAD_FMC_D2_DA2 0
#define PAD_FMC_D3_DA3 1
#define PAD_FMC_D4_DA4 7
#define PAD_FMC_D5_DA5 8
#define PAD_FMC_D6_DA6 9
#define PAD_FMC_D7_DA7 10
#define PAD_FMC_D8_DA8 11
#define PAD_FMC_D9_DA9 12
#define PAD_FMC_NBL0 0
#define PAD_FMC_NBL1 1
#define PAD_FMC_SDCKE0 2
#define PAD_FMC_SDCLK 8
#define PAD_FMC_SDNCAS 15
#define PAD_FMC_SDNE0 3
#define PAD_FMC_SDNRAS 11
#define PAD_FMC_SDNWE 5
#define PAD_LED 13
#define PAD_RCC_OSC_IN 0
#define PAD_RCC_OSC_OUT 1
#define PAD_USART1_RX 10
#define PAD_USART1_TX 9
#define PORT_FMC_A0 GPIOF
#define PORT_FMC_A1 GPIOF
#define PORT_FMC_A10 GPIOG
#define PORT_FMC_A11 GPIOG
#define PORT_FMC_A12 GPIOG
#define PORT_FMC_A14_BA0 GPIOG
#define PORT_FMC_A15_BA1 GPIOG
#define PORT_FMC_A2 GPIOF
#define PORT_FMC_A3 GPIOF
#define PORT_FMC_A4 GPIOF
#define PORT_FMC_A5 GPIOF
#define PORT_FMC_A6 GPIOF
#define PORT_FMC_A7 GPIOF
#define PORT_FMC_A8 GPIOF
#define PORT_FMC_A9 GPIOF
#define PORT_FMC_D0_DA0 GPIOD
#define PORT_FMC_D10_DA10 GPIOE
#define PORT_FMC_D11_DA11 GPIOE
#define PORT_FMC_D12_DA12 GPIOE
#define PORT_FMC_D13_DA13 GPIOD
#define PORT_FMC_D14_DA14 GPIOD
#define PORT_FMC_D15_DA15 GPIOD
#define PORT_FMC_D1_DA1 GPIOD
#define PORT_FMC_D2_DA2 GPIOD
#define PORT_FMC_D3_DA3 GPIOD
#define PORT_FMC_D4_DA4 GPIOE
#define PORT_FMC_D5_DA5 GPIOE
#define PORT_FMC_D6_DA6 GPIOE
#define PORT_FMC_D7_DA7 GPIOE
#define PORT_FMC_D8_DA8 GPIOE
#define PORT_FMC_D9_DA9 GPIOE
#define PORT_FMC_NBL0 GPIOE
#define PORT_FMC_NBL1 GPIOE
#define PORT_FMC_SDCKE0 GPIOH
#define PORT_FMC_SDCLK GPIOG
#define PORT_FMC_SDNCAS GPIOG
#define PORT_FMC_SDNE0 GPIOH
#define PORT_FMC_SDNRAS GPIOF
#define PORT_FMC_SDNWE GPIOH
#define PORT_LED GPIOC
#define PORT_RCC_OSC_IN GPIOH
#define PORT_RCC_OSC_OUT GPIOH
#define PORT_USART1_RX GPIOA
#define PORT_USART1_TX GPIOA
#define USART_USART1_RX 1
#define USART_USART1_TX 1

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2U))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2U))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2U))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2U))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_VERYLOW(n)       (0U << ((n) * 2U))
#define PIN_OSPEED_LOW(n)           (1U << ((n) * 2U))
#define PIN_OSPEED_MEDIUM(n)        (2U << ((n) * 2U))
#define PIN_OSPEED_HIGH(n)          (3U << ((n) * 2U))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2U))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2U))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2U))
#define PIN_AFIO_AF(n, v)           ((v) << (((n) % 8U) * 4U))

/*
 * GPIOA setup:
 *
 * PA0  - PIN0                      (input pullup).
 * PA1  - RMII_REF_CLK              (alternate 11).
 * PA2  - RMII_MDIO                 (alternate 11).
 * PA3  - PIN3                      (input pullup).
 * PA4  - PIN4                      (input pullup).
 * PA5  - PIN5                      (input pullup).
 * PA6  - PIN6                      (input pullup).
 * PA7  - RMII_CRS_DV               (alternate 11).
 * PA8  - USB_SOF MCO1              (alternate 10).
 * PA9  - USB_VBUS                  (analog).
 * PA10 - USB_ID                    (alternate 10).
 * PA11 - USB_DM                    (alternate 10).
 * PA12 - USB_DP                    (alternate 10).
 * PA13 - SWDIO                     (alternate 0).
 * PA14 - SWCLK                     (alternate 0).
 * PA15 - T_JTDI                    (alternate 0).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ANALOG(GPIOA_PIN0) |           \
                                     PIN_MODE_ANALOG(GPIOA_RMII_REF_CLK) |\
                                     PIN_MODE_ANALOG(GPIOA_RMII_MDIO) |  \
                                     PIN_MODE_INPUT(GPIOA_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOA_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOA_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOA_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOA_RMII_CRS_DV) |\
                                     PIN_MODE_ALTERNATE(GPIOA_USB_SOF) |    \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_VBUS) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_ID) |     \
                                     PIN_MODE_ANALOG(GPIOA_USB_DM) |     \
                                     PIN_MODE_ANALOG(GPIOA_USB_DP) |     \
                                     PIN_MODE_ALTERNATE(GPIOA_SWDIO) |      \
                                     PIN_MODE_ALTERNATE(GPIOA_SWCLK) |      \
                                     PIN_MODE_ANALOG(GPIOA_T_JTDI))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RMII_REF_CLK) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_RMII_MDIO) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RMII_CRS_DV) |\
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_SOF) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_VBUS) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_ID) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOA_T_JTDI))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOA_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_RMII_REF_CLK) |  \
                                     PIN_OSPEED_VERYLOW(GPIOA_RMII_MDIO) |     \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOA_RMII_CRS_DV) |   \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_SOF) |       \
                                     PIN_OSPEED_HIGH(GPIOA_USB_VBUS) |      \
                                     PIN_OSPEED_HIGH(GPIOA_USB_ID) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DM) |        \
                                     PIN_OSPEED_VERYLOW(GPIOA_USB_DP) |        \
                                     PIN_OSPEED_HIGH(GPIOA_SWDIO) |         \
                                     PIN_OSPEED_HIGH(GPIOA_SWCLK) |         \
                                     PIN_OSPEED_VERYLOW(GPIOA_T_JTDI))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_RMII_REF_CLK) |\
                                     PIN_PUPDR_FLOATING(GPIOA_RMII_MDIO) |    \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_RMII_CRS_DV) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_SOF) |    \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_VBUS) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_ID) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP) |     \
                                     PIN_PUPDR_FLOATING(GPIOA_SWDIO) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_SWCLK) |      \
                                     PIN_PUPDR_FLOATING(GPIOA_T_JTDI))
#define VAL_GPIOA_ODR               (PIN_ODR_LOW(GPIOA_PIN0) |             \
                                     PIN_ODR_LOW(GPIOA_RMII_REF_CLK) |     \
                                     PIN_ODR_LOW(GPIOA_RMII_MDIO) |        \
                                     PIN_ODR_LOW(GPIOA_PIN3) |             \
                                     PIN_ODR_LOW(GPIOA_PIN4) |             \
                                     PIN_ODR_LOW(GPIOA_PIN5) |             \
                                     PIN_ODR_LOW(GPIOA_PIN6) |             \
                                     PIN_ODR_LOW(GPIOA_RMII_CRS_DV) |      \
                                     PIN_ODR_LOW(GPIOA_USB_SOF) |          \
                                     PIN_ODR_LOW(GPIOA_USB_VBUS) |         \
                                     PIN_ODR_LOW(GPIOA_USB_ID) |           \
                                     PIN_ODR_LOW(GPIOA_USB_DM) |           \
                                     PIN_ODR_LOW(GPIOA_USB_DP) |           \
                                     PIN_ODR_LOW(GPIOA_SWDIO) |            \
                                     PIN_ODR_LOW(GPIOA_SWCLK) |            \
                                     PIN_ODR_LOW(GPIOA_T_JTDI))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_RMII_REF_CLK, 0U) | \
                                     PIN_AFIO_AF(GPIOA_RMII_MDIO, 0U) |    \
                                     PIN_AFIO_AF(GPIOA_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOA_RMII_CRS_DV, 0U))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_USB_SOF, 13U) |      \
                                     PIN_AFIO_AF(GPIOA_USB_VBUS, 7U) |      \
                                     PIN_AFIO_AF(GPIOA_USB_ID, 7U) |       \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 0U) |       \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 0U) |       \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0U) |         \
                                     PIN_AFIO_AF(GPIOA_T_JTDI, 0U))

/*
 * GPIOB setup:
 *
 * PB0  - LED1 LED_GREEN LED        (output pushpull maximum).
 * PB1  - PIN1                      (input pullup).
 * PB2  - PIN2                      (input pullup).
 * PB3  - SWO                       (alternate 0).
 * PB4  - PIN4                      (input pullup).
 * PB5  - PIN5                      (input pullup).
 * PB6  - PIN6                      (input pullup).
 * PB7  - LED2 LED_BLUE             (output pushpull maximum).
 * PB8  - PIN8                      (input pullup).
 * PB9  - PIN9                      (input pullup).
 * PB10 - PIN10                     (input pullup).
 * PB11 - PIN11                     (input pullup).
 * PB12 - PIN12                     (input pullup).
 * PB13 - RMII_TXD1                 (alternate 11).
 * PB14 - LED3 LED_RED              (output pushpull maximum).
 * PB15 - PIN15                     (input pullup).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ANALOG(GPIOB_LED1) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN1) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOB_SWO) |        \
                                     PIN_MODE_ANALOG(GPIOB_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOB_LED2) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN9) |           \
                                     PIN_MODE_ANALOG(GPIOB_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOB_RMII_TXD1) |  \
                                     PIN_MODE_ANALOG(GPIOB_LED3) |          \
                                     PIN_MODE_ANALOG(GPIOB_PIN15))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_LED1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SWO) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RMII_TXD1) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_LED3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_PIN15))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOB_LED1) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_SWO) |           \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_LED2) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOB_RMII_TXD1) |     \
                                     PIN_OSPEED_VERYLOW(GPIOB_LED3) |          \
                                     PIN_OSPEED_VERYLOW(GPIOB_PIN15))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_LED1) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_SWO) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_LED2) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_RMII_TXD1) |    \
                                     PIN_PUPDR_FLOATING(GPIOB_LED3) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_PIN15))
#define VAL_GPIOB_ODR               (PIN_ODR_LOW(GPIOB_LED1) |              \
                                     PIN_ODR_LOW(GPIOB_PIN1) |             \
                                     PIN_ODR_LOW(GPIOB_PIN2) |             \
                                     PIN_ODR_LOW(GPIOB_SWO) |              \
                                     PIN_ODR_LOW(GPIOB_PIN4) |             \
                                     PIN_ODR_LOW(GPIOB_PIN5) |             \
                                     PIN_ODR_LOW(GPIOB_PIN6) |             \
                                     PIN_ODR_LOW(GPIOB_LED2) |              \
                                     PIN_ODR_LOW(GPIOB_PIN8) |             \
                                     PIN_ODR_LOW(GPIOB_PIN9) |             \
                                     PIN_ODR_LOW(GPIOB_PIN10) |            \
                                     PIN_ODR_LOW(GPIOB_PIN11) |            \
                                     PIN_ODR_LOW(GPIOB_PIN12) |            \
                                     PIN_ODR_LOW(GPIOB_RMII_TXD1) |        \
                                     PIN_ODR_LOW(GPIOB_LED3) |              \
                                     PIN_ODR_LOW(GPIOB_PIN15))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_LED1, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_SWO, 0U) |           \
                                     PIN_AFIO_AF(GPIOB_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_LED2, 0U))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOB_RMII_TXD1, 0U) |    \
                                     PIN_AFIO_AF(GPIOB_LED3, 0U) |          \
                                     PIN_AFIO_AF(GPIOB_PIN15, 0U))

/*
 * GPIOC setup:
 *
 * PC0  - PIN0                      (input pullup).
 * PC1  - RMII_MDC                  (alternate 11).
 * PC2  - PIN2                      (input pullup).
 * PC3  - PIN3                      (input pullup).
 * PC4  - RMII_RXD0                 (alternate 11).
 * PC5  - RMII_RXD1                 (alternate 11).
 * PC6  - PIN6                      (input pullup).
 * PC7  - PIN7                      (input pullup).
 * PC8  - PIN8                      (input pullup).
 * PC9  - PIN9                      (input pullup).
 * PC10 - PIN10                     (input pullup).
 * PC11 - PIN11                     (input pullup).
 * PC12 - PIN12                     (input pullup).
 * PC13 - BUTTON                    (input floating).
 * PC14 - OSC32_IN                  (input floating).
 * PC15 - OSC32_OUT                 (input floating).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ANALOG(GPIOC_PIN0) |           \
                                     PIN_MODE_ANALOG(GPIOC_RMII_MDC) |   \
                                     PIN_MODE_ANALOG(GPIOC_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOC_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOC_RMII_RXD0) |  \
                                     PIN_MODE_ANALOG(GPIOC_RMII_RXD1) |  \
                                     PIN_MODE_ANALOG(GPIOC_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOC_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOC_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOC_PIN9) |           \
                                     PIN_MODE_ANALOG(GPIOC_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOC_PIN12) |          \
                                     PIN_MODE_OUTPUT(GPIOC_BUTTON) |         \
                                     PIN_MODE_ANALOG(GPIOC_OSC32_IN) |       \
                                     PIN_MODE_ANALOG(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RMII_MDC) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RMII_RXD0) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_RMII_RXD1) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BUTTON) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_IN) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOC_OSC32_OUT))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOC_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_RMII_MDC) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_RMII_RXD0) |     \
                                     PIN_OSPEED_VERYLOW(GPIOC_RMII_RXD1) |     \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOC_BUTTON) |        \
                                     PIN_OSPEED_VERYLOW(GPIOC_OSC32_IN) |   \
                                     PIN_OSPEED_VERYLOW(GPIOC_OSC32_OUT))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_FLOATING(GPIOC_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_RMII_MDC) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_RMII_RXD0) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_RMII_RXD1) |  \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOC_BUTTON) |     \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_IN) |   \
                                     PIN_PUPDR_FLOATING(GPIOC_OSC32_OUT))
#define VAL_GPIOC_ODR               (PIN_ODR_LOW(GPIOC_PIN0) |             \
                                     PIN_ODR_LOW(GPIOC_RMII_MDC) |         \
                                     PIN_ODR_LOW(GPIOC_PIN2) |             \
                                     PIN_ODR_LOW(GPIOC_PIN3) |             \
                                     PIN_ODR_LOW(GPIOC_RMII_RXD0) |        \
                                     PIN_ODR_LOW(GPIOC_RMII_RXD1) |        \
                                     PIN_ODR_LOW(GPIOC_PIN6) |             \
                                     PIN_ODR_LOW(GPIOC_PIN7) |             \
                                     PIN_ODR_LOW(GPIOC_PIN8) |             \
                                     PIN_ODR_LOW(GPIOC_PIN9) |             \
                                     PIN_ODR_LOW(GPIOC_PIN10) |            \
                                     PIN_ODR_LOW(GPIOC_PIN11) |            \
                                     PIN_ODR_LOW(GPIOC_PIN12) |            \
                                     PIN_ODR_LOW(GPIOC_BUTTON) |           \
                                     PIN_ODR_LOW(GPIOC_OSC32_IN) |         \
                                     PIN_ODR_LOW(GPIOC_OSC32_OUT))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_RMII_MDC, 0U) |     \
                                     PIN_AFIO_AF(GPIOC_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_RMII_RXD0, 0U) |    \
                                     PIN_AFIO_AF(GPIOC_RMII_RXD1, 0U) |    \
                                     PIN_AFIO_AF(GPIOC_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN7, 0U))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOC_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOC_BUTTON, 0U) |        \
                                     PIN_AFIO_AF(GPIOC_OSC32_IN, 0U) |      \
                                     PIN_AFIO_AF(GPIOC_OSC32_OUT, 0U))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input pullup).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PIN2                      (input pullup).
 * PD3  - PIN3                      (input pullup).
 * PD4  - PIN4                      (input pullup).
 * PD5  - PIN5                      (input pullup).
 * PD6  - PIN6                      (input pullup).
 * PD7  - PIN7                      (input pullup).
 * PD8  - USART3_RX STLK_RX         (alternate 7).
 * PD9  - USART3_TX STLK_TX         (alternate 7).
 * PD10 - PIN10                     (input pullup).
 * PD11 - PIN11                     (input pullup).
 * PD12 - PIN12                     (input pullup).
 * PD13 - PIN13                     (input pullup).
 * PD14 - PIN14                     (input pullup).
 * PD15 - PIN15                     (input pullup).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_ALTERNATE(GPIOD_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOD_PIN1) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOD_PIN7) |           \
                                     PIN_MODE_ALTERNATE(GPIOD_USART3_RX) |  \
                                     PIN_MODE_ALTERNATE(GPIOD_USART3_TX) |  \
                                     PIN_MODE_ALTERNATE(GPIOD_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOD_PIN13) |          \
                                     PIN_MODE_ALTERNATE(GPIOD_PIN14) |          \
                                     PIN_MODE_ALTERNATE(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART3_RX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_USART3_TX) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_HIGH(GPIOD_PIN0) |       \
                                     PIN_OSPEED_HIGH(GPIOD_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN7) |       \
                                     PIN_OSPEED_HIGH(GPIOD_USART3_RX) |     \
                                     PIN_OSPEED_HIGH(GPIOD_USART3_TX) |     \
                                     PIN_OSPEED_HIGH(GPIOD_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOD_PIN13) |      \
                                     PIN_OSPEED_HIGH(GPIOD_PIN14) |      \
                                     PIN_OSPEED_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_FLOATING(GPIOD_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOD_USART3_RX) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_USART3_TX) |  \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_LOW(GPIOD_PIN0) |             \
                                     PIN_ODR_LOW(GPIOD_PIN1) |             \
                                     PIN_ODR_LOW(GPIOD_PIN2) |             \
                                     PIN_ODR_LOW(GPIOD_PIN3) |             \
                                     PIN_ODR_LOW(GPIOD_PIN4) |             \
                                     PIN_ODR_LOW(GPIOD_PIN5) |             \
                                     PIN_ODR_LOW(GPIOD_PIN6) |             \
                                     PIN_ODR_LOW(GPIOD_PIN7) |             \
                                     PIN_ODR_LOW(GPIOD_USART3_RX) |        \
                                     PIN_ODR_LOW(GPIOD_USART3_TX) |        \
                                     PIN_ODR_LOW(GPIOD_PIN10) |            \
                                     PIN_ODR_LOW(GPIOD_PIN11) |            \
                                     PIN_ODR_LOW(GPIOD_PIN12) |            \
                                     PIN_ODR_LOW(GPIOD_PIN13) |            \
                                     PIN_ODR_LOW(GPIOD_PIN14) |            \
                                     PIN_ODR_LOW(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 12U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN1, 12U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0U))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_USART3_RX, 12U) |     \
                                     PIN_AFIO_AF(GPIOD_USART3_TX, 12U) |     \
                                     PIN_AFIO_AF(GPIOD_PIN10, 12U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN14, 12U) |         \
                                     PIN_AFIO_AF(GPIOD_PIN15, 12U))

/*
 * GPIOE setup:
 *
 * PE0  - PIN0                      (input pullup).
 * PE1  - PIN1                      (input pullup).
 * PE2  - PIN2                      (input pullup).
 * PE3  - PIN3                      (input pullup).
 * PE4  - PIN4                      (input pullup).
 * PE5  - PIN5                      (input pullup).
 * PE6  - PIN6                      (input pullup).
 * PE7  - PIN7                      (input pullup).
 * PE8  - PIN8                      (input pullup).
 * PE9  - PIN9                      (input pullup).
 * PE10 - PIN10                     (input pullup).
 * PE11 - PIN11                     (input pullup).
 * PE12 - PIN12                     (input pullup).
 * PE13 - PIN13                     (input pullup).
 * PE14 - PIN14                     (input pullup).
 * PE15 - PIN15                     (input pullup).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_ALTERNATE(GPIOE_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN1) |           \
                                     PIN_MODE_ANALOG(GPIOE_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOE_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOE_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOE_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOE_PIN6) |           \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN7) |           \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN8) |           \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN10) |          \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN11) |          \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN12) |          \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN13) |          \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN14) |          \
                                     PIN_MODE_ALTERNATE(GPIOE_PIN15))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN15))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_HIGH(GPIOE_PIN0) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOE_PIN6) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN7) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN8) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN9) |       \
                                     PIN_OSPEED_HIGH(GPIOE_PIN10) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN11) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN12) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN13) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN14) |      \
                                     PIN_OSPEED_HIGH(GPIOE_PIN15))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_FLOATING(GPIOE_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOE_PIN15))
#define VAL_GPIOE_ODR               (PIN_ODR_LOW(GPIOE_PIN0) |             \
                                     PIN_ODR_LOW(GPIOE_PIN1) |             \
                                     PIN_ODR_LOW(GPIOE_PIN2) |             \
                                     PIN_ODR_LOW(GPIOE_PIN3) |             \
                                     PIN_ODR_LOW(GPIOE_PIN4) |             \
                                     PIN_ODR_LOW(GPIOE_PIN5) |             \
                                     PIN_ODR_LOW(GPIOE_PIN6) |             \
                                     PIN_ODR_LOW(GPIOE_PIN7) |             \
                                     PIN_ODR_LOW(GPIOE_PIN8) |             \
                                     PIN_ODR_LOW(GPIOE_PIN9) |             \
                                     PIN_ODR_LOW(GPIOE_PIN10) |            \
                                     PIN_ODR_LOW(GPIOE_PIN11) |            \
                                     PIN_ODR_LOW(GPIOE_PIN12) |            \
                                     PIN_ODR_LOW(GPIOE_PIN13) |            \
                                     PIN_ODR_LOW(GPIOE_PIN14) |            \
                                     PIN_ODR_LOW(GPIOE_PIN15))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_PIN0, 12U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN1, 12U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN7, 12U))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_PIN8, 12U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN9, 12U) |          \
                                     PIN_AFIO_AF(GPIOE_PIN10, 12U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN11, 12U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN12, 12U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN13, 12U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN14, 12U) |         \
                                     PIN_AFIO_AF(GPIOE_PIN15, 12U))

/*
 * GPIOF setup:
 *
 * PF0  - PIN0                      (input pullup).
 * PF1  - PIN1                      (input pullup).
 * PF2  - PIN2                      (input pullup).
 * PF3  - PIN3                      (input pullup).
 * PF4  - PIN4                      (input pullup).
 * PF5  - PIN5                      (input pullup).
 * PF6  - PIN6                      (input pullup).
 * PF7  - PIN7                      (input pullup).
 * PF8  - PIN8                      (input pullup).
 * PF9  - PIN9                      (input pullup).
 * PF10 - PIN10                     (input pullup).
 * PF11 - PIN11                     (input pullup).
 * PF12 - PIN12                     (input pullup).
 * PF13 - PIN13                     (input pullup).
 * PF14 - PIN14                     (input pullup).
 * PF15 - PIN15                     (input pullup).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_ALTERNATE(GPIOF_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN1) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN2) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN3) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN4) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOF_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOF_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOF_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOF_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN10) |          \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN11) |          \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN12) |          \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN13) |          \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN14) |          \
                                     PIN_MODE_ALTERNATE(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_HIGH(GPIOF_PIN0) |       \
                                     PIN_OSPEED_HIGH(GPIOF_PIN1) |       \
                                     PIN_OSPEED_HIGH(GPIOF_PIN2) |       \
                                     PIN_OSPEED_HIGH(GPIOF_PIN3) |       \
                                     PIN_OSPEED_HIGH(GPIOF_PIN4) |       \
                                     PIN_OSPEED_HIGH(GPIOF_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOF_PIN10) |      \
                                     PIN_OSPEED_HIGH(GPIOF_PIN11) |      \
                                     PIN_OSPEED_HIGH(GPIOF_PIN12) |      \
                                     PIN_OSPEED_HIGH(GPIOF_PIN13) |      \
                                     PIN_OSPEED_HIGH(GPIOF_PIN14) |      \
                                     PIN_OSPEED_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_LOW(GPIOF_PIN0) |             \
                                     PIN_ODR_LOW(GPIOF_PIN1) |             \
                                     PIN_ODR_LOW(GPIOF_PIN2) |             \
                                     PIN_ODR_LOW(GPIOF_PIN3) |             \
                                     PIN_ODR_LOW(GPIOF_PIN4) |             \
                                     PIN_ODR_LOW(GPIOF_PIN5) |             \
                                     PIN_ODR_LOW(GPIOF_PIN6) |             \
                                     PIN_ODR_LOW(GPIOF_PIN7) |             \
                                     PIN_ODR_LOW(GPIOF_PIN8) |             \
                                     PIN_ODR_LOW(GPIOF_PIN9) |             \
                                     PIN_ODR_LOW(GPIOF_PIN10) |            \
                                     PIN_ODR_LOW(GPIOF_PIN11) |            \
                                     PIN_ODR_LOW(GPIOF_PIN12) |            \
                                     PIN_ODR_LOW(GPIOF_PIN13) |            \
                                     PIN_ODR_LOW(GPIOF_PIN14) |            \
                                     PIN_ODR_LOW(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_PIN0, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN1, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN2, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN3, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN4, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN5, 12U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0U))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOF_PIN10, 14U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN11, 12U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN12, 12U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN13, 12U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN14, 12U) |         \
                                     PIN_AFIO_AF(GPIOF_PIN15, 12U))

/*
 * GPIOG setup:
 *
 * PG0  - PIN0                      (input pullup).
 * PG1  - PIN1                      (input pullup).
 * PG2  - PIN2                      (input pullup).
 * PG3  - PIN3                      (input pullup).
 * PG4  - PIN4                      (input pullup).
 * PG5  - PIN5                      (input pullup).
 * PG6  - USB_FS_PWR_EN             (output pushpull minimum).
 * PG7  - USB_FS_OVCR               (input floating).
 * PG8  - PIN8                      (input pullup).
 * PG9  - PIN9                      (input pullup).
 * PG10 - PIN10                     (input pullup).
 * PG11 - RMII_TX_EN                (alternate 11).
 * PG12 - PIN12                     (input pullup).
 * PG13 - RMII_TXD0                 (alternate 11).
 * PG14 - PIN14                     (input pullup).
 * PG15 - PIN15                     (input pullup).
 */
#define VAL_GPIOG_MODER             (PIN_MODE_ALTERNATE(GPIOG_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN1) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOG_PIN3) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN4) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN5) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_USB_FS_PWR_EN) | \
                                     PIN_MODE_ALTERNATE(GPIOG_USB_FS_OVCR) |    \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOG_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOG_RMII_TX_EN) | \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOG_RMII_TXD0) |  \
                                     PIN_MODE_ANALOG(GPIOG_PIN14) |          \
                                     PIN_MODE_ALTERNATE(GPIOG_PIN15))
#define VAL_GPIOG_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOG_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_USB_FS_PWR_EN) |\
                                     PIN_OTYPE_PUSHPULL(GPIOG_USB_FS_OVCR) |\
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_RMII_TX_EN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_RMII_TXD0) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOG_PIN15))
#define VAL_GPIOG_OSPEEDR           (PIN_OSPEED_HIGH(GPIOG_PIN0) |       \
                                     PIN_OSPEED_HIGH(GPIOG_PIN1) |       \
                                     PIN_OSPEED_HIGH(GPIOG_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN3) |       \
                                     PIN_OSPEED_HIGH(GPIOG_PIN4) |       \
                                     PIN_OSPEED_HIGH(GPIOG_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_USB_FS_PWR_EN) |\
                                     PIN_OSPEED_VERYLOW(GPIOG_USB_FS_OVCR) |\
                                     PIN_OSPEED_HIGH(GPIOG_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_RMII_TX_EN) |    \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOG_RMII_TXD0) |     \
                                     PIN_OSPEED_VERYLOW(GPIOG_PIN14) |      \
                                     PIN_OSPEED_HIGH(GPIOG_PIN15))
#define VAL_GPIOG_PUPDR             (PIN_PUPDR_FLOATING(GPIOG_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_USB_FS_PWR_EN) |\
                                     PIN_PUPDR_FLOATING(GPIOG_USB_FS_OVCR) |\
                                     PIN_PUPDR_FLOATING(GPIOG_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOG_RMII_TX_EN) | \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOG_RMII_TXD0) |  \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOG_PIN15))
#define VAL_GPIOG_ODR               (PIN_ODR_LOW(GPIOG_PIN0) |             \
                                     PIN_ODR_LOW(GPIOG_PIN1) |             \
                                     PIN_ODR_LOW(GPIOG_PIN2) |             \
                                     PIN_ODR_LOW(GPIOG_PIN3) |             \
                                     PIN_ODR_LOW(GPIOG_PIN4) |             \
                                     PIN_ODR_LOW(GPIOG_PIN5) |             \
                                     PIN_ODR_LOW(GPIOG_USB_FS_PWR_EN) |     \
                                     PIN_ODR_LOW(GPIOG_USB_FS_OVCR) |      \
                                     PIN_ODR_LOW(GPIOG_PIN8) |             \
                                     PIN_ODR_LOW(GPIOG_PIN9) |             \
                                     PIN_ODR_LOW(GPIOG_PIN10) |            \
                                     PIN_ODR_LOW(GPIOG_RMII_TX_EN) |       \
                                     PIN_ODR_LOW(GPIOG_PIN12) |            \
                                     PIN_ODR_LOW(GPIOG_RMII_TXD0) |        \
                                     PIN_ODR_LOW(GPIOG_PIN14) |            \
                                     PIN_ODR_LOW(GPIOG_PIN15))
#define VAL_GPIOG_AFRL              (PIN_AFIO_AF(GPIOG_PIN0, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN1, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN2, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN4, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN5, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_USB_FS_PWR_EN, 14U) | \
                                     PIN_AFIO_AF(GPIOG_USB_FS_OVCR, 14U))
#define VAL_GPIOG_AFRH              (PIN_AFIO_AF(GPIOG_PIN8, 12U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOG_PIN10, 9U) |         \
                                     PIN_AFIO_AF(GPIOG_RMII_TX_EN, 0U) |   \
                                     PIN_AFIO_AF(GPIOG_PIN12, 9U) |         \
                                     PIN_AFIO_AF(GPIOG_RMII_TXD0, 0U) |    \
                                     PIN_AFIO_AF(GPIOG_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOG_PIN15, 12U))

/*
 * GPIOH setup:
 *
 * PH0  - OSC_IN                    (input floating).
 * PH1  - OSC_OUT                   (input floating).
 * PH2  - PIN2                      (input pullup).
 * PH3  - PIN3                      (input pullup).
 * PH4  - PIN4                      (input pullup).
 * PH5  - PIN5                      (input pullup).
 * PH6  - PIN6                      (input pullup).
 * PH7  - PIN7                      (input pullup).
 * PH8  - PIN8                      (input pullup).
 * PH9  - PIN9                      (input pullup).
 * PH10 - PIN10                     (input pullup).
 * PH11 - PIN11                     (input pullup).
 * PH12 - PIN12                     (input pullup).
 * PH13 - PIN13                     (input pullup).
 * PH14 - PIN14                     (input pullup).
 * PH15 - PIN15                     (input pullup).
 */
#define VAL_GPIOH_MODER             (PIN_MODE_ANALOG(GPIOH_OSC_IN) |         \
                                     PIN_MODE_ANALOG(GPIOH_OSC_OUT) |        \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN2) |           \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOH_PIN4) |           \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN5) |           \
                                     PIN_MODE_OUTPUT(GPIOH_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOH_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOH_PIN8) |           \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN10) |          \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN11) |          \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN12) |          \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN13) |          \
                                     PIN_MODE_ANALOG(GPIOH_PIN14) |          \
                                     PIN_MODE_ALTERNATE(GPIOH_PIN15))
#define VAL_GPIOH_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOH_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOH_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOH_PIN15))
#define VAL_GPIOH_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOH_OSC_IN) |        \
                                     PIN_OSPEED_VERYLOW(GPIOH_OSC_OUT) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN2) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN4) |       \
                                     PIN_OSPEED_HIGH(GPIOH_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOH_PIN15))
#define VAL_GPIOH_PUPDR             (PIN_PUPDR_FLOATING(GPIOH_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOH_OSC_OUT) |    \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOH_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOH_PIN15))
#define VAL_GPIOH_ODR               (PIN_ODR_LOW(GPIOH_OSC_IN) |           \
                                     PIN_ODR_LOW(GPIOH_OSC_OUT) |          \
                                     PIN_ODR_LOW(GPIOH_PIN2) |             \
                                     PIN_ODR_LOW(GPIOH_PIN3) |             \
                                     PIN_ODR_LOW(GPIOH_PIN4) |             \
                                     PIN_ODR_LOW(GPIOH_PIN5) |             \
                                     PIN_ODR_LOW(GPIOH_PIN6) |             \
                                     PIN_ODR_LOW(GPIOH_PIN7) |             \
                                     PIN_ODR_LOW(GPIOH_PIN8) |             \
                                     PIN_ODR_LOW(GPIOH_PIN9) |             \
                                     PIN_ODR_LOW(GPIOH_PIN10) |            \
                                     PIN_ODR_LOW(GPIOH_PIN11) |            \
                                     PIN_ODR_LOW(GPIOH_PIN12) |            \
                                     PIN_ODR_LOW(GPIOH_PIN13) |            \
                                     PIN_ODR_LOW(GPIOH_PIN14) |            \
                                     PIN_ODR_LOW(GPIOH_PIN15))
#define VAL_GPIOH_AFRL              (PIN_AFIO_AF(GPIOH_OSC_IN, 0U) |        \
                                     PIN_AFIO_AF(GPIOH_OSC_OUT, 0U) |       \
                                     PIN_AFIO_AF(GPIOH_PIN2, 12U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN3, 12U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN5, 12U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN7, 0U))
#define VAL_GPIOH_AFRH              (PIN_AFIO_AF(GPIOH_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN9, 14U) |          \
                                     PIN_AFIO_AF(GPIOH_PIN10, 14U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN11, 14U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN12, 14U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN13, 14U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOH_PIN15, 14U))

/*
 * GPIOI setup:
 *
 * PI0  - PIN0                      (input pullup).
 * PI1  - PIN1                      (input pullup).
 * PI2  - PIN2                      (input pullup).
 * PI3  - PIN3                      (input pullup).
 * PI4  - PIN4                      (input pullup).
 * PI5  - PIN5                      (input pullup).
 * PI6  - PIN6                      (input pullup).
 * PI7  - PIN7                      (input pullup).
 * PI8  - PIN8                      (input pullup).
 * PI9  - PIN9                      (input pullup).
 * PI10 - PIN10                     (input pullup).
 * PI11 - PIN11                     (input pullup).
 * PI12 - PIN12                     (input pullup).
 * PI13 - PIN13                     (input pullup).
 * PI14 - PIN14                     (input pullup).
 * PI15 - PIN15                     (input pullup).
 */
#define VAL_GPIOI_MODER             (PIN_MODE_ALTERNATE(GPIOI_PIN0) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN1) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOI_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOI_PIN4) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN5) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN6) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOI_PIN8) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN9) |           \
                                     PIN_MODE_ALTERNATE(GPIOI_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN13) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN14) |          \
                                     PIN_MODE_ANALOG(GPIOI_PIN15))
#define VAL_GPIOI_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOI_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOI_PIN15))
#define VAL_GPIOI_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOI_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOI_PIN15))
#define VAL_GPIOI_PUPDR             (PIN_PUPDR_FLOATING(GPIOI_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOI_PIN15))
#define VAL_GPIOI_ODR               (PIN_ODR_LOW(GPIOI_PIN0) |             \
                                     PIN_ODR_LOW(GPIOI_PIN1) |             \
                                     PIN_ODR_LOW(GPIOI_PIN2) |             \
                                     PIN_ODR_LOW(GPIOI_PIN3) |             \
                                     PIN_ODR_LOW(GPIOI_PIN4) |             \
                                     PIN_ODR_LOW(GPIOI_PIN5) |             \
                                     PIN_ODR_LOW(GPIOI_PIN6) |             \
                                     PIN_ODR_LOW(GPIOI_PIN7) |             \
                                     PIN_ODR_LOW(GPIOI_PIN8) |             \
                                     PIN_ODR_LOW(GPIOI_PIN9) |             \
                                     PIN_ODR_LOW(GPIOI_PIN10) |            \
                                     PIN_ODR_LOW(GPIOI_PIN11) |            \
                                     PIN_ODR_LOW(GPIOI_PIN12) |            \
                                     PIN_ODR_LOW(GPIOI_PIN13) |            \
                                     PIN_ODR_LOW(GPIOI_PIN14) |            \
                                     PIN_ODR_LOW(GPIOI_PIN15))
#define VAL_GPIOI_AFRL              (PIN_AFIO_AF(GPIOI_PIN0, 14U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN1, 14U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN2, 14U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN5, 14U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN6, 15U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN7, 14U))
#define VAL_GPIOI_AFRH              (PIN_AFIO_AF(GPIOI_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN9, 14U) |          \
                                     PIN_AFIO_AF(GPIOI_PIN10, 14U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOI_PIN15, 0U))

/*
 * GPIOJ setup:
 *
 * PJ0  - PIN0                      (input pullup).
 * PJ1  - PIN1                      (input pullup).
 * PJ2  - PIN2                      (input pullup).
 * PJ3  - PIN3                      (input pullup).
 * PJ4  - PIN4                      (input pullup).
 * PJ5  - PIN5                      (input pullup).
 * PJ6  - PIN6                      (input pullup).
 * PJ7  - PIN7                      (input pullup).
 * PJ8  - PIN8                      (input pullup).
 * PJ9  - PIN9                      (input pullup).
 * PJ10 - PIN10                     (input pullup).
 * PJ11 - PIN11                     (input pullup).
 * PJ12 - PIN12                     (input pullup).
 * PJ13 - PIN13                     (input pullup).
 * PJ14 - PIN14                     (input pullup).
 * PJ15 - PIN15                     (input pullup).
 */
#define VAL_GPIOJ_MODER             (PIN_MODE_ANALOG(GPIOJ_PIN0) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN1) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN9) |           \
                                     PIN_MODE_ANALOG(GPIOJ_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOJ_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOJ_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOJ_PIN13) |          \
                                     PIN_MODE_ANALOG(GPIOJ_PIN14) |          \
                                     PIN_MODE_ANALOG(GPIOJ_PIN15))
#define VAL_GPIOJ_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOJ_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOJ_PIN15))
#define VAL_GPIOJ_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOJ_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOJ_PIN15))
#define VAL_GPIOJ_PUPDR             (PIN_PUPDR_FLOATING(GPIOJ_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOJ_PIN15))
#define VAL_GPIOJ_ODR               (PIN_ODR_LOW(GPIOJ_PIN0) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN1) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN2) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN3) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN4) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN5) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN6) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN7) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN8) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN9) |             \
                                     PIN_ODR_LOW(GPIOJ_PIN10) |            \
                                     PIN_ODR_LOW(GPIOJ_PIN11) |            \
                                     PIN_ODR_LOW(GPIOJ_PIN12) |            \
                                     PIN_ODR_LOW(GPIOJ_PIN13) |            \
                                     PIN_ODR_LOW(GPIOJ_PIN14) |            \
                                     PIN_ODR_LOW(GPIOJ_PIN15))
#define VAL_GPIOJ_AFRL              (PIN_AFIO_AF(GPIOJ_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN7, 0U))
#define VAL_GPIOJ_AFRH              (PIN_AFIO_AF(GPIOJ_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOJ_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOJ_PIN15, 0U))

/*
 * GPIOK setup:
 *
 * PK0  - PIN0                      (input pullup).
 * PK1  - PIN1                      (input pullup).
 * PK2  - PIN2                      (input pullup).
 * PK3  - PIN3                      (input pullup).
 * PK4  - PIN4                      (input pullup).
 * PK5  - PIN5                      (input pullup).
 * PK6  - PIN6                      (input pullup).
 * PK7  - PIN7                      (input pullup).
 * PK8  - PIN8                      (input pullup).
 * PK9  - PIN9                      (input pullup).
 * PK10 - PIN10                     (input pullup).
 * PK11 - PIN11                     (input pullup).
 * PK12 - PIN12                     (input pullup).
 * PK13 - PIN13                     (input pullup).
 * PK14 - PIN14                     (input pullup).
 * PK15 - PIN15                     (input pullup).
 */
#define VAL_GPIOK_MODER             (PIN_MODE_ANALOG(GPIOK_PIN0) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN1) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN2) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN3) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN4) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN5) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN6) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN7) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN8) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN9) |           \
                                     PIN_MODE_ANALOG(GPIOK_PIN10) |          \
                                     PIN_MODE_ANALOG(GPIOK_PIN11) |          \
                                     PIN_MODE_ANALOG(GPIOK_PIN12) |          \
                                     PIN_MODE_ANALOG(GPIOK_PIN13) |          \
                                     PIN_MODE_ANALOG(GPIOK_PIN14) |          \
                                     PIN_MODE_ANALOG(GPIOK_PIN15))
#define VAL_GPIOK_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOK_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOK_PIN15))
#define VAL_GPIOK_OSPEEDR           (PIN_OSPEED_VERYLOW(GPIOK_PIN0) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN1) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN2) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN3) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN4) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN5) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN6) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN7) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN8) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN9) |       \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN10) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN11) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN12) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN13) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN14) |      \
                                     PIN_OSPEED_VERYLOW(GPIOK_PIN15))
#define VAL_GPIOK_PUPDR             (PIN_PUPDR_FLOATING(GPIOK_PIN0) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN1) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN2) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN3) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN4) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN5) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN6) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN7) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN8) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN9) |         \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN10) |        \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN11) |        \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN12) |        \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN13) |        \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN14) |        \
                                     PIN_PUPDR_FLOATING(GPIOK_PIN15))
#define VAL_GPIOK_ODR               (PIN_ODR_LOW(GPIOK_PIN0) |             \
                                     PIN_ODR_LOW(GPIOK_PIN1) |             \
                                     PIN_ODR_LOW(GPIOK_PIN2) |             \
                                     PIN_ODR_LOW(GPIOK_PIN3) |             \
                                     PIN_ODR_LOW(GPIOK_PIN4) |             \
                                     PIN_ODR_LOW(GPIOK_PIN5) |             \
                                     PIN_ODR_LOW(GPIOK_PIN6) |             \
                                     PIN_ODR_LOW(GPIOK_PIN7) |             \
                                     PIN_ODR_LOW(GPIOK_PIN8) |             \
                                     PIN_ODR_LOW(GPIOK_PIN9) |             \
                                     PIN_ODR_LOW(GPIOK_PIN10) |            \
                                     PIN_ODR_LOW(GPIOK_PIN11) |            \
                                     PIN_ODR_LOW(GPIOK_PIN12) |            \
                                     PIN_ODR_LOW(GPIOK_PIN13) |            \
                                     PIN_ODR_LOW(GPIOK_PIN14) |            \
                                     PIN_ODR_LOW(GPIOK_PIN15))
#define VAL_GPIOK_AFRL              (PIN_AFIO_AF(GPIOK_PIN0, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN1, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN2, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN3, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN4, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN5, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN6, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN7, 0U))
#define VAL_GPIOK_AFRH              (PIN_AFIO_AF(GPIOK_PIN8, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN9, 0U) |          \
                                     PIN_AFIO_AF(GPIOK_PIN10, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN11, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN12, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN13, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN14, 0U) |         \
                                     PIN_AFIO_AF(GPIOK_PIN15, 0U))

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
