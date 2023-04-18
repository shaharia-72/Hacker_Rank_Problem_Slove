/*Problem Statement

You will be given a positive integer N and N numbers after that. You need to tell the sum of even numbers and the sum of odd numbers separated by a space.

Input Format

First line will contain N.
Second line will contain N values named V.
Constraints

1 <= N <= 10^5
1 <= V <= 100
Output Format

Output the sum of even numbers first, then sum of odd numbers.
Sample Input 0

5
5 1 4 7 2
Sample Output 0

6 13
Sample Input 1

5
2 4 6 8 10
Sample Output 1

30 0
Sample Input 2

5
1 3 5 7 9
Sample Output 2

0 25*/
#include <stdio.h>
int main()
{
    int n, add = 0, odd = 0;
    scanf("%d", &n);
    // printf("%d\n", n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {

            add = add + array[i];
        }
        else
        {
            odd = odd + array[i];
        }
        // printf("%d ", add);

        // printf("%d ", array[i]);
    }
    printf("%d %d", add, odd);

    return 0;
}