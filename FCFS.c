#include <stdio.h>
#include <conio.h>

#define max 30

void main()
{
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max], p[max];

    float awt = 0, atat = 0;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the Process number : ");
        scanf("%d", &p[i]);

        printf("Enter the Burst time : ");
        scanf("%d", &bt[i]);

        printf("Enter the Arrival time :");
        scanf("%d", &at[i]);

        printf("\n");
    }


    temp[0] = 0;

    printf("Process\t Burst Time\t Arrival Time\t Waiting Time\t Turn Around Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i, bt[i], at[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("Average Waiting Time : %f\n", awt);
    printf("Average Turn Around Time : %f\n", atat);
}