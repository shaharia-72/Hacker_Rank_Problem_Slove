/*Problem Statement

You will be given an undirected graph as input. You will be given a query Q, for each query you will be given a source S and a destination D. You need to tell the minimum destination from source to destination for each query.

Note: If there is no path in between the source and destination, print -1.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
Next E lines will contain A, B which means there is a edge between node A and B.
Next line will contain Q, the number of queries.
For each query every line will contain S and D.
Constraints

1 <= N, E <= 1000
1 <= Q <= 1000
0 <= S, D <= 10^5
Output Format

Output the minimum destination from source to destination for each query.
Sample Input 0

6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0
Sample Output 0

2
3
3
2
2
0*/
#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 5;
const int N = 100005;
vector<int> adj[N];

int bfs(int source, int destination, int n)
{
    queue<int> q;

    // vector<int> visited;
    vector<int> visited(n + 1, -1);
    // vector<int> visited(n, -1);
    visited[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (u == destination)
        {
            return visited[u];
        }

        for (int v : adj[u])
        {
            if (visited[v] == -1)
            {
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
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

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int source, destination;
        cin >> source >> destination;

        int minimum_destination = bfs(source, destination, n);
        cout << minimum_destination << endl;
    }

    return 0;
}