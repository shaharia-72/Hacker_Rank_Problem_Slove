/*Problem Statement

    You will be given a string S which will contain Lowercase,
    Uppercase English alphabets and spaces.You need to tell which word occurs the most times and also the count of that word.

    Note : If there are multiple word which occurs the most,
    print the first word which became the maximum count before others.

Input Format

First line will contain T, the number of test cases.
Each test case will contain the string S.
Constraints

1 <= T <= 1000
1 <= |S| <= 10^4, Here |S| means the length of S.
Output Format

Output the word and the count that occurs the most.
Sample Input 0

1
Ratul loves to play football when he gets time but Ratul is not a good player so his teacher asked Ratul if he can play with him so that Ratul can progress
Sample Output 0

Ratul 4
Sample Input 1

2
ratul piyush fohad shuvo rafi piyush fohad ratul
jony jony yes papa eating sugar no papa telling lies no papa open your mouth ha ha ha
Sample Output 1

piyush 2
papa 3
Submissions: 423
Max Score: 20
Difficulty: Easy
Rate This Challenge:


More
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> mp;
        int max_value = 0;
        int min_value = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            mp[num]++;

            if (mp[num] > max_value || (mp[num] == max_value && num > min_value))
            {
                max_value = mp[num];
                min_value = num;
            }
        }

        cout << count << " " << first_max << endl;
    }

    return 0;
}
