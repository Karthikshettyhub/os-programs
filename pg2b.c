#include<stdio.h>

int main()
{
    int n;
    int bt[20], wt[20], tat[20], p[20];
    int avwt = 0, avtat = 0;
    int i, j, temp;

    printf("Enter number of process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for(i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    /* ---- SJF Sorting (only extra part vs FCFS) ---- */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* ---- Waiting Time (same as FCFS) ---- */
    wt[0] = 0;
    for(i = 1; i < n; i++)
    {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    /* ---- Turnaround Time + Average (same as FCFS) ---- */
    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];

        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",
               p[i], bt[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;

    printf("\n\nAverage Waiting Time:%d", avwt);
    printf("\nAverage Turnaround Time:%d", avtat);

    return 0;
}

