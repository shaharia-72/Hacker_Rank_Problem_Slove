/*Problem Statement

You will be given a string S as input contains only small English alphabets. You need to tell the number of vowels in it. The string will not contain any spaces.

Note: Vowels are a,e,i,o and u

Input Format

Input will contain a string S.
Constraints

1 <= |S| <= 1000 ; Here |S| means the length of string S.
Output Format

Output the number of vowels.
Sample Input 0
thefoxisgone

Sample Output 0
5

Sample Input 1
ilikeassignments

Sample Output 1
6*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    int count = 0;

    for (int i = 0; i <= strlen(s); i++)
    {
        gets(s);
    }

    // printf("%s\n", s);

    for (int i = 0; i <= strlen(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}