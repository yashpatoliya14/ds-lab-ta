#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int F = -1;
int R = -1;

void DQinsert_R(int value) {
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

void DQinsert_front(int value) {
    // Check for Queue Overflow
    if (F == 0) {
        printf("Queue is full!\n");
    } else {
        if (F == -1) { // If queue is empty
            F = 0;
            R = 0;
        } else {
            F = F - 1;
        }
        queue[F] = value;
        printf("Enqueued %d at the F\n", value);
    }
}

int DQdelete_Front() {
    // Check for Queue Underflow
    if (F == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int temp = queue[F];

    // Check if single element is left in Queue
    if (F == R) {
        F = R = -1;
    } else {
        F = F + 1;
    }

    printf("Dequeued %d from the F\n", temp);
    return temp;
}

int DQdelete_Rear() {
    // Check for Queue Underflow
    if (R == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int temp = queue[R];

    // Check if single element is left in Queue
    if (F == R) {
        F = -1;
        R = -1;
    } else {
        R = R - 1;
    }

    printf("Dequeued %d from the R\n", temp);
    return temp;
}

void display() {
    if (F == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        int i = F;
        while (1) {
            printf("%d ", queue[i]);
            if (i == R) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Enqueue R\n2. Enqueue F\n3. Dequeue F\n4. Dequeue R\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at the R: ");
                scanf("%d", &value);
                DQinsert_R(value);
                break;
            case 2:
                printf("Enter value to enqueue at the F: ");
                scanf("%d", &value);
                DQinsert_front(value);
                break;
            case 3:
                DQdelete_Front();
                break;
            case 4:
                DQdelete_Front();R           break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
