/*Problem Statement

You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.
Constraints

1 <= N, M <= 1000
Output Format

Output the minimum area.
Sample Input 0

6 5
..-..
..-..
-----
.-...
.----
.....
Sample Output 0

3
Sample Input 1

3 3
---
---
---
Sample Output 1

-1*/
#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int n, m;
int position = INT_MAX;

const int N = 1005;
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool is_valid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
    {
        return true;
    }
    else
        return false;
}

// void bfs(int si, int sj)
int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    // dis[si][sj] = 0;
    vis[si][sj] = true;
    int component = 0;

    // while (!q.empty())
    while (!q.empty())
    {
        // pi parent;
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;

        q.pop();
        component++;

        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            // cout << cI << " " << CJ << endl;
            if (is_valid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
                // dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
    return component;
}
int main()
{
    // int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char cell;
            cin >> cell;
            if (cell == '-')
            {
                vis[i][j] = true;
            }
            // cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                int component = bfs(i, j);
                position = min(position, component);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }

    // int si, Sj;
    // cin >> si >> Sj;
    // bfs(si, Sj);

    // int si, sj, di, dj;
    // cin >> si >> sj;
    // cin >> di >> dj;
    // bfs(si, sj);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // if (vis[di][dj])
    if (position == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << position << endl;
    }

    return 0;
}