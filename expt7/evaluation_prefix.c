#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("stack full!\n");
        return;
    }
    top++;
    stack[top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack empty!\n");
        return -1;
    }
    int x = stack[top];
    top--;
    return x;
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

        if (c >= '0' && c <= '9')
        {
            int x = c - '0';
            push(x);
        }
        else
        {
            int op1 = pop();
            int op2 = pop();
            int res;

            switch (c)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '^':
                res = pow(op1, op2);
                break;
            }

            push(res);
        }
    }

    printf("%d\n", stack[top]);

    return 0;
}