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

struct Node *deleteMiddle(struct Node *head){
    struct Node *temp = head;
    int n = 0;
    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    
    if(n == 0){
        return head;
    }
    if(n == 1){
        return NULL;
    }
    
    int m = (int)n/2;
    struct Node *curr = head;
    while(m-1 > 0){
        curr = curr->next;
        m--;
    }
    struct Node *del = curr->next;
    curr->next = curr->next->next;
    free(del);
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
    // linked list: 2 -> 4 -> 3 -> 6 -> 9
    struct Node *head1 = createNode(2);
    head1->next = createNode(4);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(6);
    head1->next->next->next->next = createNode(9);


    printf("List before deleting middle element is: ");
    display(head1);

    printf("List after deleting middle element is: ");
    struct Node *head = deleteMiddle(head1);
    display(head);

    return 0;
}