#include "py/mphal.h"

void MACH_ELT2_board_early_init(void) {
    // Reset the Ethernet PHY
    mp_hal_pin_output(pyb_pin_ETH_RMII_RST_N);

    mp_hal_pin_low(pyb_pin_ETH_RMII_RST_N); // ---\__50ms__/---
    mp_hal_delay_ms(50);
    mp_hal_pin_high(pyb_pin_ETH_RMII_RST_N);
}
