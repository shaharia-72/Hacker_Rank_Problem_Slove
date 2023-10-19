/*Problem Statement

You will be given a chessboard of NxM size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K(Ki and Kj), and the queen's cell Q(Qi and Qj). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below:image

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain Ki and Kj.
Third line of each test case will contain Qi and Qj.
Constraints

1 <= T <= 100
1 <= N, M <= 100
0 <= Ki, Qi < N
0 <= Kj, Qj < M
Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print -1.
Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1
Sample Output 0

6
0
3
-1
Explanation 0

For the first test case, one of the possible answer could be this way:*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> path = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool is_valid(int cI, int cJ, int N, int M)
{
    return (cI >= 0 && cI < N && cJ >= 0 && cJ < M);
}

int bfs(int si, int sj, int Qi, int Qj, int N, int M)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        int ci = current.first;
        int cj = current.second;
        q.pop();

        if (ci == Qi && cj == Qj)
        {
            return dis[ci][cj];
        }

        for (int i = 0; i < 8; i++)
        {
            int ni = ci + path[i].first;
            int nj = cj + path[i].second;

            if (is_valid(ni, nj, N, M) && !vis[ni][nj])
            {
                vis[ni][nj] = true;
                q.push({ni, nj});
                dis[ni][nj] = dis[ci][cj] + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M, Ki, Kj, Qi, Qj;
        cin >> N >> M >> Ki >> Kj >> Qi >> Qj;

        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));

        int minSteps = bfs(Ki, Kj, Qi, Qj, N, M);

        cout << minSteps << endl;
    }

    return 0;
}
