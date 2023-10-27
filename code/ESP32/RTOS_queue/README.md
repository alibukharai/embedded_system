# RTOS Queue
In this code, a FreeRTOS queue is created to facilitate the exchange of data between two tasks: a sender task and a receiver task. 

- The sender task is responsible for periodically sending data to the queue, and 
- The receiver task is responsible for retrieving and displaying the data it receives from the queue. 
 
The code sets up the queue with a specified length and item size, ensuring that data can be efficiently transmitted between the tasks. The sender task continually sends data to the queue, which is then received and processed by the receiver task, allowing for communication and synchronization between these two concurrent tasks in the FreeRTOS environment.