/*Problem Statement

You will given an integer array A and the size N. You will also be given an integer value X. You need to tell how many times X was appeared in the array.

Input Format

First line will contain N.
Second line will contain the integer array A.
Third line will contain X.
Constraints

1 <= N <= 100
0 <= A[i] <= 1000; Here 0 <= i < N
0 <= X <= 1000
Output Format

Output the number of times X was appeared in the array.
Sample Input 0

6
4 3 5 3 3 5
3
Sample Output 0

3
Sample Input 1

6
4 3 5 3 3 5
10
Sample Output 1

0
Sample Input 2

10
5 0 7 0 7 6 4 7 7 1
7
Sample Output 2

4*/

#include <stdio.h>
int main()
{
    int n, count = 0;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int a;
    scanf("%d", &a);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}