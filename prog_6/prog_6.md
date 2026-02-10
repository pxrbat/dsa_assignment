
# Documentation for prog_6.c
## Building Min Heaps and Max Heaps from Unsorted Array 
This program takes an unsorted array of integers as input and builds both a Min Heap and a Max Heap from it.

## Data Structures Used

This program uses **dynamic arrays** to represent heaps. The heap is stored in a linear array where the tree structure is maintained through index calculations rather than explicit pointers.
```c
int  *data = (int*)malloc(sizeof(int)*n);
int  *min_heap = (int*)malloc(sizeof(int)*n);
int  *max_heap = (int*)malloc(sizeof(int)*n);
```
For any element at index `i` in the array:
- Left child index is `2*i + 1`
- Right child index is `2*i +2`
- Parent is at index `(i-1)/2`

## Description of Functions Used 
**1. `void swap(int *a, int *b)`** 
- This function swaps the values of two integers using pointers. 
-  **Working:** 
	- It creates a temporary variable to store the value of the first integer. 
	- It then assigns the value of the second integer to the first. 
	- Finally, it assigns the stored value to the second integer. 

**2. `void heapify_min(int arr[], int n, int i)`** 
- This function maintains the min heap property for a subtree rooted at index `i`. 
-  **Working:** 
	- It assumes the left and right subtrees are already min heaps. 
	- It identifies the smallest element among the node at index `i`, its left child, and its right child. 
	- First, it sets `smallest = i` (assuming the current node is smallest). 
	- It calculates the indices of left child (`l = 2*i + 1`) and right child (`r = 2*i + 2`). 
	- If the left child exists (`l < n`) and is smaller than the current smallest, it updates `smallest = l`. 
	- If the right child exists (`r < n`) and is smaller than the current smallest, it updates `smallest = r`. 
	- If the smallest element is not the current node, it swaps the current node with the smallest and recursively calls `heapify_min` on the affected subtree.

**3. `void heapify_max(int arr[], int n, int i)`** 
- This function maintains the max heap property for a subtree rooted at index `i`. 
-  **Working:** 
	- It works similarly to `heapify_min` but in the opposite direction. 
	- It identifies the largest element among the node at index `i`, its left child, and its right child. 
	- It sets `largest = i` initially. 
	- It calculates left (`l = 2*i + 1`) and right (`r = 2*i + 2`) child indices. 
	- If the left child exists and is larger than the current largest, it updates `largest = l`. 
	- If the right child exists and is larger than the current largest, it updates `largest = r`. 
	- If the largest element is not the current node, it swaps them and recursively calls `heapify_max` on the affected subtree.

**4. `void build_min_heap(int arr[], int n)`** 
- This function converts an unsorted array into a min heap. 
-  **Working:** 
	- It starts from the last non-leaf node and works backwards to the root. 
	- The last non-leaf node is at index `n/2 - 1` (since nodes from `n/2` to `n-1` are leaf nodes). 
	- For each node from `n/2 - 1` down to 0, it calls `heapify_min` to ensure that node and its subtree satisfy the min heap property. 
	- By processing nodes in reverse level order (bottom-up), we ensure that when we heapify a node, its children are already valid heaps. 

**5. `void build_max_heap(int arr[], int n)`** 
- This function converts an unsorted array into a max heap. 
-  **Working:** 
	- It uses the same bottom-up approach as `build_min_heap`. 
	- It starts from the last non-leaf node at index `n/2 - 1`. 
	- For each node from `n/2 - 1` down to 0, it calls `heapify_max`. 
	- This ensures that each subtree satisfies the max heap property before moving up the tree. 
	- By the time we reach the root, the entire array represents a valid max heap.

**6. `void print_array(const char *label, int arr[], int n)`** 
- This function prints the heap array with a descriptive label. 
- **Working:** 
	- It first prints the provided label string. 
	-  Then it iterates through the array and prints each element separated by spaces. 
	- Finally, it prints a newline for better formatting.

## Organization of the main() Method
This is the entry point of the program that demonstrates heap creation. **Working:** 
- It prompts the user to enter the number of elements and validates the input. 
- - It dynamically allocates memory for three arrays using `malloc()`: 
	-  `data[]` to store the original input 
	-  `min_heap[]` to build the min heap 
	-  `max_heap[]` to build the max heap 
- It checks if memory allocation was successful. If it fails, it frees any allocated memory and exits. 
- It reads the elements from the user and copies them to both heap arrays. 
- It calls `build_min_heap()` on the `min_heap` array to convert it into a min heap. 
- It calls `build_max_heap()` on the `max_heap` array to convert it into a max heap. 
- It prints both heaps in array form. 
- Finally, it frees all dynamically allocated memory to prevent memory leaks.

## Sample Output
```bash
Enter number of elements: 3
Enter the elements: 1 6 78
Min Heap (array form): 1 6 78 
Max Heap (array form): 78 6 1 
```
