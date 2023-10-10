#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Function prototypes for the two tasks
void Task1(void *pvParameters);
void Task2(void *pvParameters);

void app_main() {
    // Create Task1 and Task2 and assign them to different cores

    // Task1 running on Core 0
    xTaskCreatePinnedToCore(
        Task1,                // Task function
        "Task1",              // Task name (for debugging)
        4096,                 // Stack size (in bytes)
        NULL,                 // Task parameters
        1,                    // Task priority
        NULL,                 // Task handle
        0                     // Core ID (0 for Core 0)
    );

    // Task2 running on Core 1
    xTaskCreatePinnedToCore(
        Task2,                // Task function
        "Task2",              // Task name (for debugging)
        4096,                 // Stack size (in bytes)
        NULL,                 // Task parameters
        1,                    // Task priority
        NULL,                 // Task handle
        1                     // Core ID (1 for Core 1)
    );
}

void Task1(void *pvParameters) {
    while (1) {
        printf("Task1 is running on Core %d\n", xPortGetCoreID());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void Task2(void *pvParameters) {
    while (1) {
        printf("Task2 is running on Core %d\n", xPortGetCoreID());
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
