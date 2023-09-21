#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        // for (char c : s)
        {
            char c = s[i];
            if (!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'B' && c == 'A')))
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        if (st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}