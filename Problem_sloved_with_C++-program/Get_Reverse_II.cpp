/*Problem Statement

You will be given data for N students, where each student will have a name (nm), class (cls), section (s) and student ID (id) which will be unique.

Your task is reverse their id and print all the students data. That means the id of the first student will be replaced by the id of the last student, the id of the second student will be replaced by the id of the second last student and so on. See the sample input and output for more clarifications.

Input Format

First line will contain N.
Next N lines will contain nm, cls, s, and id respectively.
Constraints

1 <= N <= 100
1 <= |nm| <= 100 and will contain only English alphabets.
1 <= cls <= 10
'A' <= s <= 'Z'
1 <= id <= 100
Output Format

Output all the students data after reversing their id.
Sample Input 0

3
Rakib 7 B 90
Sakib 10 A 85
Ahsan 9 C 36
Sample Output 0

Rakib 7 B 36
Sakib 10 A 85
Ahsan 9 C 90
Sample Input 1

4
Munna 8 D 10
Shojoy 9 E 11
Asif 10 C 12
Joy 9 G 13
Sample Output 1

Munna 8 D 13
Shojoy 9 E 12
Asif 10 C 11
Joy 9 G 10
Sample Input 2

4
Munna 8 D 10
Shojoy 9 E 11
Asif 10 C 12
Joy 9 G 13
Sample Output 2

Munna 8 D 13
Shojoy 9 E 12
Asif 10 C 11
Joy 9 G 10*/

#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string nm;
    int cls;
    char s;
    int id;
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    Student arr[n];

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i].nm >> arr[i].cls >> arr[i].s >> arr[i].id;
    }

    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i].id, arr[n - i - 1].id);
    }

    for (int i = 0; i < n; i++)
    {

        cout << arr[i].nm << " " << arr[i].cls << " " << arr[i].s << " " << arr[i].id << endl;
    }

    return 0;
}
