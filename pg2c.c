#include <stdio.h>

int main() {

    int n, tq;
    int at[20], bt[20], rt[20];
    int wt = 0, tat = 0;
    int time = 0, done = 0;
    int i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    /* ---- Input like FCFS ---- */
    for(i = 0; i < n; i++) {
        printf("Enter arrival time & burst time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    /* ---- Scheduling Loop ---- */
    while(done < n) {

        for(i = 0; i < n; i++) {

            if(rt[i] > 0 && at[i] <= time) {

                if(rt[i] > tq) {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else {
                    time = time + rt[i];
                    rt[i] = 0;
                    done++;

                    int cur_tat = time - at[i];
                    int cur_wt  = cur_tat - bt[i];

                    tat = tat + cur_tat;
                    wt  = wt + cur_wt;

                    printf("P%d\t\t%d\t\t%d\n",
                           i + 1, cur_tat, cur_wt);
                }
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f", (float)wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)tat / n);

    return 0;
}
