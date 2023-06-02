/*Problem Statement

Write a C program that will take an positive Odd integer N and create this pattern for the corresponding inputs. See the sample input output for understanding the pattern.

Input Format

You will be given a positive Odd integer N as input.
Constraints

1 <= N <= 21
Output Format

Output the pattern
Sample Input 0

7
Sample Output 0

***#***
***#***
***#***
#######
***#***
***#***
***#***
Sample Input 1

1
Sample Output 1

#
Sample Input 2

3
Sample Output 2

*#*
###
*#*
*/

#include <stdio.h>

int match(int nums[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == s)
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d", &T);

    int t = 1;

    while (t <= T)
    {
        int n;
        scanf("%d", &n);

        int num[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }

        int s;
        scanf("%d", &s);

        int result = match(num, n, s);

        if (result != 0)
        {
            printf("Case %d: %d\n", t, result);
        }
        else
        {

            printf("Case %d: Not Found\n", t);
        }

        t++;
    }

    return 0;
}