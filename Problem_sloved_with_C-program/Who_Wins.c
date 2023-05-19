/*Problem Statement

Tiger and Pathan are bored with movies and want to play a game. They will play the game in N round. Each time, both of them will guess a number X1 and X2, and whoever guesses the larger number will win that round. The final winner will be the one who wins the most rounds. In the event that they both win an equal number of times, the game will end in a draw.

Input Format

First line will contain N, the number of rounds.
Next N lines will contain two numbers X1 and X2, guessed by Tiger and Pathan respectively.
Constraints

1 <= N <= 1000
-10^9 <= X1, X2 <= 10^9
Output Format

Output "Tiger" if Tiger wins, "Pathan" if Pathan wins. If it is a draw, print "Draw" without the quotation marks.
Sample Input 0

5
10 20
30 20
15 16
100 20
50 45
Sample Output 0

Tiger
Explanation 0

Tiger won the 2nd, 4th and 5th round. Pathan won the 1st and 3rd round. So, Tiger is the winner!
Sample Input 1

5
10 20
30 20
15 16
20 20
50 45
Sample Output 1

Draw
Explanation 1

Tiger won the 2nd and 5th round. Pathan won the 1st and 3rd round. So, it's a draw!
Sample Input 2

4
10 20
20 10
10 30
25 25
Sample Output 2

Pathan
Explanation 2

Pathan won the 1st and 3rd round. Tiger won only the 2nd round. So, Pathan is the winner!*/

#include <stdio.h>
int main()
{
    int N, tiger = 0, pathan = 0;
    scanf("%d", &N);

    while (N--)
    {
        int a, b;

        scanf("%d %d", &a, &b);
        if (a > b)
        {
            tiger++;
        }

        else if (a < b)

        {
            pathan++;
        }
    }

    if (tiger > pathan)
    {
        printf("Tiger");
    }

    else if (tiger < pathan)
    {
        printf("Pathan");
    }
    else
        printf("Draw");

    return 0;
}