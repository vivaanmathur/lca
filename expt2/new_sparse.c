#include <stdio.h>

#define MAX 100

void compact(int m, int n, int A[m][n], int sparse[MAX][3])
{
    printf("Enter values: \n");

    sparse[0][0] = m;
    sparse[0][1] = n;

    int k = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("(%d, %d): ", i + 1, j + 1);
            scanf("%d", &A[i][j]);

            if (A[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = A[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k - 1;
}

void simple_transpose(int sparse[MAX][3])
{

    int transpose[MAX][3];

    int col = transpose[0][0] = sparse[0][1];
    int row = transpose[0][1] = sparse[0][0];
    int elem = transpose[0][2] = sparse[0][2];

    int k = 1;

    for (int i = 0; i < col; i++)
    {
        for (int j = 1; j <= elem; j++)
        {
            if (sparse[j][1] == i)
            {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }

    for (int i = 0; i < transpose[0][2] + 1; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("]\n");
    }
}

void fast_transpose(int sparse[MAX][3])
{

    int transpose[MAX][3];

    int col = transpose[0][0] = sparse[0][1];
    int row = transpose[0][1] = sparse[0][0];
    int elem = transpose[0][2] = sparse[0][2];

    int col_size[col];
    for (int i = 0; i < col; i++)
    {
        col_size[i] = 0;
    }

    for (int i = 1; i <= elem; i++)
    {
        col_size[sparse[i][1]]++;
    }

    int col_index[col];
    col_index[0] = 1;

    for (int i = 1; i < col; i++)
    {
        col_index[i] = col_index[i - 1] + col_size[i - 1];
    }

    for (int i = 1; i <= elem; i++)
    {

        int trf = col_index[sparse[i][1]];

        transpose[trf][0] = sparse[i][1];
        transpose[trf][1] = sparse[i][0];
        transpose[trf][2] = sparse[i][2];

        col_index[sparse[i][1]]++;
    }

    for (int i = 0; i < transpose[0][2] + 1; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("]\n");
    }
}

void display(int sparse[MAX][3])
{
    for (int i = 0; i < sparse[0][2] + 1; i++)
    {
        printf("[ ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sparse[i][j]);
        }
        printf("]\n");
    }
}

int main()
{

    int m, n;
    printf("Enter number of rows in Original Matrix: ");
    scanf("%d", &m);

    printf("Enter number of columns in Original Matrix: ");
    scanf("%d", &n);

    int A[m][n];

    int sparse[100][3];

    int run = 1;
    while (run)
    {

        int choice;
        printf("1.Compact Form\t2.Display\t3.Simple Transpose\t4.Fast Transpose\t5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            compact(m, n, A, sparse);
            break;
        case 2:
            display(sparse);
            break;
       case 3:
    simple_transpose(sparse);
    break;
case 4:
    fast_transpose(sparse);
    break;
        case 5:
            run = 0;
            break;
        default:
            printf("invalid choice.\n");
            break;
        }
    }

    return 0;
}