#include <bits/stdc++.h>
using namespace std;

struct Stack {
    queue<int> q1, q2;

    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element into q1
        q1.push(x);
        printf("%d is pushed.\n", x);

        // Move all elements back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (q1.empty()) {
            printf("The stack is empty.\n");
            return;
        }
        printf("%d is popped.\n", q1.front());
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            printf("The stack is empty.\n");
            return;
        }
        printf("The top element is: %d\n", q1.front());
    }

    void size() {
        printf("The size of the stack is: %lu\n", q1.size());
    }

    void isEmpty() {
        if (q1.empty()) {
            printf("The stack is empty.\n");
        } else {
            printf("The stack is not empty.\n");
        }
    }
};

int main() {
    Stack s;
    s.isEmpty();
    s.push(1);
    s.push(2);
    s.push(3);

    s.size();
    s.top();

    s.pop();
    s.pop();

    s.push(4);
    s.push(5);

    s.isEmpty();
    s.size();

    return 0;
}
