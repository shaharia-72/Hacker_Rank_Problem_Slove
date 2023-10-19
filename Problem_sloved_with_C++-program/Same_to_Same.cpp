/*Problem Statement

You will be given two singly linked list of integer values as input. You need to check if all the elements of both list are same which means both list are same. If they are same print "YES" otherwise print "NO".

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the first singly linked list, and will terminate with -1.
Second line will contain the values of the second singly linked list, and will terminate with -1.
Constraints

1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" or "NO".
Sample Input 0

10 20 30 40 -1
10 20 30 40 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1
10 20 30 -1
Sample Output 1

NO
Sample Input 2

10 20 30 40 -1
40 30 20 10 -1
Sample Output 2

NO*/

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

void li_list(Node *&head, int val)
{

    Node *n = new Node(val);
    Node *tmp = head;

    if (head == NULL)
    {
        head = n;
        return;
    }

    while (tmp->next_address != NULL)
    {
        tmp = tmp->next_address;
    }

    tmp->next_address = n;
};

bool compare(Node *head1, Node *head2)
{
    // if (head1 != NULL && head2 != NULL)
    // {
    //     if (head1->val != head2->val)
    //     {
    //         return false;
    //     }

    //     head1 = head1->next_address;
    //     head2 = head2->next_address;
    // }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val != head2->val)
        {
            return false;
        }

        head1 = head1->next_address;
        head2 = head2->next_address;
    }

    // else if (head1 != NULL || head2 != NULL)
    // {
    //     return false;
    // }

    if (head1 != NULL || head2 != NULL)
    {
        return false;
    }

    return true;
}

void display(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next_address;
    }
};
int main()
{
    int n, val;
    // cin >> n;
    Node *head1 = NULL;
    Node *head2 = NULL;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> val;
    //     li_list(head, val);
    // }

    while (cin >> val)
    {
        if (val == -1)
        {
            break;
        }
        li_list(head1, val);
    }

    while (cin >> n)
    {
        if (n == -1)
        {
            break;
        }
        li_list(head2, n);
    }

    // display(head1);
    // display(head2);

    if (compare(head1, head2))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}