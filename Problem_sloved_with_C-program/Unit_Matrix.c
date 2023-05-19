/*You will be given a matrix of size N * N. You need to tell if it is unit matrix or not.

Note: A matrix is called a unit matrix if all the primary diagonal elements are 1 and all the non-diagonal elements are 0.

Input Format

First line will contain N, the row and column of the square matrix.
Then the N * N sized matrix will be given where the values are integer only.
Constraints

1 <= N <= 100
0 <= Values <= 100
Output Format

Ouput "YES" if the matrix is unit matrix, otherwise output "NO" without the quotation marks.
Sample Input 0

3
1 0 0
0 1 0
0 0 1
Sample Output 0

YES
Sample Input 1

5
1 0 0 0 0
0 1 0 0 0
0 0 1 0 1
0 0 0 1 0
0 0 0 0 1
Sample Output 1

NO*/

#include <stdio.h>
int main()
{
    int n, flag = 1;
    scanf("%d", &n);

    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (arr[i][j] != 1)
                {
                    flag = 0;
                }
            }
            else
            {
                if (arr[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
    }

    if (flag == 1)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");

    return 0;
}
