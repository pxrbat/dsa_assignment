#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 20

char operator_stack[MAX];
int top_op = -1;

char value_stack[MAX];
int top_val = -1;

void push_op(char op){
    if(top_op == MAX-1){
        printf("Operator Stack Overflow\n");
        return;
    }
    operator_stack[++top_op] = op;
}

char pop_op(){
    if(top_op == -1){
        printf("Operator Stack Underflow\n");
        return '\0';
    }
    return operator_stack[top_op--];
}

int push_val(char val){
    if (top_val == MAX-1){
        printf("Value Stack Overflow\n");
        return -1;
    }
    value_stack[++top_val] = val;
    return 0;
}

int pop_val(){
    if (top_val == -1){
        printf("Value Stack Underflow\n");
        return -1;
    }
    return value_stack[top_val--];
}

int prec(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

bool is_right_assoc(char op){
    return op == '^';
}

int operator_eval(int a, int b, char op){
    switch(op){
        case '+': 
            return a + b;
        case '-': 
            return a - b;
        case '*': 
            return a * b;
        case '/': 
            return a / b;
        case '^': {
            int res = 1;
            for(int i = 0; i < b; i++)
                res *= a;
            return res;
        }
        default: 
            return 0;
    }
}

void infix_to_postfix(char* infix, char* postfix){
    int k = 0;
    char ch;
    for(int i = 0; infix[i] != '\0'; i++){
        ch = infix[i];
        if(isdigit(ch)){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            push_op(ch);
        }
        else if(ch == ')'){
            while(top_op != -1 && operator_stack[top_op] != '('){
                postfix[k++] = pop_op();
            }
            pop_op();
        }
        else{
            while(top_op != -1 && prec(operator_stack[top_op]) >= prec(ch)&&
                  !is_right_assoc(ch)){
                postfix[k++] = pop_op();
            }
            push_op(ch);
        }
    }
    while(top_op != -1){
        postfix[k++] = pop_op();
    }
    postfix[k] = '\0';
    printf("Equivalent Postfix Expression is: %s\n", postfix);
}

int postfix_eval(char* postfix){
    char ch;
    for(int i=0;postfix[i]!='\0'; i++){
        ch = postfix[i];
        if(isdigit(ch)){
            push_val(ch - '0');
        }
        else{
            int b = pop_val();
            int a = pop_val();
            int res = operator_eval(a, b, ch);
            push_val(res);
        }
    }
    return pop_val();
}

int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    
    printf("Given Infix Expression is: %s\n", infix);
    
    infix_to_postfix(infix, postfix);
    
    int result = postfix_eval(postfix);
    printf("The result is: %d\n", result);
    return 0;
}