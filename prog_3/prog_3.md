# Documentation for prog_3.c

## Implementation of Singly Linked List with Reverse Traversal

This program implements a basic singly linked list data structure using structures where each node contains an integer data and a pointer to the next node. This program demonstrates traversing the list in reverse directions along with fundamental linked list operations such as insertion of nodes to at the head and tail of the list as well as forward traversal of the linked list.

## Data Structures Used
### Node structure
Each individual node in the linked list is implemented using a structure:
```C
typedef struct Node{
	int data;
	struct Node* next;
}
```
`data` stores an integer value and `next` is a pointer to the next node in the list.
The program also uses two global pointers to keep track of the list:
- `Node* HEAD` is a pointer to the first node in the list.
- `Node* TAIL` is a pointer to the last node in the list.
These two pointers allow us to add elements to either end of the linked list.

## Description of Functions used
**1. `void  init_list()`** 
- This function initializes an empty linked list. 
-  **Working:** 
	- It sets both `HEAD` and `TAIL` pointers to `NULL`, which indicates that the list is currently empty and contains no nodes.

**2. `int  isEmpty()`** 
- This function checks whether the linked list is empty or not. 
-  **Working:** 
	- It returns `1` (true)  if `HEAD ==  NULL`, meaning the list has no nodes. 
	- It returns `0` (false)  if the list contains at least one node.

**3. `void  add_to_tail(int data)`** 
- This function adds a new node with the given data at the end of the linked list. 
-  **Working:** 
	- It first dynamically allocates memory for a new node using `malloc()`. 
	- It assigns the provided data to the new node and sets its `next` pointer to `NULL` since it will be the last node. 
	- If the list is empty  (checked using `isEmpty()`), it sets both `HEAD` and `TAIL` to point to this new node. 
	- If the list already has nodes, it makes the current `TAIL` node point to the new node, and then updates `TAIL` to point to the new node.

**4. `void  add_to_head(int data)`** 
- This function adds a new node with the given data at the beginning of the linked list. 
-  **Working:** 
	- It allocates memory for a new node using `malloc()`. 
	- It assigns the provided data to the new node. 
	- It sets the new node's `next` pointer to the current `HEAD`, effectively placing it before all existing nodes. 
	- If the list is empty, it also updates `TAIL` to point to this new node. 
	- Finally, it updates `HEAD` to point to the new node, making it the first node in the list.

**5. `void  traverse_list()`** 
- This function traverses the linked list from HEAD to TAIL and prints all the elements in order. 
-  **Working:** 
	- It creates a temporary pointer `p` and initializes it to `HEAD`. 
	- It uses a while loop to traverse through the list until it reaches the second last node  (where `p->next !=  NULL`). 
	- For each node except the last one, it prints the data followed by an arrow symbol `->`. -
	-  After the loop exits, it prints the last node's data without an arrow to complete the traversal.

**6. `void  reverse_traverse(Node* p)`** 
- This function recursively traverses the linked list in reverse order and prints the elements. 
-  **Working:** 
	- This is a recursive function that takes a node pointer as a parameter. 
	- The base case checks if `p ==  NULL`. If it is, the function simply returns without doing anything. 
	- Otherwise, it makes a recursive call with `p->next`, which goes deeper into the list. 
	- After the recursive call returns  (meaning we've reached the end and are now backtracking), it prints the current node's data. 
	- If the current node is not the `HEAD`, it prints an arrow `->` after the data. If it is the `HEAD`, it prints just the data without an arrow. 
	
## Organization of the main() Method
This is the entry point of the program that demonstrates the linked list operations. 
**Working:** 
- It initializes an empty linked list by calling `init_list()`. 
- It adds the value 10 to the tail of the list. 
- It adds the value 20 to the head of the list. 
- It adds the value 30 to the tail of the list. 
- After these operations, the list looks like: `20  ->  10  ->  30` 
- It calls `traverse_list()` to print the list in forward order. 
- It prints "Reverse Traversal is: " and then calls `reverse_traverse(HEAD)` to print the list in reverse order.

## Sample Output 
``` 
Regular Traversal is:  20->10->30 
Reverse Traversal is:  30->10->20 
```
