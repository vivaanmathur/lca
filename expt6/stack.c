#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack is full.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;
    printf("Value pushed.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Popped value: %d\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top value: %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main(void)
{
    int choice;

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Program ended.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}