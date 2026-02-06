#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* HEAD;
Node* TAIL;

void init_list(){
    HEAD = NULL;
    TAIL = NULL;
}

int isEmpty() {
    return HEAD == NULL;
}

void add_to_tail(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (isEmpty()) {
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

    if (isEmpty()) {
        TAIL = new_node;
    }
    HEAD = new_node;
}

void traverse_list(){
    Node* p = HEAD;
    printf("Regular Traversal is: ");
    while (p->next!= NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

void reverse_traverse(Node* p){
    if (p == NULL)
        return;

    reverse_traverse(p->next);

    if (p != HEAD)
        printf("%d->", p->data);
    else
        printf("%d", p->data);
}

int main(){
    init_list();
    add_to_tail(10);
    add_to_head(20);
    add_to_tail(30);
    traverse_list();
    printf("Reverse Traversal is: ");
    reverse_traverse(HEAD);
}