#include <stdio.h>

// Struct to store process details
struct process
{
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function to sort processes based on priority
void sort_priority(struct process p[], int n)
{
    struct process temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].priority > p[j].priority)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int n, total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for process %d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;

        printf("\n");
    }

    // Sort the processes based on priority
    sort_priority(p, n);

    // Calculate waiting time and turnaround time for each process
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for (int i = 1; i < n; i++)
    {
        p[i].waiting_time = p[i - 1].turnaround_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    // Display waiting time and turnaround time for each process
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    // Calculate and display average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %0.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);

    return 0;
}