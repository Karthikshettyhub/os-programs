#include <stdio.h>

int main() {
    int n, tq;
    int bt[20], at[20], rt[20];
    int time = 0, completed = 0;
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter arrival time & burst time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    while(completed < n) {
        for(int i = 0; i < n; i++) {

            if(rt[i] > 0 && at[i] <= time) {

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } 
                else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    int process_tat = time - at[i];
                    int process_wt = process_tat - bt[i];

                    tat += process_tat;
                    wt += process_wt;

                    printf("P%d\t\t%d\t\t%d\n", i+1, process_tat, process_wt);
                }
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)tat/n);

    return 0;
}
