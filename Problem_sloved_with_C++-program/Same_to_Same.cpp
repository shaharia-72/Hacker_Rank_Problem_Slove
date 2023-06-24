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