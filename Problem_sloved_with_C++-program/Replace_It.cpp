/*Problem Statement

You will be given two strings S and X. You need to replace all X from string S with a '$' sign.

Input Format

First line will contain T, the number of test cases.
Next T lines will contain a line with S and X.
Constraints

1 <= T <= 1000
1 <= |S|, |X| <= 1000
|X| <= |S|
Output Format

For each test cases output the modified string S.
Sample Input 0

2
thatsagoodmomentforgoodrelations good
canyoutellmewhereicanfindheriwillbegreatefultoyouifyoutellmetheanswer you
Sample Output 0

thatsa$momentfor$relations
can$tellmewhereicanfindheriwillbegreatefulto$if$tellmetheanswer*/

#include <bits/stdc++.h>
using namespace std;

string fun(string S)
{
    stringstream ss(S);
    string x, word;

    ss >> x;
    ss >> word;

    while (x.find(word) != -1)
    {
        x.replace(x.find(word), word.length(), "$");
    }

    return x;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string S;
        getline(cin, S);

        string replacestring = fun(S);
        cout << replacestring << endl;
    }
    return 0;
}
