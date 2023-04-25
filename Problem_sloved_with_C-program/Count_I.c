/*Problem Statement

You will be given an integer array A of size N. You need to count the number of even elements and the number of odd elements in the array and print them.

Input Format

First line will contain N, the size of the array
Second line will contain the array A.
Constraints

1 <= N <= 1000
0 <= A[i] <= 100; here 0 <= i < N
Output Format

Output the number of even elements first, then print the number of odd elements.
Sample Input 0

6
73 35 92 0 60 88
Sample Output 0

4 2
Sample Input 1

3
7 3 10
Sample Output 1

1 2*/
#include <stdio.h>
int main()
{
    int n, even = 0, odd = 0;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        // printf("%d\n", arr[i]);

        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
            odd++;
    }
    printf("%d %d", even, odd);

    return 0;
}