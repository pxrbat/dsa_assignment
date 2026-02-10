
# Documentation for prog_8.c
## Sorting an array of integers using Bubble, Selection, Insertion, or Merge Sort
This program generates a random array of integers and allows the user to sort it using one of four sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, or Merge Sort. It also keeps track of and displays the number of comparisons and swaps performed during the sorting process.

## Data Structures Used

This program uses **dynamically allocated** integer arrays to store the data.
```c
int  *arr =  malloc(n *sizeof(int));
int  *arr_2 =  malloc(n*  sizeof(int));
```
Memory is allocated using `malloc()` and freed after use.
The program also has two global integer variables: `int cmp_cnt` that counts the number of comparisons and `int swap_cnt` that keeps count of the number of swaps.
Merge Sort algorithm creates temporary arrays during the merge process that are dynamically allocated and freed after each merge operation. 

## Description of Functions Used 

**1. `void print_array(int *arr, int n)`** 
- This function prints all elements of the array separated by spaces.


**2. `void bubble_sort(int *arr, int n)`** 
- This function implements the Bubble Sort algorithm. 
- It uses nested loops to repeatedly compare adjacent elements and swaps them if they're in wrong order. 
- After each pass, the largest unsorted element is bubbled up to its correct position. 
- **Time Complexity:**  `O(n²)`


**3. `void selection_sort(int *arr, int n)`** 
- This function implements the Selection Sort algorithm. 
- For each position, it finds the minimum element in the remaining unsorted portion and swaps it with the current position. 
- **Time Complexity:**  `O(n²)`


**4. `void insertion_sort(int *arr, int n)`** 
- This function implements the Insertion Sort algorithm. 
- It starts from the second element and treats it as a key, then compares it with elements in the sorted portion. 
- While elements are greater than the key, it shifts them right and inserts the key in the correct position. 
- **Time Complexity:**  `O(n²)` worst case, `O(n)` best case


**5. `void merge(int *arr, int left, int mid, int right)`** 
- This function merges two sorted subarrays into one sorted array. 
- It creates temporary arrays to hold copies of the subarrays, then compares elements from both and merges them back in sorted order. 
- It frees the temporary arrays after merging to prevent memory leaks. 
- **Time Complexity:**  `O(n)`


**6. `void merge_sort(int *arr, int left, int right)`** 
- This function implements Merge Sort using divide-and-conquer approach. - It recursively divides the array into halves until each subarray has one element, then merges them back in sorted order. 
- **Time Complexity:**  `O(n log n)`

## Organization of the main() Method
This is the entry point of the program that demonstrates heap creation. **Working:** 
- The main function seeds the random number generator using `srand(time(NULL))`. 
- It prompts the user to enter the array size. 
- It dynamically allocates memory for two arrays using `malloc()`. 
- It fills the first array with random integers between 1 and 1000. 
- It displays the unsorted array using `print_array()`. 
- It presents a menu of four sorting algorithm options. 
- After the user makes a choice, it copies the original array to preserve it. 
- It executes the selected sorting algorithm using a switch statement. 
- It prints the sorted array along with the number of comparisons and swaps performed. 
- It frees all dynamically allocated memory to prevent memory leaks.

## Sample Output
### Bubble Sort
```bash
Enter the number of random integers (N): 12

Generating 12 random integers in range [1, 1000]...

Before Sorting:
303 215 42 610 632 921 793 182 433 634 722 593 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 1

Using Bubble Sort

After Sorting:
42 182 215 303 433 593 610 632 634 722 793 921 

Number of comparisons: 66
Swaps: 24
```
### Selection Sort
```bash
Enter the number of random integers (N): 12

Generating 12 random integers in range [1, 1000]...

Before Sorting:
354 116 783 858 811 434 738 83 526 465 537 652 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 2

Using Selection Sort

After Sorting:
83 116 354 434 465 526 537 652 738 783 811 858 

Number of comparisons: 66
Swaps: 10
```
### Insertion Sort
```bash
Enter the number of random integers (N): 12

Generating 12 random integers in range [1, 1000]...

Before Sorting:
411 205 315 43 725 442 703 753 954 197 665 162 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 3

Using Insertion Sort

After Sorting:
43 162 197 205 315 411 442 665 703 725 753 954 

Number of comparisons: 38
Swaps: 29
```
### Merge Sort
```bash
Enter the number of random integers (N): 12

Generating 12 random integers in range [1, 1000]...

Before Sorting:
530 197 929 424 450 627 149 609 762 323 164 812 

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice (1-4): 4

Using Merge Sort

After Sorting:
149 164 197 323 424 450 530 609 627 762 812 929 

Number of comparisons: 33
Swaps: 33
```
