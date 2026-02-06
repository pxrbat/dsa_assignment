#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* HEAD;
Node* TAIL;

void init_list(){
    HEAD = NULL;
    TAIL = NULL;
}

int is_empty() {
    return HEAD == NULL;
}

void add_to_tail(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = TAIL;
    if (is_empty()) {
        HEAD = TAIL = new_node;
    } else {
        TAIL->next = new_node;
        TAIL = new_node;
    }
}

void add_to_head(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = HEAD;
    new_node->prev = NULL;

    if (is_empty()) {
        TAIL = new_node;
    } else {
        HEAD->prev = new_node;
    }
    HEAD = new_node;
}


void traverse_list(){
    if (is_empty()) {
        printf("List is empty\n");
        return;
    }
    Node* p = HEAD;
    printf("The linked list is: ");
    while (p->next != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

void reverse_traverse(){
    if (is_empty()) {
        printf("List is empty\n");
        return;
    }
    Node* p = TAIL;
    while (p->prev != NULL) {
        printf("%d->", p->data);
        p = p->prev;
    }
    printf("%d\n", p->data);
}

void insert_after_node(int node_data, int data){
    Node* p = HEAD;
    while (p != NULL && p->data != node_data) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Node with data %d not found.\n", node_data);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = p->next;
    new_node->prev = p;

    if (p->next != NULL) {
        p->next->prev = new_node;
    } else {
        TAIL = new_node; 
    }
    p->next = new_node;
    printf("Inserted node with data %d after node with data %d\n", data, node_data);
}

int delete_node(int node_data){
    Node* p = HEAD;
    while (p != NULL && p->data != node_data) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Node with data %d not found.\n", node_data);
        return -1;
    }
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        HEAD = p->next; 
    }
    if (p->next != NULL) {
        p->next->prev = p->prev;
    } else {
        TAIL = p->prev; 
    }
    int deleted_data = p->data;
    free(p);
    return deleted_data;
}

int main(){
    init_list();
    add_to_tail(10);
    add_to_tail(20);
    add_to_tail(30);
    add_to_head(5);
    traverse_list();
    printf("Reverse Traversal of the linked list is: ");
    reverse_traverse();
    insert_after_node(20, 25);
    traverse_list();
    int deleted = delete_node(10);
    printf("Deleted node with data: %d\n", deleted);
    traverse_list();
    printf("\n");
    return 0;
}