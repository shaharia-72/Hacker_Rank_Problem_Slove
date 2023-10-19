/*Problem Statement

Given a string s containing just the characters 'A' and 'B, determine if the input string is valid.

An input string is valid if the string is empty after doing some operatios. The available operations are:

B can delete its previous available character A along with itself. If there is no A available to delete, it will not delete itself.
A can delete its previous available character B along with itself. If there is no B available to delete, it will not delete itself.
Input Format

First line will contain T, the number of test cases.
Next T lines will contain the string S.
Constraints

1 <= T <= 1000
1 <= |S| <= 1000; Here |S| means the length of the string.
Output Format

Output "YES" if the string is valid, otherwise "NO".
Sample Input 0

10
AABB
BABA
BBAA
ABAB
AAAB
ABBB
ABBA
BAABAB
BBBAABA
AAABABBABB
Sample Output 0

YES
YES
YES
YES
NO
NO
YES
YES
NO
YES*/

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