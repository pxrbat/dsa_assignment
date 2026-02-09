#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30
#define INFINITY 9999999

typedef struct{
    int nodes;
    int a_matrix[MAX][MAX];
}Graph;

void init_graph(Graph* g,int nodes){
    g->nodes= nodes;
    for(int i=0; i<nodes;i++){
        for(int j=0; j<nodes; j++){
            if(i==j){
                g->a_matrix[i][j] = 0;
            }
            else{
                g->a_matrix[i][j] = INFINITY;
            }
        }
    }
}

void add_edge_to_graph(Graph* g,int s, int d, int w){
    if(s>=0 && s<g->nodes && d>=0 &&d<g->nodes){
        g->a_matrix[s][d] = w;
        g->a_matrix[d][s] = w;
    }
}

void display_graph(Graph* g){
    printf("Weighted Adjacency Matrix:\n");
    for(int i=0;i<g->nodes; i++){
        for(int j=0; j<g->nodes; j++){
            if(g->a_matrix[i][j] == INFINITY){
                printf("Inf\t");
            }
            else{
                printf("%d\t", g->a_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int min_distance(int d[], bool visited[], int nodes){
    int min = INFINITY;
    int min_idx = -1;
    for(int n=0; n<nodes; n++){
        if(!visited[n]&&d[n]<min){
            min = d[n];
            min_idx = n;
        }
    }
    return min_idx;
}

void print_path(int p[], int d){
    if(p[d] == -1){
        printf("%d ", d);
        return;
    }
    print_path(p, p[d]);
    printf(" -> %d ", d);
}

void print_soln(int d[],int p[],int nodes,int s){
    printf("Shortest paths from node %d are:\n", s);
    for(int i=0; i<nodes; i++){
        if(d[i]== INFINITY){
            printf("Node %d cannot be reached\n", i);
        }
        else{
            printf("Node %d: Distance = %d, Path = ", i, d[i]);
            print_path(p, i);
            printf("\n");
        }
    }
}

void dijkstra(Graph* g, int s){
    int d[MAX];
    int p[MAX];
    bool visited[MAX];

    for(int i=0;i<g->nodes; i++){
        d[i] = INFINITY;
        p[i] = -1;
        visited[i] = false;
    }
    d[s] = 0;
    for(int count=0; count<g->nodes-1; count++){
        int u = min_distance(d, visited, g->nodes);
        visited[u] = true;
        for(int v=0;v<g->nodes; v++){
            if(!visited[v] && g->a_matrix[u][v] != INFINITY && d[u] != INFINITY && d[u]+g->a_matrix[u][v]<d[v]){
                p[v]= u;
                d[v] = d[u]+g->a_matrix[u][v];
            }
        }
    }
    print_soln(d,p,g->nodes,s);
}

int main(){
    Graph g;
    int nodes = 5;
    init_graph(&g, nodes);
    add_edge_to_graph(&g, 0, 1, 10);
    add_edge_to_graph(&g, 0, 2, 5);
    add_edge_to_graph(&g, 1, 2, 2);
    add_edge_to_graph(&g, 1, 3, 1);
    add_edge_to_graph(&g, 2, 1, 3);
    add_edge_to_graph(&g, 2, 3, 9);
    add_edge_to_graph(&g, 2, 4, 2);
    add_edge_to_graph(&g, 3, 4, 4);
    display_graph(&g);
    dijkstra(&g, 0);
}