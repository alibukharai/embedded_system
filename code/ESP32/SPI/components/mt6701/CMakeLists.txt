idf_component_register(SRCS "sensor_mt6701.c"
                    INCLUDE_DIRS "." "include"
                    REQUIRES driver esp_timer
                    )