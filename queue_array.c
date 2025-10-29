#include <stdio.h>
# define MAX 10

int queue[MAX];
int f = 0;
int r = 0;

int isFull(){
    if(r == MAX){
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(r == 0 || f > r){
        return 1;
    }
    return 0;

}

void enqueue(int val){
    if(isFull()) {
        printf("The queue is full.\n");
        return;
    }
    queue[r++] = val;
    printf("%d is enqueued in queue.\n", val);
}

void dequeue(){
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    printf("%d is dequeued from queue.\n", queue[f]);
    f++;

    if(f == r){
        f = r = 0;
        printf("The queue is now empty.\n");
    }
    
}

void front(){
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    printf("The front element is: %d\n", queue[f]);
}

void rear(){
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    printf("The rear element is: %d\n", queue[r - 1]);
}

void size(){
    printf("The size of the queue is: %d\n", r-f);
}

void display(){
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    if(r-f == 0){
        printf("The queue is empty.\n");
        return;
    }
    printf("Elements in queue are: ");
    for(int i=f; i<r; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int emp1 = isEmpty();
    if(emp1 == 1){
        printf("The queue is empty.\n");
    }
    else{
        printf("The queue is not empty.\n");
    }
    
    enqueue(2);
    enqueue(4);
    enqueue(6);
    display();
    
    size();
    front();
    rear();
    
    dequeue();
    display();
    
    enqueue(8);
    enqueue(10);
    display();
    
    size();
    int emp2 = isEmpty();
    if(emp2 == 1){
        printf("The queue is empty.\n");
    }
    else{
        printf("The queue is not empty.\n");
    }
    
    return 0;
}