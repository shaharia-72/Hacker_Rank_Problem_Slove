/*Problem Statement

You will be given a positive integer N. You need to print "I Love Assignment" N times without the quotation mark.

Input Format

Input will contain N.
Constraints

1 <= N <= 10^5
Output Format

Output "I Love Assignment" N times and don't forget to print new line after it.
Sample Input 0

5
Sample Output 0

I Love Assignment
I Love Assignment
I Love Assignment
I Love Assignment
I Love Assignment*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n - 1; i++)
    {
        printf("I Love Assignment\n");
    }

    return 0;
}