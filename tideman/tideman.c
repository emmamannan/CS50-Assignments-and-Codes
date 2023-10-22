#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // pairs[n]
    int n = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[n].winner = i;
                pairs[n].loser = j;
                pair_count++;
                n++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int n = 0;
    int m = 1;
    pair temp[pair_count];

    for (int j = 0; j < pair_count - 1; j++)
    {
        int x = 0;
        int smallest = preferences[pairs[x].winner][pairs[x].loser];
        for (int i = 0; i < (pair_count - n); i++)
        {
            if (smallest > preferences[pairs[i].winner][pairs[i].loser])
            {
                smallest = preferences[pairs[i].winner][pairs[i].loser];
                x = i;
            }
        }

        //swap
        temp[0].winner = pairs[x].winner;
        temp[0].loser = pairs[x].loser;

        pairs[x].winner = pairs[pair_count - m].winner;
        pairs[x].loser = pairs[pair_count - m].loser;

        pairs[pair_count - m].winner = temp[0].winner;
        pairs[pair_count - m].loser = temp[0].loser;

        n++;
        m++;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO

    locked[pairs[0].winner][pairs[0].loser] = true;
    for (int n = 1; n < pair_count; n++)
    {
        int x = 0;
        int y = 0;
        for (int m = 0; m < n; m++)
        {
            if (pairs[n].winner == pairs[m].loser)
            {
                x++;
            }
            if (pairs[n].loser == pairs[m].winner)
            {
                y++;
            }
        }
        if (x > 0 && y > 0)
        {
            locked[pairs[n].winner][pairs[n].loser] = false;
        }
        else
        {
            locked[pairs[n].winner][pairs[n].loser] = true;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%d ", locked[i][j]);
        }
        printf("\n");
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO

    for (int j = 0; j < candidate_count; j++)
        {
            int n = 0;
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
}