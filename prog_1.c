#include <stdio.h>
#include <stdlib.h>

#define MAX 20
char stack[MAX], top = -1;

void push(int data){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void evaluate_parentheses(char *expression){
    char ch;
    for (int i = 0; expression[i] != '\0'; i++){
        ch = expression[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if (top == -1){
                printf("There is a closing parenthesis '%c' with no matching opening parenthesis, so, the expression does not have balanced number of parentheses.\n", ch);
                return;
            }
            char popped = pop();
            if((ch == ')' && popped!='(') || (ch == '}' && popped!= '{') || (ch == ']' && popped!='[')){
                printf("The expression does not have a balanced number of parentheses as '%c' does not match '%c'\n", ch, popped);
                return;
            }
        }
    }
    if(top == -1){
        printf("The expression has balanced number of parentheses.\n");
    } else {
        printf("The number of parentheses in this expression is not balanced because there is an opening parenthesis '%c' with no matching closing parenthesis.\n",stack[top]);
    }
}

int main(){
    char expression[MAX];
    printf("Enter any expression with parentheses: ");
    scanf("%s", expression);
    evaluate_parentheses(expression);
    return 0;
}