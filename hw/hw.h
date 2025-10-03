/**
 * @file: hw.h
 * @brief: header file with rpi2350 hardware parameters
 * @author: Kush Jain
 * @date: 09/28/2025
 */

/************************ RPI2350 Pin-Out ************************/

#include "pico/cyw43_arch.h"

/***** rpi2350 gpios ****/
typedef enum {
    GPIO0  = 0U,            /* UART0_TX | I2C0_SDA | SPI0_RX */
    GPIO1  = 1U,            /* UART0_RX | I2C0_SCL | SPI0_CS */
    GPIO2  = 2U,            /* I2C1_SDA | SPI0_CLK */
    GPIO3  = 3U,            /* I2C1_SCL | SPI0_TX */
    GPIO4  = 4U,            /* UART1_TX | I2C0_SDA | SPI0_RX */
    GPIO5  = 5U,            /* UART1_RX | I2C0_SCL | SPI0_CS */
    GPIO6  = 6U,            /* I2C1_SDA | SPI0_CLK */
    GPIO7  = 7U,            /* I2C1_SCL | SPI0_TX */
    GPIO8  = 8U,            /* UART1_TX | I2C0_SDA | SPI1_RX */
    GPIO9  = 9U,            /* UART1_RX | I2C0_SCL | SPI1_CS */
    GPIO10 = 10U,           /* I2C1_SDA | SPI1_CLK */
    GPIO11 = 11U,           /* I2C1_SCL | SPI1_TX */
    GPIO12 = 12U,           /* UART0_TX | I2C0_SDA | SPI1_RX */
    GPIO13 = 13U,           /* UART0_RX | I2C0_SCL | SPI1_CS */
    GPIO14 = 14U,           /* I2C1_SDA | SPI1_CLK */
    GPIO15 = 15U,           /* I2C1_SCL | SPI1_TX */
    GPIO16 = 16U,           /* UART0_TX | I2C0_SDA | SPI0_RX */
    GPIO17 = 17U,           /* UART0_RX | I2C0_SCL | SPI0_CS */
    GPIO18 = 18U,           /* I2C1_SDA | SPI0_CLK */
    GPIO19 = 19U,           /* I2C1_SCL | SPI0_TX */
    GPIO20 = 20U,           /* I2C0_SDA */
    GPIO21 = 21U,           /* I2C1_SCL */
    GPIO22 = 22U,           /* GPIO */
    GPIO26 = 26U,           /* I2C1_SDA | ADC0 */
    GPIO27 = 27U,           /* I2C1_SCL | ADC1 */
    GPIO28 = 28U            /* ADC2 */
} rpm_gpio_pins_t;

/***** rpi2350 internal led ****/
#define PIN_INT_LED                                 (CYW43_WL_GPIO_LED_PIN)

/***** rpi2350 uart pins (default) ****/
#define PIN_UART0_TX                                (GPIO0)
#define PIN_UART0_RX                                (GPIO1)
#define PIN_UART1_TX                                (GPIO8)
#define PIN_UART1_RX                                (GPIO9)

/***** rpi2350 i2c pins (default) ****/
#define PIN_I2C0_SDA                                (GPIO4)
#define PIN_I2C0_SCL                                (GPIO5)
#define PIN_I2C1_SDA                                (GPIO6)
#define PIN_I2C1_SCL                                (GPIO7)

/***** rpi2350 spi pins (default) ****/
#define PIN_SPI0_TX                                 (GPIO19)
#define PIN_SPI0_RX                                 (GPIO16)
#define PIN_SPI0_CK                                 (GPIO18)
#define PIN_SPI0_CS                                 (GPIO17)
#define PIN_SPI1_TX                                 (GPIO11)
#define PIN_SPI1_RX                                 (GPIO12)
#define PIN_SPI1_CK                                 (GPIO10)
#define PIN_SPI1_CS                                 (GPIO13)

/***** rpi2350 adc pins (default) ****/
#define PIN_ADC0                                    (GPIO26)
#define PIN_ADC1                                    (GPIO27)
#define PIN_ADC2                                    (GPIO28)