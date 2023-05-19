/*Problem Statement

You will be given a 2D matrix of N * M size. The matrix will contain integer value only. You need to print the values of last row and then print the values of last column.

Input Format

First line will contain N and M the row and column respectively.
Then the 2D matrix will be given.
Constraints

2 <= N,M <= 100
0 <= Element <= 100
Output Format

First line will contain the values of last row.
Second line will contain the values of last column.
Sample Input 0

3 4
1 2 3 4
5 6 7 8
6 5 4 2
Sample Output 0

6 5 4 2
4 8 2
Sample Input 1

5 3
1 2 3
5 6 7
6 5 4
3 5 4
1 2 3
Sample Output 1

1 2 3
3 7 4 4 3*/

#include <stdio.h>
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[N][M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = N - 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = M - 1; j < M; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }

    return 0;
}
