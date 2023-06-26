/*Problem Statement

You need to take a singly linked list of integer value as input. You need to remove the duplicate values and print the unique values in ascending order.

Note: You need to solve this using singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^3; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the new singly linked list in ascending order.
Sample Input 0

1 2 1 3 2 4 2 1 3 -1
Sample Output 0

1 2 3 4
Sample Input 1

2 2 2 2 -1
Sample Output 1

2
Sample Input 2

10 4 2 1 5 6 -1
Sample Output 2

1 2 4 5 6 10
Sample Input 3

5 4 3 5 4 2 5 3 2 4 5 1 2 3 4 5 -1
Sample Output 3

1 2 3 4 5
Sample Input 4

4 3 5 4 2 3 2 4 1 2 3 4 -1
Sample Output 4

1 2 3 4 5*/

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

void sort(Node *&head, Node *&tail)
{
    vector<int> val;

    Node *tmp = head;
    while (tmp != NULL)
    {
        val.push_back(tmp->val);
        tmp = tmp->next_address;
    }

    sort(val.begin(), val.end());

    tmp = head;
    for (int i = 0; i < val.size(); i++)
    {
        tmp->val = val[i];
        tmp = tmp->next_address;
    }
}

void remove_duplicates(Node *head, Node *tail)
{
    Node *tmp = head;
    while (tmp->next_address != NULL)
    {
        if (tmp->val == tmp->next_address->val)
        {
            tmp->next_address = tmp->next_address->next_address;
        }
        if (tmp->next_address == NULL)
            break;
        else if (tmp->val != tmp->next_address->val)
        {
            tmp = tmp->next_address;
        }
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

    sort(head, tail);
    remove_duplicates(head, tail);
    display(head);

    return 0;
}