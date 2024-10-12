#include "testlibrary/testlibrary.hpp"
#include "zephyr/drivers/gpio.h"
#include "zephyr/kernel.h"
#include "zephyr/logging/log.h"

#define LED0_NODE DT_ALIAS(led0)

LOG_MODULE_REGISTER(logger, LOG_LEVEL_DBG);

int main() {
    LOG_DBG("Starting application.");
    int ret;
    const auto sleep_time_ms = static_cast<int32_t>(testlib::factorial(6));

    const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
    if (!gpio_is_ready_dt(&led)) {
        LOG_ERR("GPIO not configured correctly.");
        return 1;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        LOG_ERR("LED not configured correctly.");
        return 1;
    }

    while (true) {
        LOG_DBG("Toggle LED...");
        ret = gpio_pin_toggle_dt(&led);
        if (ret < 0) {
            LOG_ERR("Cannot toggle LED.");
            return 1;
        }
        k_msleep(sleep_time_ms);
    }

    return 0;
}
