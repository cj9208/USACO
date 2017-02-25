# [C++ macro](https://gcc.gnu.org/onlinedocs/cpp/Macros.html#Macros)
## Object-like Macros 
* commonly used to give symbolic names to numeric constants
* by convention, macro names are written in uppercase
* use backslash-newline for multiple lines
```C++
 #define NUMBERS 1, \
                 2
```
## Function-like Macros
* use the same ‘#define’ directive, but put a pair of parentheses immediately after the macro name
```C++
#define foo() /* optimized inline version */
```
* attentions
    * A function-like macro is only expanded if its name appears with a pair of parentheses after it
    * there _cannot_ be _spaces_ between the macro name and the parentheses in the macro definition

## Macro Arguments
```C++
define min(X, Y)  ((X) < (Y) ? (X) : (Y))
```
* attentions
    * use parentheses for each parameters and for all expression (in case of priority problem)
    * Macro parameters appearing inside string literals are not replaced by their corresponding actual arguments
    ```
    #define foo(x) x, "x"
    foo(bar)        ==> bar, "x"
    ```
    
## Stringizing
* convert a macro argument into a string constant
    * when a macro parameter is used with a leading ‘#’, the preprocessor replaces it with the literal text of the actual argument
```C++
#define WARN_IF(EXP) \
do { if (EXP) \
    fprintf (stderr, "Warning: " #EXP "\n"); } \
while (0)
WARN_IF (x == 0);
    ==> do { if (x == 0)
            fprintf (stderr, "Warning: " "x == 0" "\n"); } while (0);
```
```C++
#define str(s) #s
```
* attentions
    * All leading and trailing whitespace in text being stringized is ignored. 
    * Any sequence of whitespace in the middle of the text is converted to a single space in the stringized result
    * Comments are replaced by whitespace long before stringizing happens, so they never appear in stringized text

## Concatenation
* when a macro is expanded, the two tokens on either side of each ‘##’ operator are combined into a single token
* two tokens that don't together form a valid token cannot be pasted together ( If you try, the preprocessor issues a warning and emits the two tokens)
* If either of the tokens next to an ‘##’ is a parameter name, it is replaced by its actual argument before ‘##’ executes
* C preprocessor converts comments to whitespace before macros are even considered
```
#define COMMAND(NAME)  { #NAME, NAME ## _command }    
     struct command commands[] =
     {
       COMMAND (quit),
       COMMAND (help),
       ...
     };
===>     
     struct command
     {
       char *name;
       void (*function) (void);
     };
     
     struct command commands[] =
     {
       { "quit", quit_command },
       { "help", help_command },
       ...
     };
```

## Variadic Macros
```C++
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define eprintf(args...) fprintf (stderr, args)
```

## [Predefined Macros](https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html#Predefined-Macros)
* Standard Predefined Macros
* Common Predefined Macros
* System-specific Predefined Macros
* C++ Named Operators

## Undefining and Redefining Macros
* If a macro is redefined with a definition that is not effectively the same as the old one, the preprocessor issues a warning and changes the macro to use the new definition
* not redefine/undefine a macro within macro arguments 
```C++
#undef FOO
```

## [Macro Pitfalls](https://gcc.gnu.org/onlinedocs/cpp/Macro-Pitfalls.html#Macro-Pitfalls)
* special rules and counter-intuitive examples
