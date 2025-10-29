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
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue is not empty.\n");
}

void enqueue(int data){
    struct Node *newnode = create(data);
    if(head == NULL){
        head = newnode;
        s++;
        printf("%d is enqueued in queue.\n", head->data);
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    s++;
    printf("%d is enqueued in queue.\n", newnode->data);
}

void dequeue(){
    if(head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    struct Node *del = head;
    head = head->next;
    s--;
    printf("%d is dequeued from queue.\n", del->data);
    free(del);
}

void front(){
    if(head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    printf("The fron element is: %d\n", head->data);
}

void back(){
    if(head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("The back element is: %d\n", temp->data);
}

void size(){
    printf("The size of queue is: %d\n", s);
}

void display(){
    if(head == NULL){
        printf("The queue is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Elements in queue are: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    isEmpty();
    
    enqueue(2);
    enqueue(4);
    enqueue(6);
    display();
    
    size();
    
    front();
    back();
    
    dequeue();
    display();
    
    enqueue(8);
    enqueue(10);
    display();
    
    size();
    isEmpty();
    
    

    return 0;
}