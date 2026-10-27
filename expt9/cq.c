#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    queue[rear] = val;
    printf("Value inserted.\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Deleted value: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Program ended.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}