/*Same to Same Again
Problem
Submissions
Leaderboard
Discussions
Problem Statement

There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

Note: You need to implement Stack and Queue to solve this problem. You can't insert those values to anything else and also you can't use STL here. You can implement stack and queue by linked list or array as you wish.

Input Format

First line will contain N and M.
Second line will contain list A with N values.
Third line will contain list B with M values.
Constraints

1 <= N, M <= 10^6
0 <= Values of list A and B <= 1000
Output Format

Output "YES" if they were same, otherwise "NO".
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
10 20 30 40 50
50 40 30 20
Sample Output 2

NO*/

#include <bits/stdc++.h>
using namespace std;

class s_tack
{
public:
    int arr[1000];
    int index = -1;

    void push(int value)
    {
        arr[++index] = value;
    }

    int pop()
    {
        return arr[index--];
    }

    int top()
    {
        return arr[index];
    }

    bool empty()
    {
        return index == -1;
    }
};

class q_ueue
{
public:
    int arr[1000];
    int front_index = 0;
    int index = -1;
    int size = 0;

    void push(int value)
    {
        arr[++index] = value;
        size++;
    }

    int pop()
    {
        int value = arr[front_index++];
        size--;
        return value;
    }

    int front()
    {
        return arr[front_index];
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    s_tack s;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        s.push(value);
    }

    q_ueue q;
    for (int i = 0; i < m; i++)
    {
        int value;
        cin >> value;
        q.push(value);
    }

    while (!s.empty() && !q.empty())
    {
        if (s.top() != q.front())
        {
            cout << "NO" << endl;
            return 0;
        }
        s.pop();
        q.pop();
    }

    if (s.empty() && q.empty())
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}