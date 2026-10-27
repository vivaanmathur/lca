#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *create_node()
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("Error!\n");
        return NULL;
    }

    int val;
    printf("Enter val: ");
    scanf("%d", &val);
    newNode->data = val;

    newNode->next = NULL;

    return newNode;
}

void insert_node()
{
    Node *newNode = create_node();
    if (!newNode)
    {
        return;
    }

    if (!head)
    {
        head = newNode;
        newNode->next = head;

        return;
    }

    newNode->next = head;

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display_list()
{
    if (!head)
    {
        printf("List empty!\n");
        return;
    }

    Node *temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1 || choice == 3)
        {
            printf("Exiting...\n");
            break;
        }

        switch (choice)
        {
        case 1:
            insert_node();
            break;
        case 2:
            display_list();
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}