/*Problem Statement

You need to take a singly linked list of integer value as input. Then you need to sort the linked list in descending order and print the middle element of it. If there are multiple values in the middle, print both.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the value/values of the middle element.
Sample Input 0

20 10 40 30 50 -1
Sample Output 0

30
Sample Input 1

20 30 10 40 60 50 -1
Sample Output 1

40 30
Sample Input 2

726 -1
Sample Output 2

726
Sample Input 3

348 726 -1
Sample Output 3

726 348*/

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

void swap(Node *&head)
{

    for (Node *i = head; i != NULL; i = i->next_address)
    {

        for (Node *j = i->next_address; j != NULL; j = j->next_address)
        {

            if (i->val < j->val)
            {
                swap(i->val, j->val);
            }
        }
    }
}

int size(Node *&head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        tmp = tmp->next_address;
        count++;
    }
    return count;
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

void max_min(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    swap(head);
    Node *tmp = head;
    int cnt = size(head);
    int mid = (cnt + 1) / 2;

    for (int i = 1; i <= mid; i++)
    {
        if (i == mid)
        {
            cout << tmp->val;

            if (cnt % 2 == 0)
            {
                cout << " " << tmp->next_address->val;
            }
        }
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

    max_min(head);

    return 0;
}
