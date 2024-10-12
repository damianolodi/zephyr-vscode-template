#include "testlibrary/testlibrary.hpp"
#include "zephyr/drivers/gpio.h"
#include "zephyr/kernel.h"

#define LED0_NODE DT_ALIAS(led0)

int main() {
    int ret;
    const auto sleep_time_ms = static_cast<int32_t>(testlib::factorial(6));

    const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
    if (!gpio_is_ready_dt(&led))
        return 1;

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0)
        return 1;

    while (true) {
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0)
            return 1;

        k_msleep(sleep_time_ms);
    }

    return 0;
}
