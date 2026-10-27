#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char str[])
{
    if (top == MAX - 1)
    {
        printf("Stack full!\n");
        return;
    }
    top++;
    strcpy(stack[top], str);
}

void pop(char str[])
{
    if (top == -1)
    {
        printf("Stack empty\n");
        str[0] = '\0';
        return;
    }
    strcpy(str, stack[top]);
    top--;
}

int is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}

int main()
{
    char pre[MAX];
    printf("Enter prefix: ");
    scanf("%s", pre);

    int len = strlen(pre);

    for (int i = len - 1; i >= 0; i--)
    {
        char c = pre[i];

        if (is_operator(c))
        {
            char temp[MAX] = "(";
            char op1[MAX];
            char op2[MAX];
            char op_string[] = {c, '\0'};

            pop(op1);
            pop(op2);

            strcat(temp, op1);
            strcat(temp, op_string);
            strcat(temp, op2);
            strcat(temp, ")");

            push(temp);
        }
        else
        {
            char temp[] = {c, '\0'};
            push(temp);
        }
    }

    printf("Infix: %s\n", stack[top]);
    return 0;
}