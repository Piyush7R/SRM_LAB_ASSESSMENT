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

void delete_nth_from_end(struct Node **head, int pos){
    struct Node *temp = *head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    
    if(pos <=0 || pos > n){
        printf("Invalid Position.\n");
        return;
    }
    
    if(pos == n){
        struct Node *del = *head;
        (*head) = (*head)->next;
        free(del);
        return;
    }
    
    struct Node *curr = *head;
    while(n-pos > 1){
        n--;
        curr = curr->next;
    }
    
    struct Node *del = curr->next;
    curr->next = del->next;
    free(del);
    
}

void display(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(8);
    head1->next->next->next = createNode(5);
    head1->next->next->next->next = createNode(3);

    printf("List before deletion: ");
    display(head1);
    
    delete_nth_from_end(&head1, 5);
    printf("List after deletion: ");
    display(head1);
    
    return 0;
}