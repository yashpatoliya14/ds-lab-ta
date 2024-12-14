#include <stdio.h>

#define MAX_SIZE 100

// Stack data structure
int stack[MAX_SIZE];
int top = -1;

// Push element onto the stack
void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    top--;
    return stack[top + 1];
}

// Change the nth element from the top of the stack based on the provided algorithm
void change(int i, int new_value) {
    if (top - i + 1 < 0) {
        printf("Stack underflow!\n");
        return;
    }

    int index = top - i + 1;
    stack[index] = new_value;

    return;
}

int peep(int i) {
    if (top - i + 1 < 0) {
        printf("Stack underflow!\n");
        return -1;  
    }

    int index = top - i + 1;
    return stack[index];
}

// Display stack contents
void displayStack() {
    printf("Current Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    displayStack();

    int value = peep(2);
    if (value != 0) {
        printf("Peeped 2nd element from top: %d\n", value);
    }

    change(3, 99);
    displayStack();

    return 0;
}
