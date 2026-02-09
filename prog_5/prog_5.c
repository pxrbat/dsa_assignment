#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30

typedef struct{
    int items[MAX];
    int front;
    int rear;
}Queue;

typedef struct{
    int items[MAX];
    int top;
} Stack;

typedef struct{
    int nodes;
    int a_matrix[MAX][MAX];
}Graph;

void init_q(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool is_q_empty(Queue* q){
    return q->front == -1;
}

void enqueue(Queue* q, int data){
    if(q->rear == MAX - 1){
        printf("Queue Overflow\n");
        return;
    }
    if(is_q_empty(q)){
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = data;
}

int dequeue(Queue* q){
    if (is_q_empty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q->items[q->front];
    if (q->front == q->rear) {
        init_q(q);
    }
    else{
        q->front++;
    }
    return data;
}

void init_s(Stack* s) {
    s->top = -1;
}

bool is_s_empty(Stack* s){
    return s->top== -1;
}

void push(Stack* s, int data) {
    if(s->top ==MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = data;
}

int pop(Stack* s) 
{
    if (is_s_empty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    int data = s->items[s->top];
    s->top--;
    return data;
}

void init_graph(Graph* g, int nodes){
    g->nodes=nodes;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            g->a_matrix[i][j] = 0;
        }
    }
}

void add_edge_to_graph(Graph* g, int s, int d){
    if(s>=0 && s<g->nodes && d>=0 &&d<g->nodes){
        g->a_matrix[s][d] = 1;
        g->a_matrix[d][s] = 1;
    }
}

void display_graph(Graph* g){
    printf("Adjacency Matrix:\n");
    for(int i=0; i<g->nodes; i++){
        for(int j=0; j<g->nodes; j++){
            printf("%d ", g->a_matrix[i][j]);
        }
        printf("\n");
    }
}

void bfs(Graph* g, int startnode){
    bool visited_nodes[MAX] = {false};
    Queue q;
    init_q(&q);
    printf("BFS Traversal of the graph is:\n");
    visited_nodes[startnode] = true;
    enqueue(&q, startnode);

    while(!is_q_empty(&q))
    {
        int curr_node = dequeue(&q);
        printf("%d " ,curr_node);
        for(int i=0; i<g->nodes; i++){
            if(g->a_matrix[curr_node][i] == 1 && !visited_nodes[i]){
                visited_nodes[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

void dfs(Graph* g, int startnode){
    bool visited_nodes[MAX] = {false};
    Stack s;
    init_s(&s);
    printf("DFS Traversal of the graph is:\n");
    visited_nodes[startnode] = true;
    push(&s, startnode);

    while(!is_s_empty(&s))
    {
        int curr_node = pop(&s);
        printf("%d " ,curr_node);
        for(int i=0; i<g->nodes; i++){
            if(g->a_matrix[curr_node][i] == 1 && !visited_nodes[i]){
                visited_nodes[i] = true;
                push(&s, i);
            }
        }
    }
    printf("\n");
}

int main(){
    Graph g;
    int nodes = 5;
    init_graph(&g, nodes);
    add_edge_to_graph(&g, 0, 1);
    add_edge_to_graph(&g, 0, 2);
    add_edge_to_graph(&g, 1, 3);
    add_edge_to_graph(&g, 1, 4);
    display_graph(&g);
    bfs(&g, 0);
    dfs(&g, 0);
}