/*Problem Statement

You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an edge from A to B which will cost W. Also, you'll be given Q queries, for each query you'll be given X and Y, where X is the source and Y is the destination. You need to print the minimum cost from A to B for each query. If there is no connection between X and Y, print -1.

Note: There can be multiple edges from one node to another.

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
After that you'll get Q.
Next Q queries will contain X and Y.
Constraints

1 <= N <= 100
1 <= E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
1 <= Q <= 10^5
1 <= X, Y <= N
Output Format

Output the minimum cost for each query.
Sample Input 0

4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2
Sample Output 0

7
4
6
4
5
3
Sample Input 1

4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2
Sample Output 1

4
6
8
2
4
6*/

#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int u;
    int v;
    int w;
    edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;

    cin >> n >> e;
    vector<edge> v;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edge ed(a, b, w);

        // cout << ed.u << " " << ed.v << " " << ed.w << endl;

        v.push_back(ed);
    }

    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] != INT_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {

    //     if (dis[i] == INT_MAX)
    //     {
    //         cout << "-1" << endl;
    //     }
    //     else
    //     {
    //         cout << dis[i] << endl;
    //     }
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x] == INT_MAX || dis[y] == INT_MAX)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << dis[y] - dis[x] << endl;
        }
    }

    return 0;
}