#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        printf("Error!");
        return 0;
    }

    if(pid == 0){
        printf("This is the child process. PID is %d\n", getpid());
    }
    if(pid > 0){
        sleep(10);
        printf("This is parent process.\n");
        system("ps -axj | tail");
    }
}