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
        printf("memory error.\n");
        return NULL;
    }
    int x;
    printf("Enter number: ");
    scanf("%d", &x);

    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

void insert_at_beginning()
{
    Node *newNode = create_node();
    if (!newNode)
        return;

    newNode->next = head;
    head = newNode;
}

void insert_at_end()
{
    Node *newNode = create_node();
    if (!newNode)
        return;

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_at_position()
{

    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 0)
    {
        insert_at_beginning();
        return;
    }

    Node *newNode = create_node();
    if (!newNode)
        return;

    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        printf("out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_at_beginning()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }
    if (!head->next)
    {
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = NULL;
    free(del);
}

void delete_at_position()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 0)
    {
        delete_at_beginning();
        return;
    }

    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    Node *temp = head;

    for (int i = 0; i < pos - 1 && temp; i++)
    {
        temp = temp->next;
    }

    if (!temp || !temp->next)
    {
        printf("positoin out of bounds.\n");
        return;
    }

    Node *to_del = temp->next;
    temp->next = to_del->next;
    free(to_del);
}
void display_list()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    Node *temp = head;

    while (temp)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void count_nodes()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    Node *temp = head;

    int counter = 0;

    while (temp)
    {
        counter++;
        temp = temp->next;
    }
    printf("%d\n", counter);
}

void search_node()
{
    if (!head)
    {
        printf("no list.\n");
        return;
    }

    Node *temp = head;

    int keyword;
    printf("Enter keyword: ");
    scanf("%d", &keyword);

    int pos = -1;

    for (int i = 0; temp && pos == -1; i++)
    {
        if (temp->data == keyword)
        {
            pos = i;
        }
            temp = temp->next;

    }

    if (pos == -1)
    {
        printf("not found.\n");
        return;
    }
    printf("element found. %d\n", pos);
}

void sort_list()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    for (Node *i = head; i; i = i->next)
    {
        for (Node *j = i->next; j; j = j->next)
        {
            if (j->data < i->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse_list()
{
    if (!head)
    {
        printf("empty list.\n");
        return;
    }

    Node *prev = NULL;
    Node *curr = head;

    while(curr){
        Node *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;

}

int main()
{
    int run = 1;
    while (run)
    {
        int choice;
        printf("Menu: \n1. Insert at beginning\t2. Insert at end\t3. Insert at position\n4. Delete at beginning\t5. Delete at end\t6. Delete at position\n7. Display list\t8. Count nodes\t9. Search node\n10. Sort list\t11. Reverse list\t12. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_beginning();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            delete_at_beginning();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            delete_at_position();
            break;
        case 7:
            display_list();
            break;
        case 8:
            count_nodes();
            break;
        case 9:
            search_node();
            break;
        case 10:
            sort_list();
            break;
        case 11:
            reverse_list();
            break;
        case 12:
            run = 0;
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}