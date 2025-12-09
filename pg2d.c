#include <stdio.h>

int main() {
    int n;
    printf("Enter Total Number of Process: ");
    scanf("%d", &n);

    int bt[n], pr[n], p[n], wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("\nP[%d]\nBurst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(pr[j] < pr[i]) {
                int temp;
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = 0;
        for(int j = 0; j < i; j++)
            wt[i] += bt[j];
        total_wt += wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_tat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time=%d", total_wt / n);
    printf("\nAverage Turnaround Time=%d\n", total_tat / n);

    return 0;
}
