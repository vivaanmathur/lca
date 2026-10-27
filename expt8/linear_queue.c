// Linear Queue

#include <stdio.h>
#include <string.h>

typedef struct PrintJob
{
    int jobID;
    char title[100];
} PrintJob;

void isFull(PrintJob queue[], int n, int rear)
{
    if (rear == n - 1)
    {
        printf("Queue is Full.\n");
    }
    else
    {
        printf("Queue is not Full.\n");
    }
}

void isEmpty(PrintJob queue[], int front)
{
    if (front == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Queue is not Empty.\n");
    }
}

void enqueue(PrintJob queue[], int *front, int *rear, int n)
{
    if (*rear == n - 1)
    {
        printf("Queue is Full. Cannot enqueue.\n");
        return;
    }

    (*rear)++;

    if (*front == -1)
    {
        *front = 0;
    }

    printf("Enter Job ID: ");
    scanf("%d", &queue[*rear].jobID);

    printf("Enter Job Title: ");
    scanf(" %[^\n]", queue[*rear].title);

    printf("Job enqueued successfully.\n");
}

void dequeue(PrintJob queue[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is Empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued Job:\n");
    printf("Job ID: %d\n", queue[*front].jobID);
    printf("Job Title: %s\n", queue[*front].title);

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        (*front)++;
    }
}

void display(PrintJob queue[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }

    printf("\nPrint Queue:\n");

    for (int i = front; i <= rear; i++)
    {
        printf("Element %d:\n", i - front + 1);
        printf("Job ID: %d\n", queue[i].jobID);
        printf("Job Title: %s\n", queue[i].title);
    }
}

int main()
{
    int n;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    PrintJob queue[n];

    int front = -1, rear = -1;
    int run = 1;

    do
    {
        int choice = -1;

        printf("\nMenu:\n");
        printf("1. Add new Print Job\n");
        printf("2. Complete printing \n");

        printf("3. Display all Print Jobs\n");
        printf("4. Exit\n");

        printf("Enter a value: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(queue, &front, &rear, n);
            break;

        case 2:
            dequeue(queue, &front, &rear);
            break;

        case 3:
            display(queue, front, rear);
            break;

        case 4:
            run = 0;
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (run == 1);

    return 0;
}