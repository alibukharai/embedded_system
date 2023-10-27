#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "sensor_mt6701.h"

#define portTICK_RATE_MS portTICK_PERIOD_MS

static const char *TAG = "main"; 

void app_main()
{
    // Define the GPIO pins for SPI communication
    int GPIO_SCLK = 17;  // Replace with the actual GPIO pin numbers
    int GPIO_MISO = 16;  // Replace with the actual GPIO pin numbers
    int GPIO_MOSI = -1;  // Replace with the actual GPIO pin numbers
    int GPIO_CS = 18;    // Replace with the actual GPIO pin numbers

    // Initialize the MT6701 sensor
    sensor_mt6701_init(GPIO_SCLK, GPIO_MISO, GPIO_MOSI, GPIO_CS);

    while (1)
    {
        // Get the current shaft angle from the sensor
        float angle = sensor_mt7601_getAngle();

        // Log the angle value using ESP_LOG
        ESP_LOGD(TAG, "Current Shaft Angle: %f radians", angle);

        // Add a delay or perform other tasks as needed
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
