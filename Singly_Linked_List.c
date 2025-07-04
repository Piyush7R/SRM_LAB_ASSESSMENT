#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node *create(int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beg(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void insert_at_pos(int data,int pos){
    struct Node *new_node = create(data);
    if(pos <= 0){
        printf("Invalid Position.\n");
        free(new_node);
        return;
    }

    if(pos == 1){
        insert_at_beg(data);
        return;
    }
    struct Node *temp = head;
    int count = 1;
    while(count < pos-1 && temp!= NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Invalid position \n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_at_end(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_at_beg(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *del = head;
    head  = head->next;
    free(del);
}

void delete_at_pos(int pos){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(pos <= 0){
        printf("Invalid Position.\n");
        return;
    }

    if(pos == 1){
        delete_at_beg();
        return;
    }
    struct Node *temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != NULL){
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}

void delete_at_end(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void calc_length(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("The length of the list is: %d \n", count);
}

void reverse_list(){
    if(head == NULL || head->next == NULL){   // either list is empty or only 1 node is present
        return;
    }
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    head = prev;
}

int find_middle(){
    if (head == NULL) {
        printf("List is empty.\n");
        return -1;
    }
    
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void display(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    calc_length();
    
    insert_at_beg(3);
    insert_at_beg(2);
    insert_at_beg(1);
    display();

    insert_at_end(5);
    insert_at_end(6);
    insert_at_end(7);
    display();
    
    insert_at_pos(4,4);
    display();
    
    calc_length();

    delete_at_beg();
    display();

    delete_at_end();
    display();
    
    delete_at_pos(2);
    display();
    
    int mid = find_middle();
    if (mid != -1)
    printf("Middle element is: %d\n", mid);
    
    reverse_list();
    printf("List after reversing: ");
    display();
    
    


    return 0;
}