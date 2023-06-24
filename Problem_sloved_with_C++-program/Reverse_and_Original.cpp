/*Problem Statement

You need to take a singly linked list of integer value as input. Then you need to print the singly linked list in reverse order, after that print the original linked list also.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 10^9; Here V is the value of each node.
Output Format

In first line, output the linked list in reverse order.
In second line, print the original linked list.
Sample Input 0

10 20 30 40 50 -1
Sample Output 0

50 40 30 20 10
10 20 30 40 50
Sample Input 1

20 40 50 10 -1
Sample Output 1

10 50 40 20
20 40 50 10
Submissions: 337
Max Score: 20
Difficulty: Easy
Rate This Challenge:


More
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next_address;
    Node(int val)
    {
        this->val = val;
        this->next_address = NULL;
    }
};

void li_list(Node *&head, Node *&tail, int val)
{

    Node *n = new Node(val);

    if (head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    tail->next_address = n;
    tail = n;
};

void reverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    reverse(head->next_address);
    cout << head->val << " ";
}

void display(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next_address;
    }
}
int main()
{
    int val;
    Node *head = NULL;
    Node *tail = NULL;

    while (cin >> val)
    {
        if (val == -1)
        {
            break;
        }
        li_list(head, tail, val);
    }

    reverse(head);
    cout << endl;
    display(head);

    return 0;
}