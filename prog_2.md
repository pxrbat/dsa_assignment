# Documentation for prog_2.c
## Infix Expression to Postfix Expression Conversion
This program takes any infix expression such as `1 + 2` and converts them to postfix expression (`12+)`. It then evaluates the postfix expression and prints them.

## Data Structures Used
The program uses the **stack** data structure as the primary data structure which are implemented using static arrays. 
Two distinct stacks are defined and implemented in this program:
1. **Operator Stack (`operator_stack`)**
	* The `operator_stack` is a **global** character array implemented as `char operator_stack[MAX]`  where `MAX` defines the maximum number of characters the stack can hold.
	* `top_op` is an integer variable initialized to -1 that represents the top index of the `operator_stack`.
	* This stack is used during the Infix to Postfix conversion proces to store operators such as (`+`,`-`,`/`,`^`,`*`,`(`)  temporarily until their precedence dictates whether they should be moved to the output string or not.
2. **Value Stack (`value_stack`)**  	
	* The `value_stack` is also a **global** integer array which is implemented as `int value_stack[MAX]`.
	* `top_val` represents the top index of the stack and is also initialized to -1.
	* It is used to store operand values during the Postfix expression evaluation. 

For both stacks, 	`MAX` is defined as 20.
## Description of Functions Used
The program uses the following functions:
### Stack Operations:
* `void push_op(char op)`: This function pushes a character operator onto the `operator_stack`, after verifying that the stack is not full.
* `char pop_op()`: This functions removes the top element of the operator stack and returns it, after verifying that the stack is not empty.
* `int push_val(char val)`: This function pushes an operand onto the value stack, after verifying that the stack is not full.
* `int pop_val()`: This function removes the top value from the value stack and returns it after checking for "Stack Underflow".
### Helper Functions
* `int prec(char op)`: This function determines the precedence of an operator.
	* Assigns highest precedence i.e. 3 to the exponent operator `^`.
	* Assigns medium precedence i.e. 2 to the multiplication `*` and division `/`operators.
	* Assigns lowest precedence i.e. 1 to the addition `+` and the subtraction `-` operators.
* `bool is_right_assoc(char op)`: Since only the exponent operator `^` is right associated among the operators we evaluate in this program, the function returns `true` for `^` and `false` otherwise.
* `int operator_eval(int a, int b, char op)`: This function performs the actual arithmetic  operations based on the operator character provided.
### Core functions
* `void infix_to_postfix(char* infix, char* postfix)`:
	* This function's purpose is to convert an infix expression (`1+2`) into a postfix expression (`12+`).
	* **Logic**:
		* It iterates through the input string i.e. the infix expression.
		* Operands are added to the postfix expression character array `char postfix[MAX]` as they are encountered.
		* If any opening parenthesis `(` is encountered, it is pushed into the operator stack `operator_stack`.
		* If any closing parenthesis `(` is encountered, then the `operator_stack` is popped and the values are appended to `char postfix[MAX]` while the stack is not empty and a opening parenthesis `(` is not found. The opening parenthesis is not appended to the postfix character array.
		*  When an operator is encountered, the function checks the operator already on the top of stack before pushing the encountered operator.
			* If the operator on the stack has higher or equal precedence, the stack operator is popped to the output first.
			* `!is_right_assoc(ch)` part ensures that for right-associative operators like `^`, we don't pop and existing `^` from the stack, allowing multiple powers to be evaluated right to left.
			* Once every higher priority operator is cleared from the stack, the current operator is pushed to the stack.
		* After the function finishes iterating over the entire infix string, the remaining operators left on the stack are popped one by one and added to the end of the postfix character array. A null terminator is added to make the postfix result into a valid C-string.

* `int postfix_eval(char* postfix)`:
	* This function's purpose is to evaluate the result of the converted postfix string.
	* **Logic**:
		* The function iterates through the postfix string.
		* When an operand/digit is found, it is converted to an integer and pushed to the `value_stack`.
		* When an operator is found, two values are popped from the stack, the operation is performed via the `operator_eval` function and the result is pushed into the stack.
		* This process is repeated until the function iterates through the string and the final result stays in the stack.
		* The result of evaluation is returned at the end by popping the stack.  

## Organization of the main() Method
The `main()` method is the entry point of the program and executes the program in a linear, sequential flow by the following steps:
1. Arrays to hold `infix` input string and the resulting `postfix` string are declared.
2. The user is prompted to enter an Infix expression and it is read using `scanf` and stored in the `infix` string.
3. It prints the received infix expression to the console for verification.
4. It calls `infix_to_postfix()`, passing the `infix` and `postfix` strings as arguments. The function calculates the postfix string and prints it.
5. It calls the `postfix_eval()` function with the generated `postfix` string as argument and stores the result of evaluation in an integer variable `result`.
6. Finally, it prints the integer result returned by the function `postfix_eval()`.

## Sample Output
Below are some examples of a complete run of the program using different infix expression of varying precedence and parentheses.
**Sample Input 1**
```bash
Enter Infix Expression: 1+(3*4)
```
**Sample Output 1**
```bash
Given Infix Expression is: 1+(3*4)
Equivalent Postfix Expression is: 134*+
The result is: 13
```
**Sample Input 2**
```bash
Enter Infix Expression: 3^4+1
```
**Sample Output 1**
```bash
Given Infix Expression is: 3^4+1
Equivalent Postfix Expression is: 34^1+
The result is: 82
```