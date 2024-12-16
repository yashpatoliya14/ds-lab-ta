#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int F = -1;
int R = -1;

//change in simple----------------------------------------------------------- 
void CQInsert(int value) {
    // Check for Queue Overflow
    if (R == SIZE - 1) {
            R = 0;  
    } else {
            R++;  
    }

    if (F==R) {
        printf("Queue is full!\n");
    } else {        
        queue[R] = value;  // Insert the new value
    }
}


int dequeue() {
    // Check for Queue Underflow
    if (F == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    // Delete element
    int item = queue[F];
    
    // Check if single element is left in Queue
    if (F == R) {
        F = R = -1;
    } else {
        F = (F + 1) % SIZE;
    }

    printf("Dequeued %d\n", item);
    return item;
}

void display() {
    if (F == -1) {
        printf("Queue is empty!\n");
    } else {
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
        printf("\n1. CQInsert\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to CQInsert: ");
                scanf("%d", &value);
                CQInsert(value);
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
