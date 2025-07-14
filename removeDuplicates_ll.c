#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node *deleteDuplicates(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            struct Node *del = temp->next;
            temp->next = del->next;
            free(del);   // Do not move temp forward — check new temp->next
        }
        else{
            temp = temp->next;
        }
        
    }
    return head;
}

void display(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = createNode(11);
    head->next = createNode(11);
    head->next->next = createNode(11);
    head->next->next->next = createNode(21);
    head->next->next->next->next = createNode(43);
    head->next->next->next->next->next = createNode(43);
    head->next->next->next->next->next->next = createNode(60);
    
    printf("Linked list before duplicate removal:\n");
    display(head);

    printf("Linked list after duplicate removal:\n");
    head = deleteDuplicates(head);
    display(head);

    return 0;
}