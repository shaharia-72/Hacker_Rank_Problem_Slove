/*Problem Statement

Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants. Fairy asked him how many ways he can do this. She wanted Zarif to answer the maximum ways he can choose those marks.

Can you tell what will be the maximum number of ways to choose those marks to fulfill his dream?

Note: As the answer can be very long, whenever the answer gets bigger than 1e9+7, mod it with 1e9+7.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain a list A of N marks.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= M <= 1000
1 <= A[i] <= 100; 0 <= i < N
Output Format

Output the maximum number of ways.
Sample Input 0

5
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
2 900
30 40
3 904
2 6 5
2 904
2 5
Sample Output 0

1
0
1
92
10
Sample Input 1

2
30 0
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
20 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Sample Output 1

158493259
888281419*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[1005][1005];

int maxFunc(int n, int m, int a[])
{
    if (m == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int mark1;

    // int mark1 = (a[n - 1] <= m);

    if (a[n - 1] <= m)
    {
        mark1 = maxFunc(n, m - a[n - 1], a);
    }
    else
    {
        mark1 = 0;
    }

    int mark2 = maxFunc(n - 1, m, a);
    dp[n][m] = (mark1 + mark2) % mod;

    return dp[n][m];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        m = 1000 - m;

        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }
        }

        // int x = maxFunc(n, m, a[]);
        int x = maxFunc(n, m, a);
        cout << x << endl;
    }

    return 0;
}