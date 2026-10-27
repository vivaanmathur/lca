#include <stdio.h>

void compact(int m, int n, int original[m][n], int sparse[100][3])
{
   int k = 1;

   sparse[0][0] = m;
   sparse[0][1] = n;

   for (int i = 0; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
           if (original[i][j] != 0)
           {
               sparse[k][0] = i;
               sparse[k][1] = j;
               sparse[k][2] = original[i][j];
               k++;
           }
       }
   }

   sparse[0][2] = k - 1;

   if ((k - 1) > ((m * n) / 2))
   {
       printf("This matrix is not a sparse matrix.\n");
       return;
   }

   printf("\nSparse Matrix:\n");
   for (int i = 0; i < k; i++)
   {
       printf("[ ");
       for (int j = 0; j < 3; j++)
           printf("%d ", sparse[i][j]);
       printf("]\n");
   }
}

void simple_transpose(int sparse[100][3], int transpose[100][3])
{
   int n = transpose[0][0] = sparse[0][1];
   int m = transpose[0][1] = sparse[0][0];
   int t = transpose[0][2] = sparse[0][2];

   int counter = 0;

   int q = 1;

   for (int j = 0; j < n; j++)
   {
       for (int p = 1; p <= t; p++)
       {
           if (sparse[p][1] == j)
           {
               transpose[q][0] = sparse[p][1];
               transpose[q][1] = sparse[p][0];
               transpose[q][2] = sparse[p][2];
               q++;
           }

           counter++;
       }
   }

   printf("\nSimple Transpose:\n");
   for (int i = 0; i < q; i++)
   {
       printf("[ ");
       for (int j = 0; j < 3; j++)
           printf("%d ", transpose[i][j]);
       printf("]\n");
   }

   printf("Total iterations: %d\n", counter);
}

void fast_transpose(int sparse[100][3], int fast[100][3])
{
   int n = fast[0][0] = sparse[0][1];
   int m = fast[0][1] = sparse[0][0];
   int t = fast[0][2] = sparse[0][2];

   int counter = 0;

   int column_size[100] = {0};
   int column_index[100];

   for (int i = 1; i <= t; i++)
   {
       column_size[sparse[i][1]]++;

       counter++;
   }

   column_index[0] = 1;

   for (int i = 1; i < n; i++)
   {
       column_index[i] = column_index[i - 1] + column_size[i - 1];
       counter++;
   }

   for (int i = 1; i <= t; i++)
   {
       int col = sparse[i][1];
       int pos = column_index[col];

       fast[pos][0] = sparse[i][1];
       fast[pos][1] = sparse[i][0];
       fast[pos][2] = sparse[i][2];

       column_index[col]++;
       counter++;
   }

   printf("\nFast Transpose:\n");
   for (int i = 0; i <= t; i++)
   {
       printf("[ ");
       for (int j = 0; j < 3; j++)
           printf("%d ", fast[i][j]);
       printf("]\n");
   }

   printf("Total iterations: %d\n", counter);
}

int main()
{
   int m, n;

   printf("Enter number of rows: ");
   scanf("%d", &m);

   printf("Enter number of columns: ");
   scanf("%d", &n);

   if (m <= 0 || n <= 0)
   {
       printf("Invalid matrix size.\n");
       return 0;
   }

   int original[m][n];

   printf("\nEnter the matrix:\n");

   for (int i = 0; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
           printf("Element [%d][%d]: ", i, j);
           scanf("%d", &original[i][j]);
       }
   }

   int sparse[100][3];
   int transpose[100][3];
   int fast[100][3];

   compact(m, n, original, sparse);

   int run = 1;
   while (run)
   {

       printf("Choose: \n1. Simple Transpose\t2. Fast Transpose\t3.Exit\n");

       int choice;
       printf("Enter an option: ");
       scanf("%d", &choice);

       switch (choice)
       {

       case 1:

           simple_transpose(sparse, transpose);
           break;

       case 2:
           fast_transpose(sparse, fast);
           break;

       case 3:
           run = 0;
           break;

       default:
           printf("Invalid option.\n");
       }
   }

   return 0;
}