/**
 * @file: rpm_uart.c
 * @brief: UART Hardware management module for rpi2350
 * @author: Kush Jain
 * @date: 09/30/2025
 */

#include "rpm_uart.h"
#pragma message("UART module added in design.")

struct {
    uart_inst_t *uart0Alive;
    uart_inst_t *uart1Alive;
} RPmUart_IsAlive = {NULL};

/**
 * @brief Combined interrupt handler for uart on RX and TX operations
 * 
 * @param None
 * @return None
 * @note By default, SDK uses a single shared vector table between both the cores.
 *          Hence, an interrupt triggered sets the same handler for both cores.
 */
static void RPm_UartRxTx_Handler(void) {

}

PStatus RPm_UartInit(RPm_UartConfig uartConfig) {
    PStatus = RPM_FAILURE;

    /* implement logic to check whether given UART is available or not */

    /* set uart RX and TX pins */
    gpio_set_function(uartConfig.uartTX, UART_FUNCSEL_NUM(uartConfig.uartId, uartConfig.uartTX));
    gpio_set_function(uartConfig.uartRX, UART_FUNCSEL_NUM(uartConfig.uartId, uartConfig.uartRX));

    /* Initialize uart with baud rate */
    uart_init(uartConfig.uartId, uartConfig.baudRate);

    /* set uart glow control bits */
    uart_set_hw_flow(uartConfig.uartId, uartConfig.uartCTS, uartConfig.uartRTS);

    /* set uart bit stream format */
    uart_set_format(uartConfig.uartId, uartConfig.dataBits, uartConfig.stopBits, uartConfig.parityBits);

    /* use uart in FIFO mode (by default) */
    uart_set_fifo_enabled(uartConfig.uartId, true);

    /* setup uart RX interrupt */
    u32 uartIRQ = ((uartConfig.uartId == uart0) ? UART0_IRQ : UART1_IRQ);
    irq_set_exclusive_handler(uartIRQ, RPm_UartRxTx_Handler);
    irq_set_enabled(uartIRQ, true);

    /* enable both RX and TX IRQs */
    uart_set_irq_enables(uartConfig.uartId, true, true);

    /* set the given uart as alive! */
    if (uart0 == uartConfig.uartId) RPmUart_IsAlive.uart0Alive = uart0;
    else RPmUart_IsAlive.uart1Alive = uart1;
}