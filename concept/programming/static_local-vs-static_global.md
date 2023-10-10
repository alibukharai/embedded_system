# Static Local Vs Static Global Variables 

| Feature                  | Static Local Variable | Static Global Variable |
|--------------------------|-----------------------|------------------------|
| Declaration              | Defined within a function using the `static` keyword. | Defined outside of any function using the `static` keyword. |
| Scope                    | Limited to the function in which they are declared. | Available throughout the entire file in which they are defined. |
| Lifetime                 | Exists for the entire duration of the program. | Exists for the entire duration of the program. |
| Storage Location         | Stored in the program's `stack` memory. | Stored in the program's `data` memory. |
| Initialization          | Initialized only once, on the first function call. | Initialized only once, at program startup. |
| Accessibility           | Not accessible outside the declaring function. | Accessible from any function in the same file. |
| Usage                    | Useful for retaining values between function calls. | Useful for creating variables with file-level scope. |
