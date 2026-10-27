#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int check_char(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return 0;
    }
    else if (x == '(')
    {
        return 1;
    }
    else if (x == ')')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int priority(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }

    return 0;
}

int push(char x)
{
    if (top >= MAX - 1)
    {
        return 0;
    }

    top++;
    stack[top] = x;

    return 1;
}

char pop()
{
    if (top == -1)
    {
        return '?';
    }

    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '?';
    }

    return stack[top];
}

int main()
{

    printf("Enter infix: ");
    char infix[MAX];

    scanf("%s", infix);

    char postfix[MAX];

    int i_i = 0;
    int i_p = 0;

    while (infix[i_i] != '\0')
    {
        char inc = infix[i_i];

        if (check_char(inc) == 3)
        {
            postfix[i_p] = inc;
            i_p++;
        }

        else if (check_char(inc) == 1)
        {
            push(inc);
        }

        else if (check_char(inc) == 2)
        {
            while (top != -1 && peek() != '(')
            {
                postfix[i_p] = pop();
                i_p++;
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }

        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   priority(peek()) >= priority(inc))
            {
                postfix[i_p] = pop();
                i_p++;
            }

            push(inc);
        }

        i_i++;
    }

    while (top != -1)
    {
        postfix[i_p] = pop();
        i_p++;
    }

    postfix[i_p] = '\0';

    printf("%s\n", postfix);

    return 0;
}