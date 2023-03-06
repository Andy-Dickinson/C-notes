#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* program to generate 10 random numbers between 1 and 9 (inclusive) */

int main()
{
    int lower = 1, upper = 9, count = 10;

    // sets seed using clock
    srand(time(0));

    printf("The random numbers are: ");
    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", num);
    }

    return 0;
}
