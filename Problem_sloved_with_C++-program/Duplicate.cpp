#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    auto it = adjacent_find(a.begin(), a.end());

    if (it != a.end())
    {
        cout << "YES" << endl;
    }

    else
        cout << "NO" << endl;

    return 0;
}