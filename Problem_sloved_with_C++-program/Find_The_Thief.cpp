/*Problem Statement

Sakib threw a party in his house to celebrate his birthday. He told his friends a dress code to wear, the dress code is to wear even unique pearls in his/her dress, where each pearl will have a code written on it. Unfortunately there was a thief planning to rob the house. The thief knew about the dress code, but he didn't know the exact number of pearls they needed to wear. So the thief wears an odd number of pearls in his dress.

You have N numbers where each number represents a pearl code, you need to detect the code of the thief's pearl so that you can detect the thief.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain an positive integer N which is an odd number.
Second line of each test case will contain N integer values representing pearl code.
Constraints

1 <= T <= 100
1 <= N <= 10^4
-10^9 <= code <= 10^9
Output Format

Output the code of the thief's pearl.
Sample Input 0

3
5
1 3 2 1 2
9
1 2 3 2 3 2 3 1 3
7
-10 2 3 -10 2 -3 3
Sample Output 0

3
2
-3*/
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