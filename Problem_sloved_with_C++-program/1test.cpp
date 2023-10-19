#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            int N = n / 2; // Change "sum" to "N"

            bool dp[2][N + 1]; // Use a 2D array with two rows

            for (int i = 0; i <= N; i++)
            {
                dp[0][i] = false;
                dp[1][i] = false;
            }

            dp[0][0] = true;

            for (int i = 1; i <= 2; i++)
            { // Change the loop range to 2
                for (int j = 0; j <= N; j++)
                {
                    if (i % 2 == 0)
                    {
                        if (i <= j)
                        {
                            dp[i % 2][j] = dp[(i - 1) % 2][j - i] || dp[(i - 1) % 2][j];
                        }
                        else
                        {
                            dp[i % 2][j] = dp[(i - 1) % 2][j];
                        }
                    }
                }
            }

            if (dp[2 % 2][N])
            { // Change dp[n][sum] to dp[2 % 2][N]
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
