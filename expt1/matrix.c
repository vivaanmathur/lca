#include <stdio.h>

int main()
{
   int m, n, o, p;
   printf("Enter the rows of matrix 1: ");
   scanf("%d", &m);

   printf("Enter the columns of matrix 1: ");
   scanf("%d", &n);

   printf("Enter the rows of matrix 2: ");
   scanf("%d", &o);

   printf("Enter the columns of matrix 2: ");
   scanf("%d", &p);

   int X[m][n], Y[o][p], Z[m][p], T[n][m], U[p][o];

   for (int i = 0; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
           printf("Enter value at (%d, %d): ", i + 1, j + 1);
           scanf("%d", &X[i][j]);
       }
   }

   printf("Enter values of Matrix 2: \n");
   for (int i = 0; i < o; i++)
   {
       for (int j = 0; j < p; j++)
       {
           printf("Enter value at (%d, %d): ", i + 1, j + 1);
           scanf("%d", &Y[i][j]);
       }
   }

   int run = 1;

   while (run)
   {
       printf("Menu: \n0.Display\t1.Addition\t2. Subtraction\t3. Multiplication\t 4. Transpose\n5.Exit");

       int choice;
       printf("\nEnter  your choice: ");
       scanf("%d", &choice);

       switch (choice)
       {
       case 0:

           if ((m != o) || (n != p))
           {
               printf("Cannot add\n");
               run = 0;
           }

           printf("Matrix 1: \n");
           for (int i = 0; i < m; i++)
           {
               printf("[ ");
               for (int j = 0; j < n; j++)
               {
                   printf("%d ", X[i][j]);
               }
               printf(" ]\n");
           }
           printf("Matrix 2: \n");
           for (int i = 0; i < o; i++)
           {
               printf("[ ");
               for (int j = 0; j < p; j++)
               {
                   printf("%d ", Y[i][j]);
               }
               printf(" ]\n");
           }
           break;
       case 1:

           for (int i = 0; i < m; i++)
           {
               for (int j = 0; j < n; j++)
               {
                   Z[i][j] = X[i][j] + Y[i][j];
               }
           }

           printf("Added matrix: \n");
           for (int i = 0; i < m; i++)
           {
               printf("[ ");
               for (int j = 0; j < n; j++)
               {
                   printf("%d", Z[i][j]);
               }
               printf(" ]\n");
           }

           break;
       case 2:
           printf("Subtraction\n");

           if ((m != o) || (n != p))
           {
               printf("Cannot subtract\n");
               run = 0;
           }

           for (int i = 0; i < m; i++)
           {
               for (int j = 0; j < n; j++)
               {
                   Z[i][j] = X[i][j] - Y[i][j];
               }
           }

           printf("Subtracted matrix: \n");
           for (int i = 0; i < m; i++)
           {
               printf("[ ");
               for (int j = 0; j < n; j++)
               {
                   printf("%d ", Z[i][j]);
               }
               printf(" ]\n");
           }

           break;
       case 3:
           printf("Multiplication\n");

           if (n != o)
           {
               printf("Cannot multiply\n");
               run = 0;
           }

           for (int i = 0; i < m; i++)
           {
               for (int j = 0; j < p; j++)
               {
                   Z[i][j] = 0;

                   for (int k = 0; k < n; k++)
                   {
                       Z[i][j] += X[i][k] * Y[k][j];
                   }
               }
           }

           for (int i = 0; i < m; i++)
           {
               printf("[ ");
               for (int j = 0; j < p; j++)
               {
                   printf("%d ", Z[i][j]);
               }
               printf(" ]\n");
           }

           break;
       case 4:
           printf("Transpose\n");

           for (int i = 0; i < m; i++)
           {
               for (int j = 0; j < n; j++)
               {
                   Z[j][i] = X[i][j];
               }
           }

           for (int i = 0; i < m; i++)
           {
               printf("[ ");
               for (int j = 0; j < n; j++)
               {
                   printf("%d ", Z[i][j]);
               }
               printf(" ]\n");
           }

           printf("Matrix 2: \n");

           for (int i = 0; i < o; i++)
           {
               for (int j = 0; j < p; j++)
               {
                   Z[j][i] = Y[i][j];
               }
           }

           for (int i = 0; i < o; i++)
           {
               printf("[ ");
               for (int j = 0; j < p; j++)
               {
                   printf("%d ", Z[i][j]);
               }
               printf(" ]\n");
           }

           break;
       case 5:
           run = 0;
           break;
       default:
           printf("Please choose a valid option.\n");
           break;
       }
   }
}
