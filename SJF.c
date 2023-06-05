
#include <stdio.h>
#include <conio.h>

#define max 30

void main()
{
    int i, j, n, t, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("\n");
    
    for (i = 0; i < n; i++)
    {
        printf("Enter the process number : ");
        scanf("%d", &p[i]);
        printf("Enter the burst time : ");
        scanf("%d", &bt[i]);

        printf("\n");
    }

    // Sorting according to bubble sort
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    printf("Process \t Burst time \t Waiting time \t Turn Around Time\n");

    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }

        tat[i] = wt[i] + bt[i]; // correct

        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;

    printf("\n");

    printf("Average waiting time is %f\n", awt);
    printf("Average turnaround time is %f\n", atat);
}