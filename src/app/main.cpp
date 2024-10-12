#include "testlibrary/testlibrary.hpp"
#include "zephyr/drivers/gpio.h"
#include "zephyr/kernel.h"

constexpr int32_t SLEEP_TIME_MS = 100;

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main() {
    int ret;

    if (!gpio_is_ready_dt(&led))
        return 1;

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        return 1;
    }

    while (true) {
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            return 1;
        }
        k_msleep(SLEEP_TIME_MS);
    }

    return 1;
}
