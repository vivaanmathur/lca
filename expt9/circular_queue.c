// Circular Queue

#include <stdio.h>
#include <string.h>

typedef struct PrintJob
{ 
    int jobID;
    char title[100];
} PrintJob;

int isFull(PrintJob queue[], int n, int front, int rear)
{
    if ((rear + 1) % n == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(PrintJob queue[], int front)
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(PrintJob queue[], int *front, int *rear, int n)
{
    if (isFull(queue, n, *front, *rear))
    {
        printf("printer overloaded :( \n");
        return;
    }

    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % n;
    }

    printf("Enter Job ID: ");
    scanf("%d", &queue[*rear].jobID);

    printf("Enter Job Title: ");
    scanf(" %[^\n]", queue[*rear].title);

    printf("Job enqueued successfully.\n");
}

void dequeue(PrintJob queue[], int *front, int *rear, int n)
{
    if (isEmpty(queue, *front))
    {
        printf("Printer has nothing to print. \n");
        return;
    }

    printf("Printing now..:\n");
    printf("Job ID: %d\n", queue[*front].jobID);
    printf("Job Title: %s\n", queue[*front].title);

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % n;
    }
}

void display(PrintJob queue[], int front, int rear, int n)
{
    if (front == -1)
    {
        printf("Printer has nothing to print!!\n");
        return;
    }

    printf("\nPrint Queue:\n");

    int i = front;
    int count = 1;

    while (1)
    {
        printf("Element %d:\n", count);
        printf("Job ID: %d\n", queue[i].jobID);
        printf("Job Title: %s\n", queue[i].title);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % n;
        count++;
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
        printf("2. Complete printing\n");
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
            dequeue(queue, &front, &rear, n);
            break;

        case 3:
            display(queue, front, rear, n);
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