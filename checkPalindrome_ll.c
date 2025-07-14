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

void checkPalindrome(struct Node *head){
    if (head == NULL || head->next == NULL) {
        printf("List is a Palindrome.\n");
        return;
    }
    
    struct Node *slow = head;
    struct Node *fast = head;
    
    // find the middle element
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct Node *curr = slow->next;
    slow->next = NULL;
    struct Node *prev = NULL;
    struct Node *nxt = NULL;
    
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    curr = prev;
    
    while(curr != NULL){
        if(head->data != curr->data){
            printf("List is not a Palindrome.\n");
            return;
        }
        curr = curr->next;
        head = head->next;
    }
    printf("List is a Palindrome.\n");
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
    head1->next->next->next = createNode(2);
    head1->next->next->next->next = createNode(1);

    printf("List: ");
    display(head1);
    
    checkPalindrome(head1);

    return 0;
}