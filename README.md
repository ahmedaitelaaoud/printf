#### Goal
replicate the printf function.
```
#include <stdio.h>

int main()
{
	printf("hello my name is Ahmed and i'm 23 years old\n");
	printf("hello my name is %s and i'm %d years old\n", "Ahmed", 23);
}
```
First exemple: each character written into function's output.
Second exemple: find a format specifer (%), retrieve the arg in the same position, write it in specific way.
#### Format specifiers

| **Character** | **Description**                                                                                                                                |
| :------------ | ---------------------------------------------------------------------------------------------------------------------------------------------- |
| d, i          | _Print an int_.                                                                                                                                |
| u             | _Print decimal unsigned int_.                                                                                                                  |
| x, X          | _Print an unsigned int as a [hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) number. x uses lower-case letters and X uses upper-case_. |
| s             | _Print a string_                                                                                                                               |
| c             | _Print a char_                                                                                                                                 |
| p             | _Print the address of a pointer or variable. the output in hexa._                                                                              |
#### Return value : int
Checking for errors; allows you to detect failure early.
-If positive : Successful.
-If negative : Error.

------------------------------------------------------------------
### Variadic functions
variadic function can accept a ==variable number of arguments== (printf, scanf, execl).
--> To write one in C you declare at least one fixed parameter and then ... :
```
int	ft_printf(const char *format, ...);

// const char *format is the mandatory argument of printf
```
The variadic function must have at least one argument.
#### 1- What is a macro in C
A is a rule defined by the preprocessor (before compilation starts).
	--> It tells the compiler to replace some text in your code before real compilation.
	
```#define PI 3.14159```
#### 2- The stdarg macros (how to actually read the args)
This is a core concept of how my ft_printf actually reads the variable arguments from stack or registers.
```
#include <stdarg.h>
```
In variadic functions : ```
```
int sum(int n, ...);
```
The compiler has no idea how many arguments or what their types. So <stdarg.h> traverse the raw arguments manually, one by one, safely.

--> **va_list** : 
