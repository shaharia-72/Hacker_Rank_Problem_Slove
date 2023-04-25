/*Problem Statement

You will be given two positive integer N and K. You need to print from 1 to N, and you need to do this K times.

Please look at the sample input output.

Input Format

Input will contain N and K.
Constraints

1 <= N,K <= 100
Output Format

You need to print fron 1 to N, K times. Don't forget to print new line after printing from 1 to N.
Sample Input 0

10 5*/

#include <stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}