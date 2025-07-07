#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beg(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        new_node->next = new_node;
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    new_node->next = head;
    temp->next = new_node;
    head = new_node;
}

void insert_at_end(int data){
    struct Node *new_node = create(data);
    if(head == NULL){
        new_node->next = new_node;
        head = new_node;
        return;
    }
    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    new_node->next = head;
    temp->next = new_node;
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
    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }
    if (count != pos - 1) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_beg(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    
    struct Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    struct Node *del = head;
    temp->next = head->next;
    head = head->next;
    free(del);
}

void delete_at_end(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    
    struct Node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    struct Node *del = temp->next;
    temp->next = head;
    free(del);
    
}

void delete_at_pos(int pos){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    if(pos == 1){
        delete_at_beg();
        return;
    }
    
    struct Node *temp = head;
    int count = 1;
    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }
    if(temp->next == head || count != pos-1){
        printf("Invalid Positon.\n");
        return;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void calc_length(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    int count = 1;
    struct Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }

    printf("The length of the list is: %d\n", count);
}

int is_cyclic(){
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return 1;   // cycle detected
        }
    }
    return 0;   // No cycle detected
}

void display(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
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
    
    delete_at_pos(3);
    display();
    
    int result = is_cyclic();
    if(result == 1){
        printf("The List is Cyclic\n");
    }
    else{
        printf("The List is not Cyclic\n");
    }
    
    
    return 0;
}