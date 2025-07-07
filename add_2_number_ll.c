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

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);
    struct Node* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = (l1 != NULL) ? l1->data : 0;
        int val2 = (l2 != NULL) ? l2->data : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        current->next = createNode(sum % 10);
        current = current->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    return dummy->next;
}

void display(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // First linked list: 2 -> 4 -> 3
    struct Node *head1 = createNode(2);
    head1->next = createNode(4);
    head1->next->next = createNode(3);

    // Second linked list: 5 -> 6 -> 4
    struct Node *head2 = createNode(5);
    head2->next = createNode(6);
    head2->next->next = createNode(4);

    printf("First List is: ");
    display(head1);

    printf("Second List is: ");
    display(head2);

    printf("Sum of 2 list is: ");
    struct Node *head = addTwoNumbers(head1, head2);
    display(head);

    return 0;
}