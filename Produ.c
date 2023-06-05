#include <stdio.h>
#include <stdlib.h>

// mutex  1.
int mutex = 1;

//  full  0.
int full = 0;

// umber of empty slots in the buffer.
int empty = 10, data = 0;

// Producers
void producer()
{
    --mutex; // decrementing mutex

    ++full; // Increase full slots

    --empty; // decrementing the number of slots available

    data++;  // incrementing data which means that the data is produced.

    printf("\nProducer produces item : %d\n", data);

    ++mutex; // incrementing mutex
}

// A function that will resemble the consumer's consumption of data
void consumer()
{
    --mutex; // Decrementing  mutex

    --full;  // Decrease the number of full slots

    ++empty; // incrementing the number of slots available

    printf("\nConsumer consumes item : %d\n", data);

    data--; // since data is consumed, let us decrease the value of data

    ++mutex; // incrementing mutex
}

int main()
{
    int n;

    printf("\n");
    printf("1.Enter 1 for Producer   2.Enter 2 for Consumer   3.Enter 3 to Exit");
    printf("\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            /*
            If the value of mutex is 1 and the buffer is not full, then we can produce the data
            */
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("Buffer Full! Cannot produce data!");
            }
            break;

        case 2:
            /*
            If the value of mutex is 1 and the buffer is not empty, then we can consume the data
            */
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("Buffer Empty! Cannot consume data!");
            }
            break;

        // Exit Condition
        case 3:
            exit(0);
            break;
        }
    }
}
