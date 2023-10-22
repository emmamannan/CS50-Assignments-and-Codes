#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int door[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
    {
        if (door[i] == 11)
        {
            printf("true\n");
            return true;
        }
    }

    printf("false\n");
    return false;
}