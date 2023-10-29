#include <stdio.h>
#include "esp_log.h"
#include "fun.h"

static const char *TAG = "call-back-function";


void app_main(void) {
    int num1, num2;
    printf("Enter two integers: ");

    int result = add(num1, num2);

    printf("Sum: %d\n", result);

}
