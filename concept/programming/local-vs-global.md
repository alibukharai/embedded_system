# Local Vs Global Variables 

| Feature         | Local Variables                            | Global Variables                      |
|------------------------|-------------------------------------------|---------------------------------------|
| **Scope**               | Limited to the block or function where they are declared. | Accessible from any part of the program. |
| **Lifetime**            | Exists only within the block or function, typically created when the block is entered and destroyed when it exits. | Exists for the entire duration of the program, created at program startup and destroyed at program termination. |
| **Access**              | Not accessible outside the scope in which they are declared. | Accessible from any part of the program. |
| **Usage**               | Used for storing temporary data or state within a specific function or block. | Used when data needs to be shared and accessed across multiple functions or throughout the program. |
| **Initialization**      | Often initialized with a value when declared within the block or function. | Initialized when the program starts, and their initial value is often defined explicitly or implicitly. |
| **Visibility**          | Typically not visible to other functions or blocks, providing encapsulation. | Can be seen and modified by any part of the program, which may lead to potential side effects. |
