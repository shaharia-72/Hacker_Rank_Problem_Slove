/*Problem Statement

You need to take a singly linked list of integer value as input and print the maximum and minimum value of the singly linked list.

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the maximum value then the minimum value.
Sample Input 0

2 4 1 5 3 6 -1
Sample Output 0

6 1
Sample Input 1

2 -1
Sample Output 1

2 2*/

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

void find_min_max(Node *&head, int &a, int &b)
{
    if (head == NULL)
    {
        a = -1;
        b = -1;
        return;
    }

    a = head->val;
    b = head->val;

    const Node *temp = head->next_address;
    while (temp != NULL)
    {
        // a = min(min, temp->val);
        // b = max(max, temp->val);
        a = min(a, temp->val);
        b = max(b, temp->val);
        temp = temp->next_address;
    }
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
    Node *head = NULL;

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
        li_list(head, val);
    }

    // display(head);

    int minimum, maximum;
    find_min_max(head, minimum, maximum);

    cout << maximum << " " << minimum << endl;

    return 0;
}