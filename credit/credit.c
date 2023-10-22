#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //find length of card number entered by user
    int y = 0;
    long x = get_long("Number: ");
    long i = x;
    while (i > 0)
    {
        i = i / 10;
        y++;
    }

    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    long k = x;
    long q;
    int r;
    int z = 0;
    while (k > 0)
    {
        q = k % 100;
        r = 2 * (q / 10);
        z = z + (r % 10) + (r / 10);
        k = k / 100;
    }

    //sum of the digits that weren’t multiplied by 2
    long j = x;
    int l = j % 10;

    long m = j / 10;
    long n;
    int p;
    int s = 0;
    while (m > 0)
    {
        n = m % 100;
        p = n / 10;
        s = s + p;
        m = m / 100;
    }

    //Add the two sums
    int checksum = z + l + s;
    int lastdigit = checksum % 10;

    //find first two digits for AMEX and MASTERCARD (a)
    long a = x;
    for (int u = 0; u < (y - 2); u++)
    {
        a = a / 10;
    }

    //and first one digit for VISA (v)
    long v = x;
    for (int w = 0; w < (y - 1); w++)
    {
        v = v / 10;
    }

    //print out which one it is
    if (y == 15 && (a == 34 || a == 37) && lastdigit == 0)
    {
        printf("AMEX\n");
    }
    else if (y == 16 && (a == 51 || a == 52 || a == 53 || a == 54 || a == 55) && lastdigit == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ((y == 13 || y == 16) && (v == 4) && lastdigit == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
