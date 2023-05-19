/*Problem Statement

You will be given a string S consisting of small alphabets, capital alphabets and spaces. You need to count number of small alphabets, capital alphabets and spaces in the string S.

Input Format

Input will contain a string S.
Constraints

1 <= |S| <= 1000; Here |S| means the length of S.
Output Format

Output in the format given in the sample output.
Sample Input 0

Hello Everyone
Sample Output 0

Capital - 2
Small - 11
Spaces - 1
Sample Input 1

I Hope You Have Been Enjoying
Sample Output 1

Capital - 6
Small - 18
Spaces - 5*/

#include <stdio.h>
#include <string.h>
int main()
{
    int cap = 0, sma = 0, spa = 0;
    char s[1000];
    gets(s);

    // printf("%s\n", s);
    // printf("%d\n", strlen(s));

    for (int i = 0; i < strlen(s); i++)
    {
        // printf("%c\n", s[i]);

        if (65 <= (int)s[i] && (int)s[i] <= 90)
        {
            cap++;
        }
        if (97 <= (int)s[i] && (int)s[i] <= 122)
        {
            sma++;
        }
    }

    printf("Capital - %d\n", cap);
    printf("Small - %d\n", sma);
    printf("Spaces - %d\n", (int)strlen(s) - (cap + sma));

    return 0;
}