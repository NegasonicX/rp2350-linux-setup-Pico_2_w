/**
 * @file: rpm_uart.h
 * @brief: UART header file
 * @author: Kush Jain
 * @date: 09/30/2025
 */

#ifndef UART_H
#define UART_H

/**** Pico Standard Libraries ****/
#include "hardware/uart.h"
#include "hardware/irq.h"

/**** Raspberry Platform Management Libraries ****/
#include "hw.h"
#include "sw.h"

#define RPM_DEFAULT_BAUD_RATE       (115200U)
#define RPM_DEFAULT_DATA_BITS       (8U)
#define RPM_DEFAULT_STOP_BITS       (1U)
#define RPM_DEFAULT_PARITY          (UART_PARITY_NONE)

typedef enum {
    BAUD_9600 =     9600U,
    BAUD_19200 =    19200U,
    BAUD_38400 =    38400U,
    BAUD_57600 =    57600U,
    BAUD_74880 =    74880U,
    BAUD_115200 =   115200U         /* default baud rate for uart communication */
} rpm_uart_baud_t;

typedef struct {
    uart_inst_t *uartId;
    u32 uartTX;
    u32 uartRX;
    rpm_uart_baud_t baudRate;
    u32 dataBits;
    u32 stopBits;
    uart_parity_t parityBits;
    bool uartCTS;
    bool uartRTS;
} RPm_UartConfig;

/**
 * @brief This function initializes hardware uart with specific configuration
 * 
 * @param uartConfig uart configuration struct
 * @return Success or Failure
 */
PStatus RPm_UartInit(RPm_UartConfig uartConfig);

#endif //UART_H