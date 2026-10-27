
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *create_node(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory error.\n");
        return NULL;
    }
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

int input(const char *str)
{
    int x;
    printf("%s", str);
    scanf("%d", &x);
    return x;
}

void insert_at_beginning()
{
    Node *new_node = create_node(input("Enter value: "));
    if (!new_node)
        return;
    if (head)
    {
        new_node->next = head;
        head->prev = new_node;
    }
    head = new_node;
}

void insert_at_end()
{
    Node *new_node = create_node(input("Enter value: "));
    if (!new_node)
        return;

    if (!head)
    {
        head = new_node;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_position()
{
    Node *new_node = create_node(input("Enter value: "));
    if (!new_node)
        return;

    int position = input("Enter position: ");
    if (position == 0)
    {
        if (head)
        {
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < position - 1 && temp; i++)
    {
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Position out of bounds.\n");
        return;
    }
    Node *preserve;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (new_node->next)
    {
        new_node->next->prev = new_node;
    }
    temp->next = new_node;
}

int is_list_empty()
{
    if (!head)
    {
        printf("Error: list is empty.\n");
        return 1;
    }
    return 0;
}
void delete_at_beginning()
{
    if (is_list_empty())
        return;
    if (!head->next)
    {
        head = NULL;
        return;
    }
    head = head->next;
    free(head->next->prev);
    head->next->prev = NULL;
}

void delete_at_end()
{
    if (is_list_empty())
        return;

    if (!head->next)
    {
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delete_at_position()
{
    if (is_list_empty())
        return;

    int position = input("Enter position: ");
    if (position == 0)
    {
        delete_at_beginning();
        return;
    }

    Node *temp = head;
    for (int i = 0; i < position - 1 && temp; i++)
    {
        temp = temp->next;
    }
    if (!temp || !temp->next)
    {
        printf("Position out of bounds.");
        return;
    }

    Node *to_free = temp->next;

    temp->next = to_free->next;
    if (temp->next)
    {
        temp->next->prev = temp;
    }
    free(to_free);
}

void display_list()
{
    if (is_list_empty())
        return;

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
    if (is_list_empty())
        return;

    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    printf("Count is %d.\n", count);
}

void search_node()
{
    if (is_list_empty())
        return;

    Node *temp = head;

    int position = -1, keyword = input("Enter keyword");

    for (int i = 0; temp && position == -1; i++)
    {
        if (head->data == keyword)
        {
            position = i;
        }
    }

    if (position == -1)
    {
        printf("Element not found.\n");
        return;
    }
    printf("Element found at %d.\n", position);
}

void reverse()
{
    if (is_list_empty())
        return;

    Node *temp = NULL;
    Node *current = head;

    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp)
    {
        head = temp->prev;
    }
}

int main(){
    int run = 1;
    while(run){
        int choice = input("1. Insert at beginning\t2. Insert at end\t3. Insert at position\n4. Delete at beginning\t5. Delete at end\t6. Delete at position\n7. Display list\t8. Count nodes\t9. Search node\t10. Reverse list\n11. Exit\nEnter choice:");
        switch(choice){
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
                reverse();
                break;
            case 11:
                run = 0;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
