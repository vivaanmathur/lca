#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    pid_t pid = fork();

    if (pid == -1)
    {
        printf("Error.\n");
        return 0;
    }

    if (pid > 0)
    {
        printf("This is the parent process.\n");
        printf("ID of the parent process is: %d\n", getpid());
        printf("ID of the child process is: %d\n", pid);
    }

    else if (pid == 0)
    {
        sleep(10);
        printf("This is the child process.\n");
        printf("Child process id: %d\n", getpid());
        printf("Parent process id: %d\n", getppid());
    }

    return 0;
}