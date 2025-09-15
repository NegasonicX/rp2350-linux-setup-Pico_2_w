#include "pico/stdlib.h"

#define LED_PIN     (25U)

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true) {
        gpio_put(LED_PIN, 1U);
        sleep_ms(2000);

        gpio_put(LED_PIN, 0U);
        sleep_ms(2000);
    }

    return 0;
}