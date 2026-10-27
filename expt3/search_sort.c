#include <stdio.h>

struct Student
{
   int prn;
   float marks;
};

void display_db(struct Student s[], int n)
{

   printf("Student Database: \n");

   for (int i = 0; i < n; i++)
   {
       printf("Student %d\n", i + 1);
       printf("PRN: %d\t", s[i].prn);
       printf("Marks: %f\t", s[i].marks);
       printf("\n");
   }
}

int linear_search(struct Student s[], int n, int prn)
{

   int counter = 0;

   for (int i = 0; i < n; i++)
   {
       counter++;
       if (s[i].prn == prn)
       {

           printf("Iterations: %d\n", counter);

           return i;
       }
   }

   printf("Iterations: %d\n", counter);
   return -1;
}

int binary_search(struct Student s[], int n, int prn)
{

   int counter = 0;

   int high = n - 1;
   int low = 0;

   while (low <= high)
   {
       counter++;

       int mid = (low + high) / 2;

       if (prn == s[mid].prn)
       {
           printf("Iterations: %d\n", counter);
           return mid;
       }
       else if (prn < s[mid].prn)
       {
           high = mid - 1;
       }
       else if (prn > s[mid].prn)
       {
           low = mid + 1;
       }
   }

   printf("Iterations: %d\n", counter);
   return -1;
}

void insertion_sort(struct Student s[], int n)
{

   if (n == 1)
   {
       printf("Sorted with 0 iterations.\n");
       return;
   }
   int counter = 0;

   for (int i = 1; i < n; i++)
   {
       int j = i - 1;
       int key = s[i].prn;

       float marks = s[i].marks;

       while (j >= 0 && key < s[j].prn)
       {

           s[j + 1].prn = s[j].prn;
           s[j + 1].marks = s[j].marks;
           j--;
           counter++;
       }

       s[j + 1].prn = key;
       s[j + 1].marks = marks;
   }

   printf("Number of iterations: %d\n", counter);
}

void selection_sort(struct Student s[], int n)
{
   int counter = 0;

   for (int i = 0; i < n - 1; i++)
   {
       int min = i;

       for (int j = i + 1; j < n; j++)
       {
           counter++;

           if (s[j].prn < s[min].prn)
           {
               min = j;
           }
       }

       if (min != i)
       {
           struct Student temp = s[i];
           s[i] = s[min];
           s[min] = temp;
       }
   }

   printf("Number of iterations: %d\n", counter);
}

void shell_sort(struct Student s[], int n)
{
   int counter = 0;

   for (int gap = n / 2; gap > 0; gap /= 2)
   {
       for (int i = gap; i < n; i++)
       {
           struct Student temp = s[i];
           int j = i;

           while (j >= gap && s[j - gap].prn > temp.prn)
           {
               s[j] = s[j - gap];
               j -= gap;
               counter++;
           }

           s[j] = temp;
       }
   }

   printf("Number of iterations: %d\n", counter);
}

int main()
{
   int n;
   printf("Enter number of students: ");
   scanf("%d", &n);

   struct Student s[n];

   // Accept Student Data
   printf("Enter student data: \n");

   for (int i = 0; i < n; i++)
   {
       printf("Student %d\n", i + 1);
       printf("PRN: ");
       scanf("%d", &s[i].prn);

       printf("Marks: ");
       scanf("%f", &s[i].marks);
   }

   int run = 1;
   while (run)
   {
       printf("Menu:\n1.Linear Search\t2.Binary Search\t3.Insertion Sort\t4.Selection Sort\t5.Shell Sort\t6.Display DB\t7.Exit\n");

       int choice;
       printf("Enter your choice: ");
       scanf("%d", &choice);

       int x;
       int idx;

       switch (choice)
       {

       case 1:

           // Linear Search to get Marks

           printf("Enter search term: ");
           scanf("%d", &x);

           idx = linear_search(s, n, x);

           if (idx == -1)
           {
               printf("Element not found!\n");
           }
           else
           {
               printf("Element found at: %d\n", idx);
               printf("Marks: %f\n", s[idx].marks);
           }

           break;

       case 2:

           // Binary Search to get Marks

           printf("Enter search term: ");
           scanf("%d", &x);

           idx = binary_search(s, n, x);

           if (idx == -1)
           {
               printf("Element not found!\n");
           }
           else
           {
               printf("Element found at: %d\n", idx);
               printf("Marks: %f\n", s[idx].marks);
           }

           break;

       case 3:

           insertion_sort(s, n);
           break;

       case 4:
           selection_sort(s, n);
           break;

       case 5:
           shell_sort(s, n);
           break;

       case 6:
           display_db(s, n);
           break;

       case 7:
           run = 0;
           break;

       default:
           printf("Error: Invalid Option!\n");
           break;
       }
   }
}

