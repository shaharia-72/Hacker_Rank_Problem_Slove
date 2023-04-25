/*Problem Statement

You will be given a string S as input. The string will contain only English small alphabets and will not contain any spaces. You need to tell how many time each alphabets from a to z appears.

Input Format

Input will contain only S.
Constraints

1 <= |S| <= 1000; Here |S| means the length of S.
Output Format

Ouput in the format show in the sample output.

Sample Input 0
thebrownfox

Sample Output 0
a - 0
b - 1
c - 0
d - 0
e - 1
f - 1
g - 0
h - 1
i - 0
j - 0
k - 0
l - 0
m - 0
n - 1
o - 2
p - 0
q - 0
r - 1
s - 0
t - 1
u - 0
v - 0
w - 1
x - 1
y - 0
z - 0

Sample Input 1
appleorangezebra

Sample Output 1
a - 3
b - 1
c - 0
d - 0
e - 3
f - 0
g - 1
h - 0
i - 0
j - 0
k - 0
l - 1
m - 0
n - 1
o - 1
p - 2
q - 0
r - 2
s - 0
t - 0
u - 0
v - 0
w - 0
x - 0
y - 0
z - 1*/

#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char s[1000];
    gets(s);

    int cnt[26] = {0};

    for (i = 0; i < strlen(s); i++)
    {
        int value = s[i] - 'a';
        cnt[value]++;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c - %d\n", i + (int)'a', cnt[i]);
    }

    return 0;
}