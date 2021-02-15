#include <stdio.h>
#include <cs50.h>
#include <string.h>

void count(string a, float b[]);

// Formulates the Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
// to determine the grade level of sentence given
int main(void)
{
    float NumToTest[2];
    float result;
    
    string request = get_string("Give me some text to test the grade of:\n");
    
    count(request, NumToTest);
    
    NumToTest[0] = NumToTest[0] * 0.0588;
    NumToTest[1] = NumToTest[1] * 0.296;
    result = NumToTest[0] - NumToTest[1] - 15.8;
    
    int answer = (int)(result < 0 ? (result - 0.5) : (result + 0.5));
    
    if(answer > 16)
    {
        printf("Grade: 16+\n");
    }
    else if(answer < 1)
    {
        printf("Grade: Before Grade 1\n");
    }
    else
    {
        printf("Grade: %i\n", answer);
    }
    
}

// Counts letters, words and sentences then makes the value of L and S to feed into an array
// L = (letters / words) * 100
// S = (sentences / words) * 100
void count(string a, float b[])
{
    int leng = strlen(a);
    float letters, words, sent;
    
    for(int i = 0; i < leng; i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
        {
            letters++;
        }
        else if(a[i] >= 'a' && a[i] <= 'z')
        {
            letters++;
        }
        else if(a[i] == ' ')
        {
            words++;
        }
        else if(a[i] == '.' || a[i] == '!' || a[i] == '?')
        {
            sent++;
        }
    }
    words++;
    
    b[0] = letters / words;
    b[0] = b[0] * 100;
    b[1] = sent / words;
    b[1] = b[1] * 100;
}