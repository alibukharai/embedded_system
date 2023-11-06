# main.c


```cpp
/*call function*/
usb->stateRegister(&_stream_state_changed_cb, NULL);

```

```cpp
/* Define the callback function implementation */
static void _stream_state_changed_cb(usb_stream_state_t event, void *arg)
{
    switch (event) {
    case STREAM_CONNECTED: {
        ESP_LOGI(TAG, "Device connected");
        break;
    }
    case STREAM_DISCONNECTED:
        ESP_LOGI(TAG, "Device disconnected");
        break;
    default:
        ESP_LOGE(TAG, "Unknown event");
        break;
    }
}

```

# header.h

```cpp
class USB_STREAM {
public:

  typedef void (*StateChangeCallback)(usb_stream_state_t event, void *arg);

  void stateRegister(StateChangeCallback newFunction, void *usr_data);
}

```

# header.cpp

```cpp
void USB_STREAM::stateRegister(StateChangeCallback newFunction, void *userData) {
    if (newFunction != nullptr) {
        // Register the provided callback function
        CHECK_ESP_ERROR(usb_streaming_state_register(newFunction, userData),"state register fail");
    }
}

```
