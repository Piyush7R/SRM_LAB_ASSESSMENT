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

struct Node* rotate_ll(struct Node *head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Compute length
    struct Node *temp = head;
    int n = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: Make it circular
    temp->next = head;

    // Step 3: Find the new tail: move (n - k % n) steps
    k = k % n;
    int steps = n - k;
    while (steps--) {
        temp = temp->next;
    }
    

    // Step 4: Break the circle
    struct Node *new_head = temp->next;
    temp->next = NULL;

    return new_head;
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
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    printf("List: ");
    display(head1);
    
    struct Node *head = rotate_ll(head1, 2);
    printf("The rotated List is: ");
    display(head);

    return 0;
}