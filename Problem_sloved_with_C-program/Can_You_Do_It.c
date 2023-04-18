/*Problem Statement

You will be given an integer N. If N is a negative number or zero print from N to 1, otherwise print from 1 to N.

Input Format

Input will contain N.
Constraints

-10^5 <= N <= 10^5
Output Format

Output as asked in the question and don't forget to put a space between the values.
Sample Input 0

-5
Sample Output 0

-5 -4 -3 -2 -1 0 1
Sample Input 1

5
Sample Output 1

1 2 3 4 5
Sample Input 2

0
Sample Output 2

0 1*/

#include <stdio.h>
// #include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        for (int i = n; i <= 1; i++)
        {
            printf("%d ", i);
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
