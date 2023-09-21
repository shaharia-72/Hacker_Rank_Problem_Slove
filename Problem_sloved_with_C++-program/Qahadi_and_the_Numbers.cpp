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

        vector<int> v;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            bool duplicates = false;
            for (int j : v)
            {
                if (num == j)
                {
                    duplicates = true;
                    break;
                }
            }

            if (duplicates)
            {
                count++;
            }
            else
            {
                v.push_back(num);
            }
        }

        cout << count << endl;
    }

    return 0;
}