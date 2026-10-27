#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("queue full.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    int val;
    printf("enter value: ");
    scanf("%d", &val);

    rear++;
    queue[rear] = val;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty.\n");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("queue is empty.\n");
        return;
    }

    printf("displaying:\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
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