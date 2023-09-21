#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        stack<char> colors;

        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (!colors.empty() && ((colors.top() == 'R' && c == 'B') || (colors.top() == 'B' && c == 'R')))
            {
                colors.pop();
                colors.push('P');
            }
            else if (!colors.empty() && ((colors.top() == 'R' && c == 'G') || (colors.top() == 'G' && c == 'R')))
            {
                colors.pop();
                colors.push('Y');
            }
            else if (!colors.empty() && ((colors.top() == 'B' && c == 'G') || (colors.top() == 'G' && c == 'B')))
            {
                colors.pop();
                colors.push('C');
            }
            else
            {
                colors.push(c);
            }
        }

        string result = "";
        while (!colors.empty())
        {
            result = colors.top() + result;
            colors.pop();
        }

        cout << result << endl;
    }

    return 0;
}
