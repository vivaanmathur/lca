#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    int filedes[2];
    char string[100];

    printf("Enter string to be given from parent to child: ");
    scanf("%s", string);

    if (pipe(filedes) < 0) {
        printf("Pipe creation error.\n");
        return 1;
    }

    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("Process could not be created.\n");
        return 1;
    }

    if (pid > 0) {
        // Parent: write to pipe
        close(filedes[0]);
        write(filedes[1], string, 100);
        close(filedes[1]);
    }

    if (pid == 0) {
        // Child: read from pipe
        close(filedes[1]);

        char line[100];
        int n = read(filedes[0], line, 100);
        line[n] = '\0';

        printf("Data read by child: %s\n", line);
        printf("Bytes read: %d\n", n);
    }

    return 0;
}