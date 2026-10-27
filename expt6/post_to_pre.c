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
    char post[MAX];
    printf("Enter postfix: ");
    scanf("%s", post);

    for (int i = 0; post[i] != '\0'; i++)
    {
        char c = post[i];

        if (is_operator(c))
        {
            char op2[MAX];
            char op1[MAX];

            pop(op2);
            pop(op1);

            char temp[MAX];
            temp[0] = c;
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);

            push(temp);
        }
        else
        {
            char temp[] = {c, '\0'};
            push(temp);
        }
    }

    printf("Prefix: %s\n", stack[top]);
    return 0;
}