#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *create(int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beg(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        head = tail =new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insert_at_end(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        head = tail = new_node;
        return;
    }
    
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    // struct Node *temp = head;
    // while(temp->next != NULL){
    //     temp = temp->next;
    // }
    // temp->next = new_node;
    // new_node->prev = temp;
    // new_node->next = NULL;
    
}

void insert_at_pos(int data, int pos){
    struct Node *new_node = create(data);
    
    if(pos <= 0){
        printf("Invalid Position\n");
        free(new_node);
        return;
    }
    
    if(pos == 1){
        insert_at_beg(data);
        return;
    }
    struct Node *temp = head;
    int count = 1;
    while(pos-1 > count && temp != NULL){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Invalid Position\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (new_node->next != NULL) {
        temp->next->prev = new_node;
    }
    else {
        // If inserting at end, update tail
        tail = new_node;
    }
    temp->next = new_node;
}

void delete_at_beg(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *del = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    else {
        tail = NULL; // list became empty
    }
    free(del);
}

void delete_at_end(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = tail = NULL;
        return;
    }
    struct Node *del = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(del);
    // struct Node *temp = head;
    // while(temp->next->next != NULL){
    //     temp = temp->next;
    // }
    // struct Node *del = temp->next;
    // temp->next = NULL;
    // free(del);
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        delete_at_beg();
        return;
    }

    struct Node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;

    if (del->next != NULL) {
        del->next->prev = temp;
    } else {
        // If deleting last node, update tail
        tail = temp;
    }

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
    struct Node *curr = head;
    struct Node *temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    // Swap head and tail
    temp = head;
    head = tail;
    tail = temp;
}

void display_reverse() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
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


int main() {
    calc_length();
    
    insert_at_beg(3);
    insert_at_beg(2);
    insert_at_beg(1);
    display();
    
    insert_at_end(5);
    insert_at_end(6);
    insert_at_end(7);
    display();
    
    insert_at_pos(4,7);
    display();
    
    calc_length();
    
    delete_at_beg();
    display();
    
    delete_at_end();
    display();
    
    delete_at_pos(5);
    display();
    
    reverse_list();
    printf("List after reversing: ");
    display();
    
    display_reverse();
    
    return 0;
}