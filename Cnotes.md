<div id="7f97a600-1c8c-4d67-b614-5f170e1f4e7e" class="cell markdown"
tags="[]">

# <center>C Notes</center>

</div>

<div id="5d8c8ad0-c6bc-4b76-8cc9-d19a1b23fca2" class="cell markdown">

[Documentation](https://devdocs.io/c/)

</div>

<div id="d7fc0c12-7b14-4cfc-8a31-c42e4c568cdc" class="cell markdown">

C is **CASE SENSITIVE** and **ALL INSTRUCTIONS** shoule be written in
**LOWERCASE**...No camelcase!!

</div>

<div id="89315c6b-fc54-4dc9-8bbe-2669cae7f524" class="cell markdown">

C is a **high-level fully compiled** language  
C is a **procedural language** that provides no support for objects and
classes  
Designed as a **general-purpose** programming language by Dennis Ritchie
at the Bell Laboratories in 1972  
C is very fast compared to other languages, like Java and Python  
C++ supports classes and objects unlike C

</div>

<div id="d85f51f7-5526-4e09-ad5c-8cf1d305a70f" class="cell markdown">

A text editor is required, like Notepad,  
along with a compiler like GCC.  
Visual Studio can be used if an IDE is wanted

</div>

<div id="42089a1e-d12e-4286-93ed-949d9ba9b941" class="cell markdown"
tags="[]">

**Compile:**

Download [mingw-setup.exe](http://www.codeblocks.org/) for IDE  
OR in terminal, enter **bash** \>\> **GCC `filename.c` -o
nameOfExeFile**

After writing a file in **.c**:  
In IDE, click **Build** \>\> **Build and Run**

</div>

<div id="46ba560a-a572-426b-8079-e189903779e9" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="5fb1746e-ca2b-4548-b681-7b5958358d18" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="693486c9-26b3-406c-9463-fba16743be9c" class="cell markdown"
tags="[]">

## Syntax

</div>

<div id="c30dd6d7-a57a-4d6d-af39-bfe369ddca54" class="cell markdown"
tags="[]">

**Header file library:**  
**`#include <stdio.h>`**

- Allows us to work with input and output functions such as printf()

Every statement ends with semi-colon **`;`**

Example code:  
`#include <stdio.h>`

`int main() {`  
 `printf("Hello World!");`  
 `return 0;`  
`}`

- main() is required in every C program  
- return 0 ends the main() function  
- curley brackets required for functions

</div>

<div id="65651406-7d2b-4dee-952c-7bf330de8bae" class="cell markdown">

**Print:**  
`printf("print message");`

- Does NOT insert a new line at the end of the output.  
- print new line with `\n`\*\*

</div>

<div id="ef0e87d3-8850-49d3-bb3b-3460770b642f" class="cell markdown">

**Escape characters:**  
`\t` Horizontal tab  
`\\` Insert **\\** character  
`\"` Insert **"** character  
`\n` Insert **new line**  
`\0` **Null** (Used to terminate char strings)  
`%%` Use to print **% symbol**

</div>

<div id="a3324f6b-a0ea-4bea-a3be-4ace527ab1c7" class="cell markdown">

**Comments:**  
`//` Single line comments  
`/*` Multiline comments, remember to finish with \`\*/

</div>

<div id="8aa8c249-5900-49d6-a135-4c46e7640790" class="cell markdown">

**Declaring variables:**  
`<type> <variable_name> = <value>;`

- Variables can be declared without assigning a value on creation
  `<type> <variable_name>;`  
- Multiple variables of the same type can be assigned in one line
  seperated with a comma
  `<type> <variable1> = <val>, <variable2> = <val>, ...;`
- Variables **CANNOT** be printed with printf - use **format
  specifiers**

</div>

<div id="0fca3dfe-3c2b-4b1b-8be9-9a6c8c149450" class="cell markdown">

**Constants:**  
`const <type> <VARIABLE_NAME> = <value>;`

- Declares an **unchangable and read-only** variable  
- **MUST** be assigned with a **value** when declaring a constant  
- Usual to declare constant variable name in uppercase

</div>

<div id="656b9e1e-742a-49ca-a368-f0fd987f917e" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="02ea063e-a01d-4cb5-820a-7b4eb67eaa6e" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="7022cf24-2d5b-48e6-9a81-1532235a0f7c" class="cell markdown">

## Format Specifiers and Types

</div>

<div id="05e0e31e-1ea3-4a82-b07e-43b7244fe5e2" class="cell markdown">

**Format specifiers:**  
`printf("<specifier>", <variable_name>);`

- Used to output variables  
- Text can be included in quotes  
- Multiple specifiers can be included, list variables seperated with
  commas

|  Specifier   | Type                          | Size                    | Description                                                                                                                                         |
|:------------:|:------------------------------|:------------------------|:----------------------------------------------------------------------------------------------------------------------------------------------------|
| `%d` or `%i` | int                           | 2 or 4 bytes            | Stores whole numbers, without decimals<br>d = Signed integer<br>i = Unsigned integer                                                                |
|     `%c`     | char                          | 1 byte                  | Stores a single character/letter/number, or ASCII values                                                                                            |
|     `%f`     | float                         | 4 bytes                 | Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits<br>Specify number of decimals with `%.<num>f` |
|    `%lf`     | double                        | 8 bytes                 | Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits<br>Specify number of decimals with `%.<num>lf` |
|     `%s`     | string                        | \[size of array\] bytes |                                                                                                                                                     |
|    `%lu`     | unsigned int or unsigned long |                         |                                                                                                                                                     |
|     `%p`     | pointer                       |                         |                                                                                                                                                     |
|    `%zu`     | size_t                        |                         | Specifically for use with **`size_t` type** (Unsigned length modifier / unsigned integer)<br>which represents the **size of any object in bytes**   |

[Format specifiers in
C](https://www.tutorialspoint.com/format-specifiers-in-c)  
[Types and
sizes](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)

</div>

<div id="9281b784-856e-4a8e-9f2f-d62b50b12574" class="cell markdown">

**Type conversion and sums:**  
**CAUTION using floats**  
`float <varaible_name> = 5 / 2;`

- This will result in **2.000000** as `5` and `2` are both **ints**

`float <variable_name> = (float) 5 / 2;`

- This outputs **correctly** as a float

</div>

<div id="f012ed6c-08df-418f-85a1-4da48601b824" class="cell markdown">

**Sizeof Operator:**  
`printf("%lu\n", sizeof(<variable_name>));`

- Prints the memory size **(in bytes)** of a data type or a variable  
- Compiler expects the sizeof operator to return a long unsigned int
  (%lu)

</div>

<div id="c7c0e578-88aa-4e80-bfc5-9e8cc56b5048" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="7632635c-62bd-4452-824d-b5d0d392251c" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="166d1c2f-b8fc-4e27-8dcf-31de2f49afbd" class="cell markdown">

## Operators

</div>

<div id="8f3ce512-fff9-4e94-839a-7efab35529e1" class="cell markdown">

**Arithmetic Operators:**

| Operator | Name           | Description                            | Example                                                          |
|:--------:|:---------------|:---------------------------------------|:-----------------------------------------------------------------|
|   `+`    | Addition       | Adds together two values               | x + y                                                            |
|   `-`    | Subtraction    | Subtracts one value from another       | x - y                                                            |
|   `*`    | Multiplication | Multiplies two values                  | x \* y                                                           |
|   `/`    | Division       | Divides one value by another           | x / y                                                            |
|   `%`    | Modulus        | Returns the division remainder         | x % y                                                            |
|   `++`   | Increment      | Increases the value of a variable by 1 | ++x (increments, then outputs)<br>x++ (outputs, then increments) |
|   `--`   | Decrement      | Decreases the value of a variable by 1 | --x (decreases, then outputs)<br>x-- (outputs, then decreases)   |

</div>

<div id="6990ae03-300c-4f4f-89cb-44ecf41b61fa" class="cell markdown">

**Assignment Operators:**

| Operator | Description                                                                                                                        | Example                                       |
|:--------:|:-----------------------------------------------------------------------------------------------------------------------------------|:----------------------------------------------|
|   `=`    | Simple assignment operator. Assigns values from right side operands to left side operand                                           | C = A + B will assign the value of A + B to C |
|   `+=`   | Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand               | C += A is equivalent to C = C + A             |
|   `-=`   | Subtract AND assignment operator. It subtracts the right operand from the left operand and assigns the result to the left operand  | C -= A is equivalent to C = C - A             |
|   `*=`   | Multiply AND assignment operator. It multiplies the right operand with the left operand and assigns the result to the left operand | C \*= A is equivalent to C = C \* A           |
|   `/=`   | Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand      | C /= A is equivalent to C = C / A             |
|   `%=`   | Modulus AND assignment operator. It takes modulus using two operands and assigns the result to the left operand                    | C %= A is equivalent to C = C % A             |
|  `<<=`   | Left shift AND assignment operator                                                                                                 | C \<\<= 2 is same as C = C \<\< 2             |
|  `>>=`   | Right shift AND assignment operator                                                                                                | C \>\>= 2 is same as C = C \>\> 2             |
|   `&=`   | Bitwise AND assignment operator                                                                                                    | C &= 2 is same as C = C & 2                   |
|   `^=`   | Bitwise exclusive OR and assignment operator                                                                                       | C ^= 2 is same as C = C ^ 2                   |
|  `\|=`   | Bitwise inclusive OR and assignment operator                                                                                       | C \|= 2 is same as C = C \| 2                 |

</div>

<div id="69071b01-3668-45e6-9e7a-c431b536ae07" class="cell markdown">

**Comparison Operators:**

| Operator | Name                     |
|:--------:|:-------------------------|
|   `==`   | Equal to                 |
|   `!=`   | Not equal                |
|   `>`    | Greater than             |
|   `<`    | Less than                |
|   `>=`   | Greater than or equal to |
|   `<=`   | Less than or equal to    |

</div>

<div id="81f87cc6-9ba3-4807-a907-fcae0754393f" class="cell markdown">

**Logical Operators:**

| Operator | Name        | Description                                             | Example              |
|:--------:|:------------|:--------------------------------------------------------|:---------------------|
|   `&&`   | Logical and | Returns true if both statements are true                | x \< 5 && x \< 10    |
|  `\|\|`  | Logical or  | Returns true if one of the statements is true           | x \< 5 \|\| x \< 4   |
|   `!`    | Logical not | Reverse the result, returns false if the result is true | !(x \< 5 && x \< 10) |

</div>

<div id="28a635df-f79e-4b30-a46c-1ea2ab9daf82" class="cell markdown">

[All operators and Operators
Precedence](https://www.tutorialspoint.com/cprogramming/c_operators.htm)

</div>

<div id="f95ff272-978b-4c73-8c1e-098271b824b0" class="cell markdown">

[C-data
types](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)

</div>

<div id="996fa947-3002-4da5-8f71-a9c2e37d3cc0" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="3b9d9ad9-ae12-4b9d-8061-8da244c76a10" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="eb09e657-bb1d-4b38-8bdf-f3421473e3a7" class="cell markdown">

## Booleans

`#include <stdbool.h>`  
`bool <varaible_name> = <value>;`

- Booleans are not a built-in type, and **must be included** in the
  header as shown  
- Can **take** values `true` or `false`  
- **Returned** as **integers**  
- **Use** **`%d`** format specifier  
- Can compare numbers, boolean variables, or special structures like
  arrays

</div>

<div id="1b2f3a8c-fcfd-4fe5-963d-86135a11b031" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="ca9133e1-ca93-44eb-adef-d6562e45cd53" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="456e2a03-9544-47e0-9860-8cdf7f12bd7d" class="cell markdown">

## Loops

</div>

<div id="b15991b0-f2c2-4947-b1ee-46c9bb5c9b26" class="cell markdown">

**if ... else:**  
`if (<condition>) {`  
 `code_to_execute_if_condition_is_true;`  
`} else if (<condition2>) {`  
 `code_to_execute_if_condition2_is_true;`  
`else {`  
 `code_to_execute_if_condition_is_false;`  
`}`

- Else if and else blocks are optional

</div>

<div id="8277a8af-d5ec-45eb-b969-b751c933f7cd" class="cell markdown">

**Short hand if ... else (ternary operator):**  
`<variable_name> = (<condition>) ? <expression_true> : <expression_false>;`

- Does not require being assigned to a variable  
- Runs expressionTrue when condition true, and expressionFalse when
  false

</div>

<div id="8fa16320-ba8e-4948-8449-bc2052417c0e" class="cell markdown">

**Switch statement:**  
`switch(<expression>) {`  
 `case <value>:`  
  `code_block;`  
  `break;`  
 `case <value>:`  
  `code_block;`  
  `break;`  
 `default:`  
  `code_block;`  
`}`

- The switch expression (can be a variable) is evaluated once  
- The value of the expression is compared with the values of each case  
- If there is a match, the associated block of code is executed  
- The break statement breaks out of the switch block and stops the
  execution  
- The default statement is optional, and specifies some code to run if
  there is no case match

</div>

<div id="53e88cb1-9873-418c-a8ff-da12167e6cea" class="cell markdown">

**While loop:**  
`while (<condition>) {`  
 `code_block_to_be_executed;`  
 `incrementer;`  
`}`

- Incrementer is not always included (infinite loop / change value to
  false etc), but is very common  
- Executes loop while condition is true  
- May never run, as condition is checked first

</div>

<div id="e3b4afb9-3ee5-4bdb-9b5e-afbf77ef5ff5" class="cell markdown">

**Do/While loop:**  
`do {`  
 `code_block_to_be_executed;`  
 `incrementer;`  
`}`  
`while (<condition>);`

- Incrementer is not always included (infinite loop / change value to
  false etc), but is very common  
- Executes loop while condition is true  
- Will be executed at least once, as condition is checked **after** code
  block is run

</div>

<div id="1800820e-3fa2-43d3-8f8d-366e62bb20a9" class="cell markdown">

**For loop:**  
`for (<initialise>; <condition>; <incrementer>) {`  
 `code_block_to_be_executed;`  
`}`

- Used when you **know exactly** how many times you want to loop  
- Initialise variable can be declared (with type) before the loop, or in
  the initialise statment

</div>

<div id="5da0d71a-b6ae-41e6-a396-2e46753b339e" class="cell markdown">

**Break statment:**  
`break;`

- Used to break out of a loop or switch statment

</div>

<div id="63844035-e72a-45bc-b155-e2a2b073ccbf" class="cell markdown">

**Continue statment:**  
`continue;`

- Breaks one iteration (usually in a loop)

</div>

<div id="3ef8400e-a67a-4d41-af32-cd90d1faf4a9" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="8d256cfd-731b-43b0-9bf0-6cd2fc6a03bc" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="56b802ec-a018-41d0-abb4-311f16e29893" class="cell markdown">

## Arrays

- Used to store multiple values in a single variable, instead of
  declaring separate variables for each value

`<type> <variable_name>[] = {<val1>, <val2>, ...};`  
**OR**  
`<type> <variable_name>[<size>]`

- Access elements with `<variable_name>[<index>]` (first element is
  **index 0**)  
- Elements can be reassigned by indexing and using assignment operator  
- **Cannot change size** after creation

</div>

<div id="1856f637-52c7-40bb-add9-08c0c87dd5d8" class="cell markdown">

**Matrices:**  
`<type> <variable_name>[<size>][<size>]... = { {<values of 1st row, comma seperated>}, {<values of 2nd row>} };`

- Index with `<variable_name>[<row>][<col>]...`

</div>

<div id="777785bb-3d85-43e4-a41b-6a0cc81ce836" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="eb967ab7-38ce-45f7-b8fa-a2c9b68fb4b9" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="36f36572-f163-41ca-a2d5-69afa5490af6" class="cell markdown">

## Strings

- No String type in C, must use `char` and create an `array` of
  characters

`char <variable_name>[] = "<string>";`  
**OR**  
`char <variable_name>[] = {'<char0>', '<char1>', ..., '\0'};`   --
**MUST include** `'\0'` at end

- Must use double quotes  
- Output with format specifier `%s`  
- **Access elements by indexing** like arrays
  `<variable_name>[<index>]`  
- **Change a character by indexing** and using **single quotes**
  `<variable_name>[<index>] = '<newChar>';`  
- `'\0'` is the null terminating character, and must be included when
  creating a string with chars (This still counts as a character with
  sizeof operator)

</div>

<div id="16d92941-5c28-499e-98aa-1ae0bfa0a209" class="cell markdown">

**Special Characters:**

- The following must be escaped when adding to a string:  
- Note the backslash counts as one character, and the character its
  escaping as another when using the sizeof operator

| Character | Enter as | Description  |
|:---------:|:--------:|:-------------|
|    `'`    |   `\'`   | Single quote |
|    `"`    |   `\"`   | Double quote |
|    `\`    |   `\\`   | Backslash    |

</div>

<div id="d17ba224-e84f-475a-8647-07a1a9a3d9af" class="cell markdown">

## String Functions

`#include <string.h>`

- **Must include** in header to use String functions

| Function name       |                 Syntax                  | Specifier (if printing) | Description                                                                                                                                                                                   |
|:--------------------|:---------------------------------------:|:-----------------------:|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| String Length       |          `strlen(<variable>);`          |          `%d`           | Returns the length of a string **NOT including** null terminator or escape characters                                                                                                         |
| Concatenate Strings | `strcat(<string_var1>, <string_var2>);` |          `%s`           | Combines two strings, result is **stored in \<string_var1\>**<br>Note that the **size** of **\<string_var1\>** should be **large enough** to store the result of the **two strings combined** |
| Copy String         | `strcpy(<string_var2>, <string_var1>);` |          `%s`           | Copies \<string_var1\> to \<string_var2\><br>Note that the **size** of **\<string_var2\>** should be **large enough** to store the copied string                                              |
| Compare Strings     | `strcmp(<string_var1>, <string_var2>);` |          `%d`           | Compares two strings<br>Returns **0 if equal**, or a non-zero value if not equal                                                                                                              |

</div>

<div id="e514224c-8dd8-4925-8d96-190161b263c4" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="9ed933ff-0f23-4564-af83-52cc19f84cc9" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="e664922a-e006-4f1d-84b7-d83468aba23e" class="cell markdown">

## User Input

**Single words:**  
`scanf("%<format_specifier>", &<variable_name>);`  
**Multiple inputs (single words):**  
`scanf("%<format_specifier1> %<format_specifier1> ...", &<variable_name>, &<variable_name>, ...);`

- **Size of string array** used must have been specified, so **ensure
  large enough**  
- **Whitespace and tabs etc** considered **terminating characters**, so
  if multiple words entered for a single string, **only the first word
  will be accepted**

**Line of text input:**  
`fgets(<variable_name>, sizeof(<variable_name>), stdin);`

- Reads a **line of input text**  
- Reads until either **newline** character or **exceeds specified buffer length** (sizeof(<variable_name>))   
- use `gets(<variable_name>)` to read until **newline** character only  
- **MUST** have minimum 2 for char array size to hold user string variable (to hold terminating character), or terminal will not wait to get input  

</div>

<div id="2ce93869-533b-407b-8baa-375b1139d0cf" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="9eb34136-3f9a-4bde-b1f1-b7087195b307" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="40f65014-eb0a-4408-846d-482fcca51167" class="cell markdown"
tags="[]">

## Memory Address and Pointers

**Summary of pointers:**

|                Syntax                 | Operator | Operator Name        | Effect                                                                                                                                                                                                                                                                                                                                                  |
|:-------------------------------------:|:--------:|:---------------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             `&variable;`              |   `&`    | Reference operator   | **Returns memory address of variable**                                                                                                                                                                                                                                                                                                                  |
| `type* pointer_variable = &variable;` |   `*`    | Indirection operator | **Declares a pointer**<br>Does not require setting at this point, ie:<br>  `type* pointer_variable;`<br>  `pointer_variable = &variable;` **--NOTE `*` is not used here**<br>Declare multiple in one line:<br>  `type* ptr1, * ptr2;` **--requires `*` for each pointer**<br>To assign at same time:<br>  `type* ptr1 = &variable, * ptr2 = &variable;` |
|         `*pointer_variable;`          |   `*`    | Dereference operator | **Returns <u>value</u> of variable** that pointer is **pointing to**                                                                                                                                                                                                                                                                                    |

**Memory address:**  
`printf("%p\n", &<variable_name>);`

- Returns the **memory address in hexidecimal**  
- When a variable is created in C, a memory address is assigned to the
  variable  
- `&` is the **reference operator**, `&<variable_name>` is called a
  **pointer**

**Pointers:**  
`<type>* <pointer_variable_name> = &<variable_name>;`

- A **variable** that **stores** the **memory address of another
  variable** as its value  
- A **pointer variable points** to a **data type** of the **same type**,
  these <u>must match</u>  
- `*` is **required**  
- Use with **CAUTION**, as **possible to damage data stored in other
  memory addresses**

**Print <u>address</u> of variable pointer is pointing at:**  
`printf("%p\n", <pointer_variable_name>);`

- Outputs the memory address of the variable the pointer is pointing to

**Print <u>value</u> of variable pointer is pointing at:**  
`printf("%<specifier>\n", *<pointer_variable_name>);`

- `*` is known as the **dereference operator**  
- Outputs the value of the variable the pointer is pointing to

**Access arrays with pointers:**  
`int <array_name>[<size>] = {<val1>, <val2>, ...};`

- Defines an array  
  `printf("%d", *<array_name>);`  
- Prints **1st element** of array as that is the same address as the
  array itself  
  `printf("%d", *(<array_name> + 1));`  
- Prints the **2nd element** of array  
  `printf("%d", *(<array_name> + 2));`  
- Prints the **3rd element** of array  
- This technique can be used in a **loop** by replacing the number to
  increase the address with `i`  
- **Accessing arrays** (especially large arrays), is **faster with
  pointers**

</div>

<div id="ba6a2060-4a61-417c-a51c-6fe9c3b05629" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="98f2c2be-05e4-450e-be3d-f65cbc81c3c7" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="6563ee03-cbda-47a6-843d-c5648c8b37fa" class="cell markdown">

## Functions

</div>

<div id="0fc1e743-377c-431c-bb17-9eaa9747d34f" class="cell markdown">

**Declare a function:**  
`<return_type> <function_name>(<type> <parameter1>, <type> <parameter2>, ...) {`  
 `code_block_to_be_executed;`  
 `return <value>;`   **-- not required if** `<return_type>` **is**
`void`  
`}`

- Parameters are optional variables to be used inside the function  
- If `<return_type>` is **not** `void`, the function must finish with a
  **return statement** `return <value>;`  
- **Return statement** could return a value or a variable  
- **Return statment value** of 0 is usually used for error handling to
  denote finished without an error, must use `<return_type>` **int** in
  declaration  
- Functions can be declared both above and below the main function
  (**see below**)

**Good practice to declare as follows:**  
`// Function declaration`  
`int add(int, int);`

`// Main method`  
`int main() {`  
 `int result = add(5, 3); // call the function`  
 `printf("Result is = %d", result);`  
 `return 0;`  
`}`

`//Function definition`  
`int add(int x, int y) {`  
 `return x + y;`  
`}`

</div>

<div id="e0333bc4-0411-4f51-bb91-4edd53ebcaac" class="cell markdown">

**Call a function:**  
`<function_name>(<argument1>, <argument2>, ...);`

- Must be the **same number** of **arguments as parameters** in defined
  function  
- **Arguments** must be in the **same order as parameters** in defined
  function

</div>

<div id="17c2fcd5-488b-421a-9603-6c5c4dfbfaf8" class="cell markdown">

**Recursion:**

- Making a function call itself

example:  
`int sum(int k);`

`int main() {`  
 `int result = sum(10);`  
 `printf("%d", result);`  
 `return 0;`  
`}`

`int sum(int k) {`  
 `if (k > 0) {`  
  `return k + sum(k - 1);`   **-- call to itself**  
 `} else {`  
  `return 0;`  
 `}`  
`}`

- With each call to itself, the argument value is reduced until the if
  statment is no longer entered  
- **Caution** required to not enter an **infinite loop**

</div>

<div id="acfd131c-401d-4321-bc37-f6abf0bcb4a7" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="37abb094-e9fb-4273-8d3e-c5ebbf1334a0" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="eac77289-6807-48b1-ae61-3d2477fab41c" class="cell markdown">

## Mathes Functions

`#include <math.h>`

- Include the header file  
- For most functions, you will want to use the format specifier for
  float `%f`

</div>

<div id="de47de1e-bba6-42d8-a68c-09ce8205b045" class="cell markdown">

| Function          |     Syntax      | Description                                                                     |
|:------------------|:---------------:|:--------------------------------------------------------------------------------|
| Absolute          |   `abs(<x>)`    | Returns the absolute value of `x`                                               |
| Arccosine         |   `acos(<x>)`   | Returns the arccosine of `x`                                                    |
| Arcsine           |   `asin(<x>)`   | Returns the arcsine of `x`                                                      |
| Arctangent        |   `atan(<x>)`   | Returns the arctangent of `x`                                                   |
| Ceiling           |   `ceil(<x>)`   | Rounds number `x` **upwards** to **nearest integer**                            |
| Cube root         |   `cbrt(<x>)`   | Returns the cube root of `x`                                                    |
| Cos               |   `cos(<x>)`    | Returns the cosine of `x`                                                       |
| Euler raised to x |   `exp(<x>)`    | Returns the value of <code>e<sup>x</sup></code>                                 |
| Floor             |  `floor(<x>)`   | Rounds number `x` **downwards** to **nearest integer**                          |
| Power             | `pow(<x>, <y>)` | Finds the value of <code>x<sup>y</sup></code>                                   |
| Sine              |   `sin(<x>)`    | Returns the sine of `x` (`x` is in radians)                                     |
| Square root       |   `sqrt(<x>)`   | Find the **square root** of a number `x`                                        |
| Tan               |   `tan(<x>)`    | Returns the tangent of an angle, ie: tan(`x`) = length_opposite/length_adjacent |

</div>

<div id="2e32c51b-5ee2-4d8b-8ed7-5287bf7986bb" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="716c14d8-d4e6-4d38-bcb3-9769b418939b" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="19309000-0c4d-4145-ba11-1c3373fe78bf" class="cell markdown">

## Files

</div>

<div id="3b39573e-42a5-475a-a7bf-a5044739cd95" class="cell markdown">

**File Handling:**  
`FILE* <file_pointer>;`  
`<file_pointer> = fopen("<filename>.<exetension>", "<mode>");`

- Can create, open, read and write to files by declaring a **pointer of
  type** `FILE` (**example name: `fptr`**), and use `fopen()` function  
- `<mode>` can be:
  - `w` - writes to a file **-- will create if does not exist**, also
    **<u>overwrites</u> previous content**  
  - `a` - appends to a file **-- also creates if does not exist**  
  - `r` - reads from a file **-- returns** `NULL` **if does not
    exist**  
  - `r+` - Opens for both reading and writing. If the file doesn't exist
    or can't be found, the call to open the file fails  
  - `w+` - Opens an empty file for both reading and writing. If the
    given file exists, its contents are destroyed  
  - `a+` - The same as `a` but also allows reading  
  - **r+ / w+ / a+** - requires **rewind()** between write/read
    operations. [Further
    reading](https://learn.microsoft.com/en-us/cpp/c-runtime-library/file-read-write-access-constants?view=msvc-170)  
- When creating files, they will be created in the **same directory as
  the program file if nothing else other than name is specifiied**,
  however can provide path

</div>

<div id="1336dbd0-eafb-4782-89da-d7c15c7b9f8f" class="cell markdown">

**Close file:**  
`fclose(<file_pointer>);`

- **GOOD PRACTICE** to close file when done

<br>

</div>

<div id="f51ae442-d1e4-4fe7-9f6a-74c0707c2647" class="cell markdown">

**Writting to file:**

- Open file as above (in **write or append mode**)

`fprintf(<file_pointer>, "<text_to_write>");`

- Can enter multiple as follows:

`fprintf(<file_pointer>, "%s %d <format_specifer> ...", "<text_to_write>", <integer>, <variable>, ...);`

- [More
  info](https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm)  
- Remember to **close file** when done

<br>

</div>

<div id="bdfed12a-2787-447c-9019-a5ba14d692c7" class="cell markdown"
jp-MarkdownHeadingCollapsed="true" tags="[]">

**Reading from a file:**

- Open file as above (in **read mode**)

<br>

##### --Read line at a time--

- **Create** a **string large enough** to store contents:

`char <string_name>[<size>];`

- Use **fgets** function to **read text and store in string**:

`fgets(<string_name>, <max_size_of_data_to_read>, <file_pointer>);`
 **--returns NULL at end of file**

- `<max_size_of_data_to_read>` will **usually match string size**  
- Use `printf()` function to output text  
- `fgets()` only **reads 1 line at a time** (up to size specified), need
  to use in **while loop** to read **every line** (see below)

<br>

##### --Read character at a time--

`char <variable> = fgetc(<file_pointer>)`  **--returns EOF at end of
file**

- Returns unsigned char or EOF

<br>

##### --GOOD PRACTICE to check file exists--

`if (<file_pointer> != NULL) {`  
 `while (fgets(<string_name>, <max_size>, <file_pointner>)) {`  [--use
feof() function with
**fgetc()**](https://www.tutorialspoint.com/c_standard_library/c_function_feof.htm)  
  `printf("%s", <string_name>);`  
 `}`  
`} else {`  
 `printf("Not able to open the file.");`  
`}`

- **CLOSE FILE**  
  `fclose(<file_pointer>);`

<br>

</div>

<div id="3f4e9838-2950-4726-b4fe-da13b771e8eb" class="cell markdown">

##### --Writting and reading to file without closing inbetween--

- Open file in a **read/write mode** (r+, w+, a+)  
- Requires **resetting** the **file position** to the beginning of the
  file between operations  
  `rewind(<file_pointer>);`

<br>

</div>

<div id="72e3e67b-2e99-4928-a3f3-71ff39fd5f33" class="cell markdown">

**fseek() --set file position of stream:**  
`fseek(<file_pointer>, <long int offset>, <int whence>);`

- `<long int offset>` is the number of bytes to offset file positon from
  `whence`, this equates to **number of chars** in most cases  
- `<int whence>` is the position **from where the offset is added** and
  can be one of the following:
  - `SEEK_SET` -- **Beginning of file**  
  - `SEEK_CUR` -- **Current position**  
  - `SEEK_END` -- **End of file**

Example:  
`fseek(fp, 7, SEEK_SET);` -- sets file position 7 bytes (7 chars) from
beginning of file

</div>

<div id="8cc4e8f3-4cdb-4b04-a013-7083cc7e5146" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="e6a609ad-88bd-4a29-a400-266900f10615" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="6fe7de91-b7cb-4d0b-98e4-fe4b01ba9145" class="cell markdown">

## Clock() Function

Function to get clock tick, allowing timing of functions etc.

`#include <time.h>`

- Must include the time header

<br>

`clock_t <variable>;`

- Declares a clock tick object

<br>

`<variable> = clock();`

- Gets clock tick and assigns to **clock_t variable**  
- Can set a variable to **start** and **end** time (or a new variable =
  clock() - start_time)  
- Note, **must divide by CLOCKS_PER_SEC** to get **seconds**

<br>

`double <total_time_variable> = (double) (<end_time> - <start_time>) / CLOCKS_PER_SEC`

- Returns **elapsed time in <u>seconds</u>**

</div>

<div id="ad354b88-221b-4b5d-b1ec-e5dfad67e395" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="804f53a3-f194-4c6b-afc0-5115b2b2057a" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="23841391-4141-46d9-a346-201d52d4b491" class="cell markdown">

## Structs (Structures)

A way to **group several related variables into one place**  
Each variable in the struct is known as **a member**  
**Can contain different types**

<br>

##### --Declare a structure--

`struct <structure_name> {`  
 `<type> <member_variable>;`  
 `<type> <member_variable>;`  
 `...`  
`};`

- Usually declared outside of main method

<br>

##### --Create a struct variable--

`struct <structure_name> <structure_variable>;`

- Usually declared inside the main method

<br>

##### --Assign and access member values--

Either **at declaration:**  
`struct <structure_name> <structure_variable> = {<member1_value>, <member2_value>, ...};`

- Must be in **same order as declared in the structure**

**OR**

`<structure_variable>.<member_variable> = <value>;`  
`printf("<specifier>", <structure_variable>.<member_variable>);`

- Assigns a value to a structure member (can also **modify in the same
  manner**)  
- To **assign a string to** a char array **member**, **MUST use
  strcpy():**  
   `strcpy(<structure_variable>.<string_member_variable>, "<string>");`  
- To **access members of a structure**, use the **dot operator**. To
  **access members of a structure through a <u>pointer</u>** (such as in
  a function), use the **arrow operator:**  
  `strcpy(<structure_pointer>`**`->`**`<string_member_variable>, "<string>");`
   **--don't however use spaces between pointer and member**

Structures can also be **copied to another structure**  
`<structure_variable1> = <structure_variable2>;`

<br>

##### --Using typedef to define a new data type--

`typedef strut <structure_name> {`  
 `<type> <member_variable>;`  
 `<type> <member_variable>;`  
 `...`  
`} <type_name>;`

- Defining a structure in this way allows us to **define structure
  variables directly**:  
  `<type_name> <variable>;`  
- Assign values in the same way as above

</div>

<div id="cc8a87a5-b736-4438-92bf-932e0addd9c0" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="d548dccb-503f-4a1f-913d-cdb79ca83c4b" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="6b31b906-fd1a-46a2-be11-0561659ee9a4" class="cell markdown">

## Aliases with \#define

`#define <alias> <value>`

- Note `;` is not used  
  example:  
  `#define TRUE 1`  
  `printf( "Value of TRUE : %d\n", TRUE);` **--Value of TRUE : 1**

</div>

<div id="67e598cc-937e-4605-a433-39bb86fc46dc" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="91094d6a-3e4d-49b0-8111-a8ccd26006ca" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="50b7106c-428d-46ea-9b19-2a0f47be3d92" class="cell markdown">

## Enums (Enumerated lists)

Often **used in switch statments**  
Or give **names to constansts**

`enum <enum_name> {`  
 `<ENUM_ITEM1>,`  **-- declared in caps as constant**  
 `<ENUM_ITEM2>,`  
 `...`  
`};`

- Declares enum list (usually outside main method)  
- Can **assign value** to item with `<ENUM_ITEM> = <value>,`

`enum <enum_name> <enum_variable> = <ENUM_ITEM>;`  
`printf("%d", <enum_variable>);`

- Top item in list will have **default value = 0**, next = 1 and so on  
- **If assigned a value** to an item in a list, the **following items
  will continue from given** number

</div>

<div id="f95abc1a-76a5-4281-9993-7791a1e773b3" class="cell markdown">

[<p style="text-align: right;">**⬆ Table of Contents ⬆**</p>](#C-Notes)

</div>

<div id="149aa788-0838-43a1-9213-44bd2d131c83" class="cell markdown">

------------------------------------------------------------------------

</div>

<div id="a69e54a2-f5e1-4ea5-a3f6-2a6533cadc63" class="cell code">

``` python
```

</div>
