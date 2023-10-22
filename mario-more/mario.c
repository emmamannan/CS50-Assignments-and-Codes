#include <cs50.h>
#include <stdio.h>

int main(void)
{
   //get height of pyramid
   int h;
   do
   {
    h = get_int("Height: ");
   }
   while (h < 1 | h > 8);

   //intial number of # (n)
   int n = 1;

   //initial number of spaces (z) before #
   int z = h - 1;

   //loop for number of rows which is equal to height (h)
   for (int j = 0; j < h; j++)
   {
    //loop for printing (z) spaces before the first pyramid
    for (int k = 0; k < z; k++)
    {
        printf(" ");
    }
    z--;
    //loop for printing first (n) number of #
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    //loop for printing 2 spaces before the second pyramid
    for (int k = 0; k < 2; k++)
    {
        printf(" ");
    }
    //loop for printing second (n) number of #
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
    n++;
   }
}