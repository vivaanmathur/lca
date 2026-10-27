#include <stdio.h>
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
    char post[MAX];
    printf("Enter postfix: ");
    scanf("%s", post);

    for (int i = 0; post[i] != '\0'; i++)
    {
        char c = post[i];

        if (c >= '0' && c <= '9')
        {
            int x = c - '0';
            push(x);
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
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