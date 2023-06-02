/*Problem Statement

Write a program to determine if a given string contains the word "Ratul." If the word is present in the string, the program should output "YES," otherwise it should output "NO."

NOTE: You need to find only "Ratul"; not "ratul" or "RatuL" or any other form. Words are separated by spaces.

Input Format

Input will contain a string S containing names. There is a space in between two names.
Constraints

1 <= |S| <= 1000; Here |S| means the length of the string.
Output Format

Output YES or NO according to the question.
Sample Input 0

Rahat Rifat Sakib Asif Sifat Ratul Munna
Sample Output 0

YES
Sample Input 1

Rahat Rifat Sakib Asif Sifat Munna
Sample Output 1

NO*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    // cout << s << endl;

    stringstream ss(s);
    string word;

    // while (((string)(ss >> word)) == "Ratul")
    while (ss >> word)
    {
        // cout << word << endl;
        if (word == "Ratul")
        {
            cout << "YES" << endl;
            // break;
            return 0;
        }

        // else
        //     break;
    }
    cout << "NO" << endl;

    return 0;
}