/*Problem Statement

You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

Note: There will be no component with single node.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
Next E lines will contain A, B which means there is a edge between node A and B.
Constraints

1 <= N, E <= 1000
Output Format

Output the number of nodes in each component in ascending order.
Sample Input 0

9 7
0 1
1 2
0 2
2 3
4 5
5 7
8 9
Sample Output 0

2 3 4
Explanation 0

The components are shown for the sample test case:
image

Sample Input 1

5 3
999 1000
100 500
500 600
Sample Output 1

2 3*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool visited[N];

int bfs(int s)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    int number_of_cc = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                number_of_cc++;
            }
        }
    }

    return number_of_cc;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cc;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int number_of_cc = bfs(i);
            if (number_of_cc > 1)
            {
                cc.push_back(number_of_cc);
            }
        }
    }

    sort(cc.begin(), cc.end());

    for (int v : cc)
    {
        cout << v << " ";
    }

    cout << endl;

    return 0;
}
