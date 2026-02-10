
# Documentation for prog_7.c
## Finding Shortest Paths in a Weighted Graph using Dijkstra's Algorithm

This program implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a weighted, undirected graph using an adjacency matrix representation.

## What is Dijkstra's Algorithm?

Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a source vertex to all other vertices in a weighted graph. It repeatedly selects the unvisited vertex with the smallest distance and updates distances to its neighbors.



## Data Structures Used

### Graph Structure
The graph structure contains the number of nodes and the adjacency matrix.

```c
```c
typedef struct{
    int nodes;
    int a_matrix[MAX][MAX];
}Graph;
```
`nodes` stores the total number of nodes in the graph and `a_matrix[MAX][MAX]` is the 2D adjacency matrix. `INFINITY` is defined as `9999999` to represent the absence of an edge.

## Functions Description

**1. `void init_graph(Graph* g, int nodes)`**
- This function initializes the weighted graph with specified number of nodes.
- It sets diagonal elements to 0 and all other elements to INFINITY.


**2. `void add_edge_to_graph(Graph* g, int s, int d, int w)`**
- This function adds a weighted edge between vertices s and d with weight w.
- For undirected graphs, it sets both `a_matrix[s][d]` and `a_matrix[d][s]` to w.


**3. `void display_graph(Graph* g)`**
- This function prints the weighted adjacency matrix.
- It displays "Inf" for INFINITY values to improve readability.


**4. `int min_distance(int d[], bool visited[], int nodes)`**
- This function finds the unvisited vertex with minimum distance from source.
- It scans all vertices and returns the index of the one with smallest distance that hasn't been visited.
- This implements the greedy selection in Dijkstra's algorithm.


**5. `void print_path(int p[], int d)`**
- This function recursively prints the shortest path from source to destination vertex d.
- It uses the parent array to backtrack from destination to source.
- The base case is when `p[d] == -1` (reached the source).



**6. `void print_soln(int d[], int p[], int nodes, int s)`**
- This function prints the complete solution with distances and paths.
- For each vertex, it displays its distance from source and the actual path.
- It handles unreachable nodes by checking if distance equals INFINITY.


**7. `void dijkstra(Graph* g, int s)`**
- This is the main implementation of Dijkstra's algorithm.
- **Working:**
  - **Initialization:** Sets all distances to INFINITY, parents to -1, vertices as unvisited, and source distance to 0.
  - **Main Loop:** For each iteration:
    - It finds the unvisited vertex u with minimum distance using `min_distance()`.
    - It marks u as visited.
    - For each neighbor v of u, if going through u provides a shorter path, it updates the distance and parent of v.
  - **Output:** Calls `print_soln()` to display results.


**8. `int main()`**
- This is the program entry point that demonstrates the algorithm.
- It creates a 5-node graph, adds weighted edges, displays the matrix, and runs Dijkstra's algorithm from node 0.

## Sample Output
```
Weighted Adjacency Matrix:
0       10      5       Inf     Inf
10      0       3       1       Inf
5       3       0       9       2
Inf     1       9       0       4
Inf     Inf     2       4       0
Shortest paths from node 0 are:
Node 0: Distance = 0, Path = 0 
Node 1: Distance = 8, Path = 0  -> 2  -> 1 
Node 2: Distance = 5, Path = 0  -> 2 
Node 3: Distance = 9, Path = 0  -> 2  -> 1  -> 3 
Node 4: Distance = 7, Path = 0  -> 2  -> 4 
```


