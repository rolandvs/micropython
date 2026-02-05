/**
 *	ELT2 board uses little real estate so most of the options are DISABLED
 * 
**/


#define MICROPY_HW_BOARD_NAME       "MACH_ELT2"
#define MICROPY_HW_MCU_NAME         "STM32H743"

#define MICROPY_HW_ENABLE_RTC       (1)	// internal clock, no external 32768Hz XTAL
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (0)
#define MICROPY_HW_ENABLE_DAC       (0)	// not used, could be a valuable debug tool
#define MICROPY_HW_ENABLE_USB       (0)	// not used, could be handy for debug
#define MICROPY_HW_ENABLE_SDCARD    (0)	// flash, no SD card
#define MICROPY_HW_HAS_SWITCH       (1)	// push button
#define MICROPY_HW_HAS_FLASH        (1)	// flash memory as file system


#define MICROPY_BOARD_EARLY_INIT    MACH_ELT2_board_early_init	// pre-init like reset peripherals
void MACH_ELT2_board_early_init(void);


// Oscillator configuration (adjust to your actual hardware)
#define MICROPY_HW_CLK_USE_HSE      (1)
#define MICROPY_HW_CLK_HSE_MHZ      (25)

// The board has an 25MHz HSE, the following gives CPU speed
#define MICROPY_HW_CLK_PLLM         (5)
#define MICROPY_HW_CLK_PLLN         (192)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (15)
#define MICROPY_HW_CLK_PLLR         (2)
#define MICROPY_HW_CLK_PLLVCI       (RCC_PLL1VCIRANGE_3)
#define MICROPY_HW_CLK_PLLVCO       (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC      (0)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M        (5)
#define MICROPY_HW_CLK_PLL3N        (48)
#define MICROPY_HW_CLK_PLL3P        (2)
#define MICROPY_HW_CLK_PLL3Q        (5)
#define MICROPY_HW_CLK_PLL3R        (2)
#define MICROPY_HW_CLK_PLL3VCI      (RCC_PLL3VCIRANGE_2)
#define MICROPY_HW_CLK_PLL3VCO      (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC     (0)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// UART config
#define MICROPY_HW_UART1_TX         (pin_B14)	// only one uart is used
#define MICROPY_HW_UART1_RX         (pin_B15)

//#define MICROPY_HW_UART2_TX         (pin_D5)
//#define MICROPY_HW_UART2_RX         (pin_D6)
//#define MICROPY_HW_UART2_RTS        (pin_D4)
//#define MICROPY_HW_UART2_CTS        (pin_D3)

#define MICROPY_HW_UART_REPL        PYB_UART_1	// repl console
#define MICROPY_HW_UART_REPL_BAUD   115200

// LEDs
#define MICROPY_HW_LED1             (pin_B7)    // red
#define MICROPY_HW_LED2             (pin_B8)	// green
#define MICROPY_HW_LED3             (pin_B9)	// blue
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USRSW is pulled high. Pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN        (pin_E14)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// USB config
#define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

// Ethernet via RMII (XTAL=25MHz)
#define MICROPY_HW_ETH_MDC          (pin_C1)
#define MICROPY_HW_ETH_MDIO         (pin_A2)
#define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
#define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
#define MICROPY_HW_ETH_RMII_TX_EN   (pin_B11)
#define MICROPY_HW_ETH_RMII_TXD0    (pin_B12)
#define MICROPY_HW_ETH_RMII_TXD1    (pin_B13)
#define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
#define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)

// Enable QSPI flash
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (28) // 256Mbit = 2^28 bits = 32MB

// QSPI Flash Pin Configuration
#define MICROPY_HW_QSPIFLASH_CS     (pin_B6)   // FLASH_CS
#define MICROPY_HW_QSPIFLASH_SCK    (pin_B2)   // FLASH_CLK
#define MICROPY_HW_QSPIFLASH_IO0    (pin_D11)  // FLASH_DI (IO0/MOSI)
#define MICROPY_HW_QSPIFLASH_IO1    (pin_C10)  // FLASH_DO (IO1/MISO)
#define MICROPY_HW_QSPIFLASH_IO2    (pin_E2)   // IO2 (WP#)
#define MICROPY_HW_QSPIFLASH_IO3    (pin_D13)  // IO3 (HOLD#/RESET#)

// W25Q256JV specific configuration
//#define MICROPY_HW_QSPI_PRESCALER		(2)  // QSPI clock divider (adjust for stability)
//#define MICROPY_HW_QSPI_SAMPLE_SHIFT    (1)  // Half-cycle sample shift

// Enable external flash filesystem
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)  // Use external flash instead
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)

#define MICROPY_HW_ENABLE_QSPI          (1)
#define MICROPY_HW_QSPI_FLASH_SIZE      (32 * 1024 * 1024)  // 32MB

// Filesystem configuration
#define MICROPY_HW_BDEV_QSPIFLASH       (1)
#define MICROPY_HW_BDEV_QSPIFLASH_SIZE_BYTES (MICROPY_HW_QSPI_FLASH_SIZE)


// USB configuration (if available on your board)
// #define MICROPY_HW_USB_FS                   (1)

// Optional: Enable memory-mapped mode for XIP
// Uncomment to enable XIP execution from flash
// #define MICROPY_HW_QSPI_MEMORY_MAPPED       (1)
// #define MICROPY_HW_QSPI_XIP_BASE            (0x90000000)

