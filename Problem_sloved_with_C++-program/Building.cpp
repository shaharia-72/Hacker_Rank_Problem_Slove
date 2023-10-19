/*Problem Statement

You have just opened a dish cable business and you want to connect your dish lines in your area. In your area there are N buldings and E roads. The roads are two way obviously. In each road there is a cost of connecting the cables. You want to connect all buldings in such a way that there is connection from any building to another, not necessary to be directly.

As you are a businessman, you want the total cost to be minimum. Can you tell the minimum total cost to do the work?

Note: There can be multiple road from one building to another. If it is not possible to connect all the building, print -1.

Input Format

First line will contain N and E.
Next E lines will contain A, B and W which means there is a connection in between A and B where the cost for connecting the cable is W.
Constraints

1 <= N, E <= 10^5
1 <= A, B <= N
1 <= W <= 10^9
Output Format

Output the minimum cost.
Sample Input 0

5 7
1 2 10
1 3 5
3 2 4
2 4 1
3 4 2
4 5 3
1 5 2
Sample Output 0

8
Sample Input 1

3 2
1 2 10
2 1 2
Sample Output 1

-1*/
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a;
    int b;
    int w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    // return a.w > b.w;
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }

        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    for (Edge val : v)
    {
        // cout << val.a << " " << val.b << " " << val.w << " " << endl;
        int a = val.a;
        int b = val.b;
        int w = val.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
        {
            continue;
        }
        ans.push_back(val);
        dsu_union(a, b);
    }

    if (ans.size() != n - 1)
    {
        cout << -1 << endl;
        return 0;
    }

    long long sum = 0;

    for (Edge val : ans)
    {
        sum += (long long)val.w;
    }

    cout << sum << endl;

    return 0;
}