# Documentation for prog_4.c

## Implementation of Doubly Linked List with Insert and Delete Operations

This program implements a doubly linked list data structure where each node contains an integer value, pointer to the next node, and pointer to the previous node. The programs demonstrates insert operation after a given node and delete operation of the doubly linked list along with traversal in both directions.

## Data Structures Used
### Node structure
Each individual node in the linked list is implemented using a structure:
```C
typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev
}
```
`data` stores an integer value, `next` is a pointer to the next node in the list and `prev` is a pointer to the previous node in the list.
The program also uses two global pointers to keep track of the list:
- `Node* HEAD` is a pointer to the first node in the list.
- `Node* TAIL` is a pointer to the last node in the list.
These two pointers allow us to add elements to either end of the linked list.

## Description of Functions used
**1. `void  init_list()`** 
- This function initializes an empty doubly linked list. 
-  **Working:** 
	- It sets both `HEAD` and `TAIL` pointers to `NULL`, which indicates that the list is currently empty and contains no nodes.

**2. `int  is_empty()`** 
- This function checks whether the linked list is empty or not. 
-  **Working:** 
	- It returns `1` (true)  if `HEAD ==  NULL`, meaning the list has no nodes. 
	- It returns `0` (false)  if the list contains at least one node.

**3. `void  add_to_tail(int data)`** 
- This function adds a new node with the given data at the end of the linked list. 
-  **Working:** 
	- It first dynamically allocates memory for a new node using `malloc()`. 
	- It assigns the provided data to the new node and sets its `next` pointer to `NULL` since it will be the last node. 
	- It sets the new node's `prev` pointer to the current `TAIL`.
	- If the list is empty  (checked using `is_empty()`), it sets both `HEAD` and `TAIL` to point to this new node. 
	- If the list already has nodes, it makes the current `TAIL` node's next pointer point to the new node, and then updates `TAIL` to point to the new node.

**4. `void  add_to_head(int data)`** 
- This function adds a new node with the given data at the beginning of the linked list. 
-  **Working:** 
	- It allocates memory for a new node using `malloc()`. 
	- It assigns the provided data to the new node. 
	- It sets the new node's `next` pointer to the current `HEAD` and its `prev` pointer to `NULL`. 
	- If the list is empty, it also updates `TAIL` to point to this new node. 
	- If the list is not empty, it updates the current `HEAD`'s prev pointer to point to the new node.
	- Finally, it updates `HEAD` to point to the new node, making it the first node in the list.

**5. `void  traverse_list()`** 
- This function traverses the linked list from HEAD to TAIL and prints all the elements in forward order. 
-  **Working:** 
	- It first checks if the list is empty. If it is, it prints "List is empty" and returns.
	- It creates a temporary pointer `p` and initializes it to `HEAD`. 
	- It uses a while loop to traverse through the list until it reaches the second last node  (where `p->next !=  NULL`). 
	- For each node except the last one, it prints the data followed by an arrow symbol `->`. -
	-  After the loop exits, it prints the last node's data without an arrow to complete the traversal.

**6. `void  reverse_traverse(Node* p)`** 
- This function traverses the doubly linked list from TAIL to HEAD and prints all the elements in reverse order. 
-  **Working:** 
	- It first checks if the list is empty. If it is, it prints "List is empty" and returns. 
	- It creates a temporary pointer `p` and initializes it to `TAIL`. 
	- It uses a while loop to traverse backwards through the list until it reaches the second node from the front  (where `p->prev !=  NULL`). 
	- For each node except the first one, it prints the data followed by an arrow symbol `->`. 
	- After the loop exits, it prints the first node's data without an arrow.

**7. `void  insert_after_node(int node_data,  int data)`** 
- This function inserts a new node with the given data after a node that contains the specified node_data value. 
-  **Working:** 
	- It creates a pointer `p` and starts from `HEAD`. 
	- It traverses the list until it finds the node with data equal to `node_data`, or reaches the end of the list. 
	- If the node is not found  (`p ==  NULL`), it prints an error message and returns. 
	- If the node is found, it allocates memory for a new node and sets its data. 
	- It sets the new node's `next` pointer to `p->next` and its `prev` pointer to `p`. 
	- If `p->next` is not `NULL` (meaning p is not the last node), it updates the next node's prev pointer to point to the new node. 
	- If `p->next` is `NULL` (meaning p is the last node), it updates `TAIL` to point to the new node. 
	- Finally, it sets `p->next` to the new node, completing the insertion.

**8. `int  delete_node(int node_data)`** 
- This function deletes a node with the specified data value from the doubly linked list. 
-  **Working:** 
	- It creates a pointer `p` and starts from `HEAD`. 
	- It traverses the list until it finds the node with data equal to `node_data`, or reaches the end. 
	- If the node is not found  (`p ==  NULL`), it prints an error message and returns -1. 
	- If the node is found, it performs the deletion by updating pointers: 
	- If the node has a previous node  (`p->prev !=  NULL`), it sets the previous node's next pointer to skip over the current node. -
	-  If there's no previous node (meaning we're deleting the HEAD), it updates `HEAD` to point to the next node. 
	- If the node has a next node  (`p->next !=  NULL`), it sets the next node's prev pointer to point to the previous node. 
	- If there's no next node, it updates `TAIL` to point to the previous node. 	
	- It saves the deleted node's data, frees the memory allocated for the node using `free()`, and returns the deleted data.
	
## Organization of the main() Method

This is the entry point of the program that demonstrates the doubly linked list operations. 
**Working:** 
- It initializes an empty doubly linked list by calling `init_list()`. 
- It adds the value 10 to the tail of the list. 
- It adds the value 20 to the tail of the list. 
- It adds the value 30 to the tail of the list. 
- It adds the value 5 to the head of the list. 
- It calls `traverse_list()` to print the list in forward order. 
- It calls `reverse_traverse()` to print the list in reverse order. 
- It inserts a new node with value 25 after the node containing 20. 
- It traverses the list again to show the updated structure.
- It deletes the node containing value 10. 
- It prints the deleted value and traverses the list to show the final list.
## Sample Output 
```bash
The linked list is:  5->10->20->30
Reverse Traversal of the linked list is:  30->20->10->5
Inserted node with data 25 after node with data 20
The linked list is:  5->10->20->25->30
Deleted node with data:  10 
The linked list is:  5->20->25->30
```
