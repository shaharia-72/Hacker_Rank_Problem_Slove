/*Problem Statement

You will be given a positive integer N and an array A of size N. Suppose, the index starts from 0, then you need to print all the values at even indexes in reverse way.

For example:

If the input is

5
10 20 30 40 50
You need to print 50 30 10 as their indexes are 4 2 0 respectively.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 10^5
1 <= A[i] <= 100 ; where A[i] are the values of array A.
Output Format

Output the values of even indexes in reverse way. Don't forget to put a space between two values.
Sample Input 0

5
10 20 30 40 50
Sample Output 0

50 30 10
Sample Input 1

6
10 20 30 40 50 60
Sample Output 1

50 30 10*/
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            printf("%d ", array[i]);
        }
    }
    return 0;
}