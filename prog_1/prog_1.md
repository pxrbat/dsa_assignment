# Documentation for prog_1.c
## Balanced Parentheses using Stack
This program takes any mathematical expression such as `a+(b*{c-d}) ` as input from the user and checks if the number of parentheses and their order in the expression are valid.

## Data Structures Used
This program uses the **stack** data structure as the primary data structure to check whether there are balanced number of parentheses in the provided mathematical expression. Stack is also used to check if these parentheses are present in the correct order in the expression.

The stack is implemented using a `char` array: `char stack[MAX]`

- `MAX` defines the maximum number of characters that the stack can hold.
- An integer variable `top` is also defined to keep track of the index of the top element of the stack in the array with `top = -1` indicating that the stack is empty.

The program reads the input expression character by character. Whenever an opening parenthesis (`(`,`{`,`[`) is encountered, it is pushed onto the stack. Now, when any closing parenthesis (`)`,`}`,`]`) is encountered, the stack is used to test whether the popped opening parenthesis matches the closing parenthesis to determine validity of the parentheses in the expression.

## Description of Functions Used
**1. `void push(char ch)`** 
* This function pushes any opening parenthesis encountered while scanning the expression onto the stack.
* **Working**
	*  This function checks if the stack is full via `top == MAX-1`, if it is full, it prints `Stack Overflow` and exits.
	* If there is space, it increments `top` by 1 and stores the parenthesis character at that index.
* **Time Complexity** 
	* `O(1)` -- constant time insertion by indexing onto the stack array.

**2. `int pop(char ch)`**
* This function removes and returns the opening parenthesis at the top of the stack whenever a closing parenthesis is encountered in the expression. 
* **Working**
	*  The function checks if the stack is empty via `top == -1`, if it is empty, it prints `Stack Underflow` and exits.
	* If the stack is not empty, it returns the top element and decrements `top` by 1.
* **Time Complexity**
	* `O(1)` -- constant time removal of element via indexing from the stack array.

**3. `void evaluate_parentheses(char *expression)`**
* This function checks whether the given expression has a  balanced number of parentheses.
* **Working**
	*  It traverses the expression character by character.
	* If it finds any opening parenthesis, it pushes them onto the stack via the `push(char ch)` function.
	* When it finds a closing parenthesis:
		* It checks if the stack is empty. If empty, it prints that the expression does not have balanced number of parentheses.
		* If not empty, it pops the opening parenthesis at the top and verifies it matches the closing parenthesis. If they don't match, it prints that the expression does not have balanced number of expression.
	* After processing the entire expression:
		* If the stack is empty, the parentheses are balanced.
		* Otherwise, there are unmatched opening parentheses.
	
	Appropriate messages are printed for each case.

* **Time Complexity**
	* `O(n)`, the entire expression of `n` length has to be traversed and each character has to be processed exactly once.
	* `push` and `pop` take constant time.
	
**4. `int main()`**
* The `main` function is the entry point of the program. 
* **Working**
	*  It declares a character array `char expression[MAX]` to store the input expression.
	* It prompts the user using `printf` to enter any mathematical expression containing parentheses.
	* The input expression is read using `scanf`.
	* The `evaluate_parentheses()` function is called with `expression` array as an argument to check if the expression contains balanced number of parentheses.
	* It terminates the program.

## Sample Output
**Sample Input 1**
```bash
Enter any expression with parentheses: a+(b-c)*(d  
```
**Sample Output 1**
```bash
The number of parentheses in this expression is not balanced because there is an opening parenthesis '(' with no matching closing parenthesis.
```
**Sample Input 2**
```bash
Enter any expression with parentheses: m+[a-b*(c+d*{m)]
```
**Sample Output 2**
```bash
The expression does not have a balanced number of parentheses as ')' does not match '{'
```
**Sample Input 3**
```bash
Enter any expression with parentheses: a+(b-c)
```
**Sample Output 3**
```bash
The expression has balanced number of parentheses.
```