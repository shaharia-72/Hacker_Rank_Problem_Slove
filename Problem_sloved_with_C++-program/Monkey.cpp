/*Problem Statement:

Amena has just learned alphabets. She can read write from a to z only in lowercase. But, Amena always writes in alphabetic order what she saw. Also she writes a line as a word. For example, she writes monkey as ekmnoy. Her mother wants to test her reading and writing skills. Her mother gave her some lines, can you tell what she will write?

Note: Input will be given by EOF.

Input Format

Input consist of a line S. The line will contain lowercase letters and spaces. It is possible that there are multiple spaces together and the line end with spaces.
Constraints

0 < |S| <= 100
Output Format

Output what Amena will write.
Sample Input 0

monkey
i love flower
Sample Output 0

ekmnoy
eefilloorvw*/

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