#include <stdio.h>

struct Process
{
    int pid;
    int bt;
    int at;

    int ct;
    int tat;
    int wt;
};

int main()
{

    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++)
    {

        printf("Process %d\n", i + 1);
        printf("PID: ");
        scanf("%d", &p[i].pid);

        printf("BT: ");
        scanf("%d", &p[i].bt);

        printf("AT: ");
        scanf("%d", &p[i].at);
    }

    // Sort the structures by their arrival time

    if (n > 1)
    {

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (p[j].at > p[j + 1].at)
                {
                    int temp = p[j].at;
                    p[j].at = p[j + 1].at;
                    p[j + 1].at = temp;

                    temp = p[j].bt;
                    p[j].bt = p[j + 1].bt;
                    p[j + 1].bt = temp;

                    temp = p[j].pid;
                    p[j].pid = p[j + 1].pid;
                    p[j + 1].pid = temp;
                }
            }
        }
    }

    float avg_ct = 0, avg_wt = 0, avg_tat = 0;

    int j = p[0].at;

    for (int i = 0; i < n; i++)
    {

        if (p[i].at > j)
        {
            j = p[i].at;
        }

        // CT = Gantt counter + BT
        p[i].ct = j + p[i].bt;

        avg_ct += p[i].ct;

        // TAT = CT - AT

        p[i].tat = p[i].ct - p[i].at;

        avg_tat += p[i].tat;

        // WT = TAT - BT
        p[i].wt = p[i].tat - p[i].bt;

        avg_wt += p[i].wt;

        j = j + p[i].bt;
    }

    // Calculate the average already summed
    avg_ct /= n;
    avg_tat /= n;
    avg_wt /= n;

    for (int i = 0; i < n; i++)
    {
        printf("PID: %d\t|\tBT: %d\t|\tAT: %d\t|\tCT:%d\t|\tTAT: %d\t|\tWT: %d\n", p[i].pid, p[i].bt, p[i].at, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average completion time: %f\n", avg_ct);
    printf("Average TAT: %f\n", avg_tat);
    printf("Average WT: %f\n", avg_wt);

    return 0;
}
