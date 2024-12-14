#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    // Check for Queue Overflow
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    // Increment REAR pointer
    rear++;

    // Insert element
    queue[rear] = value;

    // Is front pointer properly set?
    if (front == -1) {
        front = 0;
    }

    printf("Enqueued %d\n", value);
}

int dequeue() {
    // Check for Queue Underflow
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int item = queue[front];

    // Check if single element left in Queue
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    printf("Dequeued %d\n", item);
    return item;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
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
