#include <stdio.h>

struct Process
{
    int pid;
    int allocation[100];
    int max[100];

    int need[100];

    int completed;
};

int main()
{

    int no_of_resources;
    printf("Enter no. of resources: ");
    scanf("%d", &no_of_resources);

    int no_of_processes;
    printf("Enter no. of processes: ");
    scanf("%d", &no_of_processes);

    struct Process p[no_of_processes];

    for (int i = 0; i < no_of_processes; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);

        printf("Enter allocation: ");
        for (int j = 0; j < no_of_resources; j++)
        {
            scanf("%d", &p[i].allocation[j]);
        }

        printf("Enter max: ");
        for (int j = 0; j < no_of_resources; j++)
        {
            scanf("%d", &p[i].max[j]);
        }

        // Finding Need

        for (int j = 0; j < no_of_resources; j++)
        {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }

        p[i].completed = 0;
    }

    int work[no_of_resources];

    printf("Enter currently available resources: ");
    for (int i = 0; i < no_of_resources; i++)
    {
        scanf("%d", &work[i]);
    }

    int safe_sequence[100];

    int count = 0;

    while(count < no_of_processes){
        int progress = 0;

        for(int i= 0; i < no_of_processes; i++){
            if(p[i].completed==1){
                continue;
            }

            int can_run = 1;

            for(int j = 0; j < no_of_resources; j++){
                if(p[i].need[j] > work[j]){
                    can_run = 0;
                }
            }

            if(can_run == 1){
                for(int j= 0; j < no_of_resources; j++){
                    work[j] += p[i].allocation[j];
                }
                p[i].completed=1;
                safe_sequence[count]= p[i].pid;
                count++;
                progress = 1;
            }
        }

        if(progress==0){
            break;
        }
    }


    if(count == no_of_processes){
        printf("Safe state.\n");
        for(int i= 0; i < no_of_processes;i++){
            printf("%d ", safe_sequence[i]);
        }
    }
    else{
        printf("system is not in safe state.");
    }
}