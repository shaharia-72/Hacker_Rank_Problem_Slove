/*Problem Statement

You will be given three non-negative integers A,B and C. You need to tell if these integers form an equilateral triangle (A triangle whose three sides are the same and each side contains a positive value). If the answer is yes, print "Yes" otherwise "No".

Input Format

Input will contain A,B and C.
Constraints

0 <= A,B,C <= 100
Output Format

Output "Yes" or "No" without quotation.
Sample Input 0

2 4 2
Sample Output 0

No
Sample Input 1

3 3 3
Sample Output 1

Yes
Sample Input 2

0 0 0
Sample Output 2

No
Sample Input 3

0 1 2
Sample Output 3

No*/

#include <stdio.h>
int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    if (a == b && c == a && b == c)
    {
        if (a == 0 && c == 0 && b == 0)
        {
            printf("No");
        }

        else
            printf("Yes");
    }
    else
        printf("No");
    return 0;
}