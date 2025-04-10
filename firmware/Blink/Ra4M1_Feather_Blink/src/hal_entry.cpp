/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hal_data.h"

void R_BSP_WarmStart(bsp_warm_start_event_t event);

/* AGT timer callback function prototype */
void agt_callback(timer_callback_args_t *p_args);

/* Holds level to set for pin */
bsp_io_level_t pin_level = BSP_IO_LEVEL_LOW;

/*******************************************************************************************************************//**
 * @brief  Blinky example application using AGT Timer interrupt.
 *
 * Toggles BSP_IO_PORT_01_PIN_12 using the AGT timer interrupt.
 **********************************************************************************************************************/
void hal_entry (void)
{
#if BSP_TZ_SECURE_BUILD

    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

    /* Enable access to the PFS registers */
    R_BSP_PinAccessEnable();

    /* Open the AGT timer (AGT0 or AGT1 depending on what you configured) */
    R_AGT_Open(&g_timer0_ctrl, &g_timer0_cfg);

    /* Start the AGT timer */
    R_AGT_Start(&g_timer0_ctrl);

    while (1)
    {
        /* The main loop can be left empty as the LED toggling is handled in the interrupt */
    }

    /* Protect PFS registers */
    R_BSP_PinAccessDisable();
}

/*******************************************************************************************************************//**
 * @brief  AGT timer interrupt callback.
 *
 * This function toggles the state of BSP_IO_PORT_01_PIN_12.
 **********************************************************************************************************************/
void agt_callback(timer_callback_args_t *p_args)
{
    /* Toggle the LED pin */
    R_BSP_PinWrite(BSP_IO_PORT_01_PIN_12, pin_level);

    /* Toggle level for next write */
    pin_level = (BSP_IO_LEVEL_LOW == pin_level) ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process. This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open(&IOPORT_CFG_CTRL, &IOPORT_CFG_NAME);
    }
}
