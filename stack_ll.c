// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;
int s = 0;

struct Node *create(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void isEmpty(){
    if(head == NULL){
        printf("The stack is empty.\n");
        return;
    }
    printf("The stack is not empty.\n");
}

void push(int data){
    struct Node *newnode = create(data);
    if(head == NULL){
        head = newnode;
        s++;
        printf("%d is pushed in stack.\n", head->data);
        return;
    }
    newnode->next = head;
    head = newnode;
    s++;
    printf("%d is pushed in stack.\n", head->data);
}

void pop(){
    if(head == NULL){
        printf("stack underflow.\n");
        return;
    }
    struct Node *del = head;
    head = head->next;
    s--;
    printf("%d is poped from stack.\n", del->data);
    free(del);
}

void peek(){
    if(head == NULL){
        printf("The stack is empty.\n");
        return;
    }
    printf("The peek element is: %d\n", head->data);
}
void size(){
    printf("The size of the stack is: %d\n", s);
}

void display(){
    if(head == NULL){
        printf("The stack is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Elements in stack are: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    isEmpty();
    
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
    isEmpty();
    

    return 0;
}