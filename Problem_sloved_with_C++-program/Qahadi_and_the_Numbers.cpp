/*Problem Statement

Qahadi is playing with numbers. He loves unique numbers and wants them a lot. He has some numbers, and it is possible that there are some duplicates. So, he wants to remove those duplicate numbers.

In a move he can remove a number that is currently in the list more than once. Can you tell how many moves does he need to make all the numbers unique.

For example,

If Qahadi had the numbers 1, 5, 10, 5, 2, 5, 10, 5, 1; then he will need 5 moves to remove 1, 5, 5, 5, 10 from the list and make the list: 1, 5, 10, 2 where all of the values are unique.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N, the size of the list.
Second line of each test case will contain the list A of size N.
Constraints

1 <= T <= 100
1<= N <= 10^4
-10^9 <= A[i] <= 10^9 ; Here A[i] means the values of the list.
Output Format

Output how many moves does he need to make the list unique.
Sample Input 0

4
5
1 2 3 4 5
5
1 1 1 1 1
10
-5 2 4 -5 -2 2 4 3 2 -3
5
-2 -3 -4 -2 -3
Sample Output 0

0
4
4
2*/

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

        vector<int> v;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            bool duplicates = false;
            for (int j : v)
            {
                if (num == j)
                {
                    duplicates = true;
                    break;
                }
            }

            if (duplicates)
            {
                count++;
            }
            else
            {
                v.push_back(num);
            }
        }

        cout << count << endl;
    }

    return 0;
}