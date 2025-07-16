#include <stdio.h>
# define MAX 10

int stack[MAX];
int top = -1;
int s = 0;

int isFull(){
    if(top == MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void push(int val){
    if(isFull()){
        printf("stack overflow.\n");
        return;
    }
    stack[++top] = val;
    s++;
    printf("%d is pushed in stack.\n", val);
}

void pop(){
    if(isEmpty()){
        printf("stack underflow.\n");
        return;
    }
    printf("%d is poped from stack.\n", stack[top]);
    top--;
    s--;
}

void peek(){
    if(isEmpty()){
        printf("stack underflow.\n");
        return;
    }
    printf("The peek element is: %d\n", stack[top]);
}

void size(){
    printf("The size of the stack is: %d\n", s);
}

void display(){
    if(top == -1){
        printf("The stack is empty.\n");
        return;
    }
    printf("Elements in stack are: ");
    for(int i=top; i>=0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int emp1 = isEmpty();
    if(emp1 == 1){
        printf("The stack is empty.\n");
    }
    else{
        printf("The stack is not empty.\n");
    }
    
    push(2);
    push(4);
    push(6);
    display();
    
    size();
    peek();
    
    pop();
    display();
    
    push(8);
    push(10);
    display();
    
    size();
    int emp2 = isEmpty();
    if(emp2 == 1){
        printf("The stack is empty.\n");
    }
    else{
        printf("The stack is not empty.\n");
    }
    
    return 0;
}