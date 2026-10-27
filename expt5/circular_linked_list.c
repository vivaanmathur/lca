#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *insert(Node *head, int coeff, int exp)
{
    if (coeff == 0)
        return head;

    Node *temp = head;
    if (temp != NULL)
    {
        if (temp->exp == exp)
        {
            temp->coeff += coeff;
            return head;
        }

        temp = temp->next;
        while (temp != head)
        {
            if (temp->exp == exp)
            {
                temp->coeff += coeff;
                return head;
            }

            temp = temp->next;
        }
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->exp = exp;

    if (head == NULL)
    {
        new_node->next = new_node;
        return new_node;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = head;

    return head;
}

Node *create(void)
{
    Node *head = NULL;
    int n;
    int coeff;
    int exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insert(head, coeff, exp);
    }

    return head;
}

void print_term(int coeff, int exp)
{
    int value = coeff < 0 ? -coeff : coeff;

    if (exp == 0)
        printf("%d", value);
    else if (exp == 1)
        printf("%dx", value);
    else
        printf("%dx^%d", value, exp);
}

void display(Node *head)
{
    Node *temp;
    int first = 1;

    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    temp = head;
    printf("Polynomial: ");

    if (temp->coeff != 0)
    {
        if (temp->coeff < 0)
            printf("-");
        print_term(temp->coeff, temp->exp);
        first = 0;
    }

    temp = temp->next;
    while (temp != head)
    {
        if (temp->coeff != 0)
        {
            if (!first && temp->coeff > 0)
                printf(" + ");
            else if (!first)
                printf(" ");

            if (temp->coeff < 0)
                printf("-");
            print_term(temp->coeff, temp->exp);
            first = 0;
        }

        temp = temp->next;
    }

    if (first)
        printf("0");

    printf("\n");
}

Node *add(Node *p1, Node *p2)
{
    Node *sum = NULL;
    Node *temp;

    if (p1 != NULL)
    {
        sum = insert(sum, p1->coeff, p1->exp);
        temp = p1->next;

        while (temp != p1)
        {
            sum = insert(sum, temp->coeff, temp->exp);
            temp = temp->next;
        }
    }

    if (p2 != NULL)
    {
        sum = insert(sum, p2->coeff, p2->exp);
        temp = p2->next;

        while (temp != p2)
        {
            sum = insert(sum, temp->coeff, temp->exp);
            temp = temp->next;
        }
    }

    return sum;
}

int main(void)
{
    Node *p1;
    Node *p2;
    Node *sum;

    printf("Enter first polynomial\n");
    p1 = create();

    printf("\nEnter second polynomial\n");
    p2 = create();

    display(p1);
    display(p2);

    sum = add(p1, p2);
    display(sum);

    return 0;
}
