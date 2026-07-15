#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "bluepad32.h"

static const char *TAG = "BP32";

static ControllerPtr myController = NULL;

void on_connected_controller(ControllerPtr ctl) {
    ESP_LOGI(TAG, "Controller connected!");
    myController = ctl;
}

void on_disconnected_controller(ControllerPtr ctl) {
    if (myController == ctl) {
        myController = NULL;
    }
    ESP_LOGI(TAG, "Controller disconnected!");
}

void app_main(void) {
    ESP_LOGI(TAG, "Starting Bluepad32...");

    BP32.setup(on_connected_controller, on_disconnected_controller);

    while (1) {
        BP32.update();

        if (myController && myController->isConnected()) {
            int x = myController->axisX();
            int y = myController->axisY();

            ESP_LOGI(TAG, "X=%d Y=%d", x, y);
        }

        vTaskDelay(pdMS_TO_TICKS(50));
    }
}