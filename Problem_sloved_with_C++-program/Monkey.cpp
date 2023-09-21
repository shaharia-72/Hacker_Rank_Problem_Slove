#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    string word;
    bool firstWord = true;

    while ((c = cin.get()) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            if (!word.empty())
            {
                sort(word.begin(), word.end());
                cout << (firstWord ? "" : " ") << word;
                word.clear();
                firstWord = false;
            }
            if (c == '\n')
            {
                cout << endl;
                firstWord = true;
            }
        }
        else
        {
            word += c;
        }
    }

    return 0;
}