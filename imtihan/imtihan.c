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

    for (int i=0; i<h; i++)
    {
        for (int j=0; j<i; j++)
        {
            printf(" ");
        }

        for (int k=i; k<h; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int k=i; k<h; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

void lock_pairs(void)
{
    // TODO

    locked[pairs[0].winner][pairs[0].loser] = true;
    for (int n = 1; n < pair_count; n++)
    {
        bool x = false;
        bool y = false;
        for (int m = 0; m < n; m++)
        {
            x = xpairs[n].winner == pairs[m].loser;
            y = pairs[n].loser == pairs[m].winner;
            if (x && y) {
                locked[pairs[n].winner][pairs[n].loser] = false;
                break;
            }
        }
        if (!(x&&y)){
            locked[pairs[n].winner][pairs[n].loser] = true;
        }
    }
    return;
}

int n = 0;
    for (int j = 0; j < candidate_count; j++)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (locked[i][j] == false)
                {
                    n++;
                }
            }
            if (n == candidate_count)
            {
                printf("%s\n", candidates[j]);
            }
        }

    return;