/*Problem Statement

Suppose there are M1 workers who can complete a work in D days. Unfortunately, some of them became sick before the start of the work, and now there are M2 workers. Can you tell how many days it will take for them to complete the work?

Note: If the answer is a floating value, print the integer part of the answer.

Input Format

Input will contain three positive integers M1, M2 and D.
Constraints

1 <= M1 <= 100
1 <= M2 <= M1
1 <= D <= 20
Output Format

Output how many days it will take for M2 workers.
Sample Input 0

10 5 15
Sample Output 0

30
Explanation 0

10 workers needed 15 days to complete the work, and it will take 30 days for 5 workers to complete that work.
Sample Input 1

4 1 5
Sample Output 1

20*/

#include <stdio.h>
int main()
{
    int m1, m2, d, md = 0;

    scanf("%d %d %d", &m1, &m2, &d);

    printf("%d", md = (m1 * d) / m2);

    return 0;
}