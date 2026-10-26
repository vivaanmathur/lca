#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

   int n;
   printf("Enter size: ");
   scanf("%d", &n);

   int x[n];
   for (int i = 0; i < n; i++)
   {
       printf("Enter value at %d: ", i + 1);
       scanf("%d", &x[i]);
   }

   pid_t sorter = fork();

   if (sorter == 0)
   {
       // Child Process - Sort in Descending Order
       printf("Child process: \n");

       for (int i = 0; i < n; i++)
       {
           for (int j = i + 1; j < n; j++)
           {
               if (x[j] > x[i])
               {
                   int c = x[i];
                   x[i] = x[j];
                   x[j] = c;
               }
           }
       }

       for (int i = 0; i < n; i++)
       {
           printf("Elem %d: %d\t", i + 1, x[i]);
       }
       printf("\n");
   }
   else
   {
       // Parent Process - Sort in Ascending Order
       printf("Parent process: \n");

       for (int i = 0; i < n; i++)
       {
           for (int j = i + 1; j < n; j++)
           {
               if (x[j] < x[i])
               {
                   int c = x[i];
                   x[i] = x[j];
                   x[j] = c;
               }
           }
       }

       for (int i = 0; i < n; i++)
       {
           printf("Elem %d: %d\t", i + 1, x[i]);
       }
       printf("\n");
   }

   return 0;
}

