
# Documentation for prog_5.c

## BFS and DFS Traversal on Undirected Graph using Adjacency Matrix

This program implements an undirected graph using an adjacency matrix and demonstrates two fundamentail graph traversal algorithms: **Breadth First Search (BFS)** and **Depth First Search (DFS)**. This program lets a user create a graph by adding edges between nodes and then traverse it using either technique.

  

## Implementing an Undirected Graph using Adjacency Matrix

An undirected graph is a collection of nodes connected by edges that have no direction. This means there is bidirectional travel route between any two nodes on the graph.

An adjacency matrix is a 2D array that is used to represent connection between nodes in a graph.

For a graph of `n` nodes, we use `n x n` matrix where:

* `a_matrix[i][j] = 1` means there is an edge between node `i` and node `j`
* `a_matrix[i][j] = 0` means there is no edge between nodes `i` and `j`
* In case of an undirected graph, the adjacency matrix is symmetric. This means if there is an edge between nodes `i` and `j`, `a_matrix[i][j] = a_matrix[j][i] = 1`.

## Data Structures Used
**1. Queue - for BFS**
The queue is implemented using an integer array with front and rear pointers to keep track of first and last elements respectively.
```c
typedef struct{
	int items[MAX];
	int front;
	int rear;
}Queue;
```
`items[MAX]` stores the node indices waiting to be processed. 
The queue is empty when `front = -1`.

**2. Stack - for DFS**
The stack is also implemented using an integer array with a top pointer to keep track of the topmost element.
```c
typedef struct{	
	int items[MAX];
	int top;
}Stack;
```
When `top = -1`, the stack is empty.

**3. Graph**
The graph structure contains the number of nodes and the adjacency matrix.
```c
typedef struct{
	int nodes;
	int a_matrix[MAX][MAX]
}Graph;
```
`nodes` stores the total number of nodes in the graph and `a_matrix[MAX][MAX]` is the 2D adjacency matrix.
## Description of Functions Used
### Queue Operations
**1. `void  init_q(Queue* q)`** 
- This function initializes the queue by setting both front and rear pointers to -1 which indicates an empty queue. 


**2. `bool is_q_empty(Queue* q)`**
 - It checks if the queue is empty by verifying if `front ==  -1`. - The function returns `true` if empty, `false` otherwise. 


**3. `void  enqueue(Queue* q,  int data)`** 
- It adds the index of a node to the rear end of the queue. 
-  **Working:** 
	- It checks if the queue is full  (`rear == MAX-1`). If queue is full, it prints "Queue Overflow" and returns. 
	- If the queue is empty, it sets `front =  0`. 
	- Then, it increments `rear` and stores the data at that position.

 

**4. `int  dequeue(Queue* q)`** 

- This function removes and returns the node index from the front of the queue.
 -  **Working:**
	  - It first checks if the queue is empty. If it is, the function prints "Queue Underflow" and returns -1. 
	  - It retrieves the element at the `front` position. 
	  - If `front == rear` (meaning there's only one element), it reinitializes the queue by calling `init_q()`. 
	  - Otherwise, it just increments `front` to move to the next element. 


### Stack Operations
**1. `void  init_s(Stack* s)`** 
- This function initializes the stack by setting `top =  -1`, which indicates an empty stack. 


**2. `bool is_s_empty(Stack* s)`** 
- This function checks if the stack is empty by verifying if `top ==  -1`.
- It returns `true` if the stack is empty, `false` otherwise. 


**3. `void  push(Stack* s,  int data)`** 
- This function pushes a node index onto the top of the stack. 
-  **Working:** 
	- It first checks if the stack is full by testing `top == MAX-1`. If the stack is full, it prints "Stack Overflow" and returns. 
	- Then it increments `top` and stores the data at that new position. 


**4. `int  pop(Stack* s)`** 
- This function removes and returns the node index from the top of the stack. 
-  **Working:** 
	- It checks if the stack is empty first. If it is, the function prints "Stack Underflow" and returns -1. 
	- It retrieves the element at the `top` position and then decrements `top`. 

### Graph Operations
**1. `void  init_graph(Graph* g,  int nodes)`** 
- This function initializes the graph with a given number of nodes. 
-  **Working:** 
	- It sets the total number of nodes in the graph. 
	- Then it uses nested loops to initialize all cells in the adjacency matrix to 0, which indicates that there are no edges initially. 


**2. `void  add_edge_to_graph(Graph* g,  int s,  int d)`** 
- This function adds an undirected edge between source node `s` and destination node `d`. 
-  **Working:** 
	- It first validates that both `s` and `d` are within the valid node range  (0 to nodes-1). 
	- Then it sets both `a_matrix[s][d]  =  1` and `a_matrix[d][s]  =  1` to create a bidirectional connection between the two nodes. 

**3. `void  display_graph(Graph* g)`** 
- This function prints the adjacency matrix representation of the graph to the console. 
-  **Working:** 
- It uses nested loops to traverse and print each element of the adjacency matrix in a readable format. 

**5. `void  bfs(Graph* g,  int startnode)`** 
- This function performs Breadth-First Search traversal starting from the given node. 
-  **Working:** 
	- It initializes a boolean array `visited_nodes[]` to keep track of which nodes have already been visited. 
	- It creates and initializes a queue to manage the order of node exploration. 
	- The starting node is marked as visited and enqueued. - While the queue is not empty, the function does the following: 
	- It dequeues a node and prints it. - It checks all adjacent nodes by scanning through that node's row in the adjacency matrix. 
	- For each unvisited adjacent node  (where `a_matrix[curr_node][i]  ==  1` and the node hasn't been visited), it marks the node as visited and enqueues it. 
	- This approach explores the graph level by level, visiting all neighbors of a node before moving to the next level of nodes.

**13. `void dfs(Graph* g,  int startnode)`** 
- This function performs Depth-First Search traversal starting from the given node. 
-  **Working:** 
	- It initializes a boolean array `visited_nodes[]` to track which nodes have been visited. 
	- It creates and initializes a stack to manage the exploration order. 
	- The starting node is marked as visited and pushed onto the stack. 
	- While the stack is not empty, the function does the following: - It pops a node from the stack and prints it. 
	- It checks all adjacent nodes by looking through that node's row in the adjacency matrix. 
	- For each unvisited adjacent node  (where `a_matrix[curr_node][i]  ==  1` and the node hasn't been visited), it marks the node as visited and pushes it onto the stack. - This approach explores the graph by going as deep as possible along each branch before backtracking to explore other branches.

## Organization of the main() Method
It is the entry point of the program that demonstrates how to create a graph and perform traversals on it. 
-  **Working:** 
	- It declares a graph structure and specifies that it will have 5  nodes. 
	- It initializes the graph using `init_graph()`. 
	- It adds edges to create the graph.
	- It displays the adjacency matrix so we can see the graph's structure. 
	- It performs BFS traversal starting from node 0 and prints the result. 
	- It performs DFS traversal starting from node 0 and prints the result.
## Sample Output 

```bash
Adjacency Matrix:
0 1 1 0 0 
1 0 0 1 1 
1 0 0 0 0 
0 1 0 0 0 
0 1 0 0 0 
BFS Traversal of the graph is:
0 1 2 3 4 
DFS Traversal of the graph is:
0 2 1 4 3 
```

