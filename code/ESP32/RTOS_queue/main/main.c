#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_err.h"
#include "esp_log.h"

#define QUEUE_LENGTH 5
#define ITEM_SIZE    sizeof(int)

static const char *TAG1 = "TASK1";
static const char *TAG2 = "TASK2";

static QueueHandle_t xQueue = NULL;   //Global So every tasks can access

// Function to create a task that sends data to the queue
void sender_task(void *args) {

    QueueHandle_t xQueue = (QueueHandle_t)args;

    int data_to_send = 0;
    while (1) {
        ESP_LOGI(TAG1,"Sending data: %d", data_to_send);
        xQueueSend(xQueue, &data_to_send, portMAX_DELAY);
        data_to_send++;
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

// Function to create a task that receives data from the queue
void receiver_task(void *args) {
    QueueHandle_t xQueue = (QueueHandle_t)args;

    int received_data;
    while (1) {
        if (xQueueReceive(xQueue, &received_data, portMAX_DELAY) == pdTRUE) {
            ESP_LOGI(TAG2,"Received data: %d", received_data);
        }
    }
}

void app_main() {
    // Create a queue
    xQueue = xQueueCreate(QUEUE_LENGTH, ITEM_SIZE);

    if (xQueue == NULL) {
        printf("Failed to create the queue.\n");
        vTaskDelete(NULL);
    }
    // Create sender and receiver tasks
    xTaskCreate(sender_task, "Sender Task", 2048, (void *)xQueue, 5, NULL);
    xTaskCreate(receiver_task, "Receiver Task", 2048, (void *)xQueue, 5, NULL);
}
