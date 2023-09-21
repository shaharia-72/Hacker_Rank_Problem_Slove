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

        int thief = 0;
        int pearls_code;

        for (int i = 0; i < n; i++)
        {
            cin >> pearls_code;
            thief ^= pearls_code;
        }

        cout << thief << endl;
    }

    return 0;
}