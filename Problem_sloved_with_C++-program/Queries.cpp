#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_reverse(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

int insert(Node *head, int index, int val)
{
    Node *n = new Node(val);

    if (head == NULL)
    {
        head = head;
    }

    else if (index == 0)
    {
        n->next = head;
        n->prev = n;
        head = n;
    }

    else
    {
        Node *n = head;
        int
    }
}

int main()
{
    int n, X, V;
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    int i = 0;
    while (n)
    {
        cin >> X >> V;
        insert(head, X, V);
        print(head);
        print_reverse(head);
    }

    return 0;
}
