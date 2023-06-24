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
// void li_list(Node *&head, int val)
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
    // for (Node *i = head; i->next_address != NULL; i = i->next_address)
    for (Node *i = head; i != NULL; i = i->next_address)
    {
        // for (Node *j = i->next_address; j->next_address != NULL; j = j->next_address)
        for (Node *j = i->next_address; j != NULL; j = j->next_address)
        {
            if (i->val > j->val)
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
        // li_list(head, val);
        li_list(head, tail, val);
    }

    // swap(head);
    // display(head);
    max_min(head);

    // for (Node *i = head; i->next_address != NULL; i = i->next_address)
    // {
    //     for (Node *j = i->next_address; j != head; j = j->next_address)
    //     {
    //         if (i->val == j->val)
    //         {
    //             cout << i->val << endl;
    //         }
    //         else
    //             cout << i->val << " " << j->val << endl;
    //     }
    // }

    return 0;
}
