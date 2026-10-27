#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];

int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack full!\n");
        return;
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return '\0';
    }
    char a = stack[top];
    top--;
    return a;
}

char peek()
{
    if (top == -1)
    {
        printf("Stack empty\n");
        return '\0';
    }
    return stack[top];
}

int check_char(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    else if (c == '(')
    {
        return 2;
    }
    else if (c == ')')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

void rev(char str[])
{

    for (int i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = pop();

        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';

        str[i] = c;
    }
}

int priority(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    return 0;
}

int main()
{
    char in[MAX];
    printf("Enter infix: ");
    scanf("%s", in);

    rev(in);

    char pre[MAX];

    int i_i = 0;
    int i_p = 0;

    while (in[i_i] != '\0')
    {
        char c = in[i_i];
        switch (check_char(c))
        {
        case 1:
            while (top != -1 && peek() != '(' && priority(peek()) >= priority(c))
            {
                pre[i_p] = pop();
                i_p++;
            }
            push(c);
            break;
        case 2:
            push('(');
            break;
        case 3:

            while (top != -1 && peek() != '(')
            {
                pre[i_p] = pop();
                i_p++;
            }
            if (top != -1 && peek() == '(')
            {
                pop();
            }
            break;
        case 4:
            pre[i_p] = c;
            i_p++;
            break;
        }
        i_i++;
    }

    while (top != -1)
    {
        pre[i_p] = pop();
        i_p++;
    }
    pre[i_p] = '\0';
    rev(pre);
    printf("%s\n", pre);
}