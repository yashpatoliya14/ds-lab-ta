#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int F = -1;
int R = -1;

void enqueue(int value) {
    // Check for Queue Overflow
    if (R == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    // Increment R pointer
    R++;

    // Insert element
    queue[R] = value;

    // Is F pointer properly set?
    if (F == -1) {
        F = 0;
    }

    printf("Enqueued %d\n", value);
}

int dequeue() {
    // Check for Queue Underflow
    if (F == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int item = queue[F];

    // Check if single element left in Queue
    if (F == R) {
        F = R = -1;
    } else {
        F++;
    }

    printf("Dequeued %d\n", item);
    return item;
}

void display() {
    if (F == -1 || F > R) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = F; i <= R; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
