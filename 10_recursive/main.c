#include "one_two_step.h"
#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("one_two_step： \n");
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        int steps = array[i];
        printf("steps: %d, climbs: %d\n", steps, one_two_step(steps));
    }

    return 0;
}