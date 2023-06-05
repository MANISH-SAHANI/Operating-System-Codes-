#include <stdio.h>

void main()
{
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10], p[10];

    float awt = 0, atat = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the process number : ");
        scanf("%d", &p[i]);
        
        printf("Enter the burst time : ");
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];

        printf("\n");
    }

    printf("Enter the time quantum : ");
    scanf("%d", &qt);

    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++;
                continue;
            }
            if (rem_bt[i] > qt)
                rem_bt[i] = rem_bt[i] - qt;
            else
            {
                if (rem_bt[i] >= 0)
                {
                    temp = rem_bt[i];
                    rem_bt[i] = 0;
                }
            }
            sq = sq + temp;
            tat[i] = sq;
        }

        if (n == count)
        {
            break;
        }
    }

    printf("\nProceess\tBurst Time\tTurn Around Time\tWaiting Time\n");

    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }

    awt = awt / n;
    atat = atat / n;

    printf("\nAverage Waiting Time : %f\n", awt);
    printf("\nAverage Turn Around Time : %f\n", atat);
}