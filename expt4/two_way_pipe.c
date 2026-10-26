// Vivaan Mathur
// 1272260892

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define MAX 20

int main()
{
    int pipe1[2], pipe2[2], n;
    char string[MAX];
    char line[MAX];

    pid_t pid;

    printf("Enter string to be given from parent to child: ");
    scanf("%s", string);

    if (pipe(pipe1) < 0 || pipe(pipe2) < 0)
    {
        printf("\nPipe creation error.");
        exit(0);
    }

    if ((pid = fork()) < 0)
    {
        printf("\nFork error.");
        exit(0);
    }

    if (pid > 0)
    {
        // Parent
        close(pipe1[0]);
        close(pipe2[1]);

        // Parent sends data to child
        write(pipe1[1], string, MAX);

        // Parent reads response from child
        n = read(pipe2[0], line, MAX);
        line[n] = '\0';

        printf("\nData received by parent: %s\n", line);
    }

    if (pid == 0)
    {
        // Child
        close(pipe1[1]);
        close(pipe2[0]);

        // Child reads data from parent
        n = read(pipe1[0], line, MAX);
        line[n] = '\0';

        printf("\nData received by child: %s\n", line);

        // Child sends data back to parent
        write(pipe2[1], line, MAX);
    }

    exit(0);
}