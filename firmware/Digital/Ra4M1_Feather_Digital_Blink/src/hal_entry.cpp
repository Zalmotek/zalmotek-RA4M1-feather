#include "hal_data.h"
#include "common_utils.h"

void R_BSP_WarmStart(bsp_warm_start_event_t event);

/* AGT timer callback function prototype */
void agt_callback(timer_callback_args_t *p_args);

/* Holds the current level for each pin */
bsp_io_level_t pin_levels[] = {
    BSP_IO_LEVEL_LOW, // D5
    BSP_IO_LEVEL_LOW, // D6
    BSP_IO_LEVEL_LOW, // D9
    BSP_IO_LEVEL_LOW, // D10
    BSP_IO_LEVEL_LOW, // D11
    BSP_IO_LEVEL_LOW, // D12
    BSP_IO_LEVEL_LOW  // D13
};

/* Array of pins to toggle */
const bsp_io_port_pin_t pins[] = {
    BSP_IO_PORT_01_PIN_03, // D5
    BSP_IO_PORT_01_PIN_04, // D6
    BSP_IO_PORT_01_PIN_05, // D9
    BSP_IO_PORT_01_PIN_02, // D10
    BSP_IO_PORT_01_PIN_06, // D11
    BSP_IO_PORT_01_PIN_07, // D12
    BSP_IO_PORT_01_PIN_12  // D13
};

/*******************************************************************************************************************//**
 * @brief  Blinky example application using AGT Timer interrupt.
 *
 * Toggles multiple pins using the AGT timer interrupt.
 **********************************************************************************************************************/
void hal_entry(void)
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
 * This function toggles the state of multiple pins.
 **********************************************************************************************************************/
void agt_callback(timer_callback_args_t *p_args)
{
    /* Toggle each pin in the list */
    for (size_t i = 0; i < sizeof(pins) / sizeof(pins[0]); i++)
    {
        /* Write the current level to the pin */
        R_BSP_PinWrite(pins[i], pin_levels[i]);

        /* Print the pin and its state */
        APP_PRINT("Pin: %d, State: %s\n", pins[i],
               (pin_levels[i] == BSP_IO_LEVEL_LOW) ? "LOW" : "HIGH");

        /* Toggle the level for the next write */
        pin_levels[i] = (BSP_IO_LEVEL_LOW == pin_levels[i]) ? BSP_IO_LEVEL_HIGH : BSP_IO_LEVEL_LOW;

    }
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process. This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart(bsp_warm_start_event_t event)
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
