# Static Global  VS Global Variables 

| Feature         | Static Global Variables                    | Regular (Non-Static) Global Variables   |
|------------------------|-------------------------------------------|---------------------------------------|
| **Scope**               | Accessible only within the file in which they are defined. They have file-level scope. | Accessible from any part of the program, including other files (when properly declared). They have program-level scope. |
| **Lifetime**            | Exist for the entire duration of the program. Created at program startup and destroyed at program termination. | Exist for the entire duration of the program. Created at program startup and destroyed at program termination. |
| **Initialization**      | Initialized only once, typically at program startup. Their initial values can be explicitly set. | Initialized only once, typically at program startup. Their initial values can be explicitly set. |
| **Accessibility**      | Accessible only within the file in which they are defined. Not accessible from other files. | Accessible from any part of the program, including other files, if properly declared with the `extern` keyword. |
| **Use Cases**          | Useful for creating variables with file-level scope, sharing data within a single file, and encapsulating data within a file. | Used when data needs to be shared and accessed across multiple files or throughout the entire program. |

Static global variables are typically used when you want to restrict the scope of a variable to a single file and encapsulate data within that file, preventing other files from accessing it directly. Regular global variables are used when data needs to be shared and accessed across multiple files or throughout the entire program.