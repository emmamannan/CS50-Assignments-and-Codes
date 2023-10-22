#include <stdio.h>

void swap (int *x, int *y);

int main (void)
{
    int x = 10;
    int y = 11;

    int *s = &x;
    int *t = &y;

    swap (s, t);
    printf("x is %i and y is %i\n", x, y);
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}