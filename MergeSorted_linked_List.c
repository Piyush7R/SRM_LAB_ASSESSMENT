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

struct Node *sortedMerge(struct Node *head1, struct Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    if(head1->data <= head2->data){
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else{
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

void display(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // First linked list: 5 -> 10 -> 15
    struct Node *head1 = createNode(5);
    head1->next = createNode(10);
    head1->next->next = createNode(15);

    // Second linked list: 2 -> 3 -> 20
    struct Node *head2 = createNode(2);
    head2->next = createNode(3);
    head2->next->next = createNode(20);
    
    struct Node *res = sortedMerge(head1, head2);
    display(res);

    return 0;
}