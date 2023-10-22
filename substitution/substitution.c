#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2 && (strlen(argv[1]) != 26))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int k = 0;
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Key must contain 26 alphabetical characters only.\n");
                return 1;
            }

            for (int j = k; j < 25; j++)
            {
                int n = argv[1][i];
                int m = argv[1][j + 1];

                if (n == m)
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
            k++;
        }

    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int a = plaintext[i] - 65;
            printf("%c", toupper(argv[1][a]));
        }
        else if (islower(plaintext[i]))
        {
            int b = plaintext[i] - 97;
            printf("%c", tolower(argv[1][b]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}