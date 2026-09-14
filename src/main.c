#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_13

void app_main(void)
{
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_GPIO, 1);
        printf("LED ON\n");
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(LED_GPIO, 0);
        printf("LED OFF\n");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}