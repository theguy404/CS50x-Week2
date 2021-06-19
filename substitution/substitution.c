#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Checks for 1 arguement of 26 letters
    if (!argv[1] || argv[2])
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        // checks cypher for errors
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] < 'A' || argv[1][i] > 'Z')
            {
                if (argv[1][i] < 'a' || argv[1][i] > 'z')
                {
                    return 1;
                }
            }
            for (int j = 0; j <= i; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    if (i != j)
                    {
                        return 1;
                    }
                }
            }
        }
        
        // get the string to convert
        string plain = get_string("plaintext: \n");
        int length = strlen(plain);
        char cyphertxt[length];
        
        // matches letters in cypher to their upper or low case equivalant
        for (int i = 0; i < length; i++)
        {
            if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                int character = plain[i] - 65;
                char character2 = argv[1][character];
                if (character2 >= 'a')
                {
                    character2 = character2 - 32;
                }
                cyphertxt[i] = character2;
            }
            else if (plain[i] >= 'a' && plain[i] <= 'z')
            {
                int character = plain[i] - 97;
                char character2 = argv[1][character];
                if (character2 < 'a')
                {
                    character2 = character2 + 32;
                }
                cyphertxt[i] = character2;
            }
            else
            {
                cyphertxt[i] = plain[i];
            }
        }
        
        printf("ciphertext: ");
        
        // iterates over cyphertxt array and prints to the console
        for (int i = 0; i < length; i++)
        {
            printf("%c", cyphertxt[i]);
        }
        printf("\n");
    }
}