#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][100];
int front = -1, rear = -1;

// Add request
void enqueue() {
    char request[100];

    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter customer request: ");
    scanf(" %[^\n]", request);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    strcpy(queue[rear], request);

    printf("Request added successfully.\n");
}

// Process request
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No requests.\n");
        return;
    }

    printf("Processed Request: %s\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display requests
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nPending Requests:\n");

    i = front;
    while (1) {
        printf("%s\n", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Call Center Queue ---\n");
        printf("1. Add Request\n");
        printf("2. Process Request\n");
        printf("3. Display Requests\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
