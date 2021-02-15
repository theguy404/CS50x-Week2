#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Checks for 1 arguement of 26 letters
    if(!argv[1] || argv[2])
    {
        printf("Usage: ./substitution key\n");
    }
    else if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else
    {
        string plain = get_string("plaintext: \n");
        int length = strlen(plain);
        char cyphertxt[length];
        
        // matches letters in cypher to their upper or low case equivalant
        for(int i = 0; i < length; i++)
        {
            if(plain[i] >= 'A' && plain[i] <= 'Z')
            {
                int character = plain[i] - 65;
                char character2 = argv[1][character];
                cyphertxt[i] = character2;
            }
            else if(plain[i] >= 'a' && plain[i] <= 'z')
            {
                int character = plain[i] - 97;
                char character2 = argv[1][character] + 32;
                cyphertxt[i] = character2;
            }
            else
            {
                cyphertxt[i] = plain[i];
            }
        }
        printf("%s\n", cyphertxt);
    }
}