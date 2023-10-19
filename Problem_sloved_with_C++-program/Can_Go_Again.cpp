/*Problem Statement

You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D. You need to tell the minimum cost from source node to destination. If there is no possible path from S to D then print Not Possible.

Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

Input Format

First line will contain N and E.
Next E lines will contain A, B and W.
Next line will contain source node S.
Next line will contain T, the number of test cases.
For each test case, you will get D.
Constraints

1 <= N <= 1000
1 <= E <= 1000
1 <= S <= N
1 <= T <= 1000
1 <= D <= N
-10^9 <= W <= 10^9
Output Format

Output the minimum cost for each test case.
Sample Input 0

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
1
5
1
2
3
4
5
Sample Output 0

0
-1
-2
-5
0
Sample Input 1

5 7
1 2 10
1 3 -2
3 2 1
2 4 7
3 4 -3
4 5 5
2 5 2
5
5
1
2
3
4
5
Sample Output 1

Not Possible
Not Possible
Not Possible
Not Possible
0
Sample Input 2

5 8
1 2 -2
1 3 -10
3 2 1
2 4 7
4 3 -3
4 5 5
2 5 2
4 1 1
1
5
1
2
3
4
5
Sample Output 2

Negative Cycle Detected*/
#include <bits/stdc++.h>
using namespace std;
int int_max = 1e7;

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

    int source;
    cin >> source;
    dis[source] = 0;
    bool cycle = false;

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
                // cycle = true;
                // break;
            }
        }
    }

    // for (int i = 1; i <= n - 1; i++)
    // {
    for (int j = 0; j < v.size(); j++)
    {
        edge ed = v[j];
        int a = ed.u;
        int b = ed.v;
        int w = ed.w;

        if (dis[a] != INT_MAX && dis[a] + w < dis[b])
        {

            // dis[b] = dis[a] + w;
            cycle = true;
            break;
        }
    }
    // }

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
        int destination;
        cin >> destination;

        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }

        else if (dis[destination] == INT_MAX)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[destination] << endl;
        }
    }
    return 0;
}
