#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/ringbuf.h"

#define RING_BUFFER_SIZE 1028
#define TASK_STACK_SIZE 2048
#define TASK_PRIORITY 5
#define TASK_DELAY_MS 1000 //1ms

static TaskHandle_t taskSendHandle = NULL;
static TaskHandle_t taskReceiveHandle = NULL;
static RingbufHandle_t ringBuffer;

void taskSend(void *arg)
{
    static char *txItem = "A Sending Task";
    BaseType_t result;

    while (1) {
        result = xRingbufferSend(ringBuffer, txItem, strlen(txItem), pdMS_TO_TICKS(100));
        if (result == pdTRUE) {
            printf("Send item: %s\n", txItem);
        } else {
            printf("Failed to send item: %s\n", txItem);
        }
        vTaskDelay(pdMS_TO_TICKS(TASK_DELAY_MS));
    }
}

void taskReceive(void *arg)
{
    static size_t itemReceive;
    static char *item;

    while (1) {
        item = (char *)xRingbufferReceive(ringBuffer, &itemReceive, pdMS_TO_TICKS(100));
        if (item != NULL) {
            item[itemReceive] = '\0';
            printf("Received item: %s\n", item);
            printf("Received item size: %d\n", itemReceive);
            vRingbufferReturnItem(ringBuffer, (void *)item);
        } else {
            printf("Failed to receive item.\n");
        }

        vTaskDelay(pdMS_TO_TICKS(TASK_DELAY_MS));
    }
}

void app_main()
{
    // RingBuffer creation
    ringBuffer = xRingbufferCreate(RING_BUFFER_SIZE, RINGBUF_TYPE_NOSPLIT);

    if (ringBuffer == NULL) {
        printf("Failed to create the ring buffer.\n");
        return;
    }

    // Create tasks
    if (xTaskCreate(taskSend, "TaskSend", TASK_STACK_SIZE, NULL, TASK_PRIORITY, &taskSendHandle) != pdPASS) {
        printf("Failed to create the taskSend task.\n");
        vRingbufferDelete(ringBuffer);
        return;
    }

    if (xTaskCreate(taskReceive, "TaskReceive", TASK_STACK_SIZE, NULL, TASK_PRIORITY, &taskReceiveHandle) != pdPASS) {
        printf("Failed to create the taskReceive task.\n");
        vRingbufferDelete(ringBuffer);
        return;
    }

    vTaskDelay(pdMS_TO_TICKS(TASK_DELAY_MS));
}
