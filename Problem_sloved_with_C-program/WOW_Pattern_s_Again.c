/*Write a C program that will take an integer N and creates this pattern for the corresponding inputs.

For example,

If N=3, the pattern look like this,
image

If N=6, the pattern look like this,
image

Input Format

You will be given a positive integer N as input.
Constraints

1 <= N <= 20
Output Format

Output the pattern
Sample Input 0

1
Sample Output 0

^
Sample Input 1

3
Sample Output 1

  ^
 ***
^^^^^
Sample Input 2

6
Sample Output 2

     ^
    ***
   ^^^^^
  *******
 ^^^^^^^^^
************/

#include <stdio.h>

int main()
{
    int rows, i, j, space;

    scanf("%d", &rows);

    for (i = 1; i <= rows; i++)
    {
        for (space = 1; space <= (rows - i); space++)
        {
            printf(" ");
        }
        for (j = 1; j <= (2 * i - 1); j++)
        {
            if (i % 2 == 0)
            {
                printf("*");
            }
            else
                printf("^");
        }
        printf("\n");
    }

    return 0;
}
