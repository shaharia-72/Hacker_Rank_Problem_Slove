/*Problem Statement

You are given a list of numbers. Now find the position of a specific number from the list; if the number is not found in the given list then you have to print Not Found.

Note: Find the first occurence of that number from left.

Input Format

Input starts with an integer T, denoting the number of test cases.
Next line contains N, size of the list.
Next line contains N, values of the list.
Last integer contains S, the number that you need to find.
Constraints

1 <= T <=20
1 <= N <=1000
1 <= S <=1000
Output Format

For each test case you have to print “Case T: R” (except quotes) where T is the test case and R is the position of the S from N integers. If S is not found in the given N integers then you have to print “Case T: Not Found” in a line.

Note: Don't forget to print a new line;

Sample Input 0*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == (n + 1) / 2 || j == (n + 1) / 2)
            {
                printf("#");
            }

            else
                printf("*");
        }

        printf("\n");
    }

    return 0;
}
