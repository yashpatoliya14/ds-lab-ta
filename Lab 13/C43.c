#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueueRear(int value) {
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

void enqueueFront(int value) {
    // Check for Queue Overflow
    if ((front == 1 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) { // If queue is empty
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front = front - 1;
        }
        queue[front] = value;
        printf("Enqueued %d at the front\n", value);
    }
}

int dequeueFront() {
    // Check for Queue Underflow
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int temp = queue[front];

    // Check if single element is left in Queue
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("Dequeued %d from the front\n", temp);
    return temp;
}

int dequeueRear() {
    // Check for Queue Underflow
    if (rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int temp = queue[rear];

    // Check if single element is left in Queue
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear = rear - 1;
    }

    printf("Dequeued %d from the rear\n", temp);
    return temp;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue Rear\n2. Enqueue Front\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at the rear: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 2:
                printf("Enter value to enqueue at the front: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
