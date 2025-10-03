#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define LED_OFF    (0U)
#define LED_ON     (1U)

int main() {

    int rc = cyw43_arch_init();
    hard_assert(rc == PICO_OK);

    while(true) {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, LED_ON);
        sleep_ms(500);

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, LED_OFF);
        sleep_ms(500);
    }

    return 0;
}