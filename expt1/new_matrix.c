#include <stdio.h>

void accept(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    printf("Enter values: \n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("(%d, %d): ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("(%d, %d): ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }
}

void display(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    printf("Matrix 1:\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("(%d, %d): %d\n", i + 1, j + 1, A[i][j]);
        }
    }

    printf("Matrix 2:\n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("(%d, %d): %d\n", i + 1, j + 1, B[i][j]);
        }
    }
}

void addition(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    if ((m1 != m2) || (n1 != n2))
    {
        printf("Cannot add. Row/column mismatch.\n");
        return;
    }

    int C[m1][m2];

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            C[i][j] = A[i][j] + B[i][j];

            printf("(%d, %d): %d\n", i + 1, j + 1, C[i][j]);
        }
    }
}

void subtraction(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    if ((m1 != m2) || (n1 != n2))
    {
        printf("Cannot subtract. Row/column mismatch.\n");
        return;
    }

    int C[m1][m2];

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            C[i][j] = B[i][j] - A[i][j];

            printf("(%d, %d): %d\n", i + 1, j + 1, C[i][j]);
        }
    }
}

void multiplication(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    if ((n1 != m2))
    {
        printf("Cannot multiply. Row/column mismatch.\n");
        return;
    }

    int C[m1][n2];

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {

            int sum = 0;
            for (int k = 0; k < n1; k++)
            {
                sum += A[i][k] * B[k][j];
            }

            C[i][j] = sum;

            printf("(%d, %d): %d\n", i + 1, j + 1, C[i][j]);
        }
    }
}

void transpose(int m1, int m2, int n1, int n2, int A[m1][n1], int B[m2][n2])
{
    int C[n1][m1];

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            C[j][i] = A[i][j];
        }
    }

    int D[n2][m2];

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            D[j][i] = B[i][j];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            printf("(%d, %d): %d\n", i + 1, j + 1, C[i][j]);
        }
    }

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("(%d, %d): %d\n", i + 1, j + 1, D[i][j]);
        }
    }
}

int main()
{
    int m1, m2, n1, n2;
    printf("Enter number of rows in Matrix 1: ");
    scanf("%d", &m1);

    printf("Enter number of columns in Matrix 1: ");
    scanf("%d", &n1);

    printf("Enter number of rows in Matrix 2: ");
    scanf("%d", &m2);

    printf("Enter number of columns in Matrix 1: ");
    scanf("%d", &n2);

    int A[m1][n1], B[m2][n2];

    int run = 1;
    while (run)
    {

        int choice;
        printf("1.Accept\t2.Display\t3.Addition\t4.Subtraction\t5.Multiplication\t6.Transpose\t7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            accept(m1, n1, m2, n2, A, B);
            break;
        case 2:
            display(m1, n1, m2, n2, A, B);
            break;
        case 3:
            addition(m1, n1, m2, n2, A, B);
            break;
        case 4:
            subtraction(m1, n1, m2, n2, A, B);
            break;
        case 7:
            run = 0;
            break;
        default:
            printf("wrong.\n");

            break;
        }
    }
}