#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

void left_to_right(Node *head)
{
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void right_to_left(Node *head)
{
    cout << "R -> ";
    Node *tmp = head;
    if (tmp == NULL)
    {
        cout << endl;
        return;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert(Node *&head, int &size, int index, int value)
{
    if (index < 0 || index > size)
    {
        cout << "Invalid" << endl;
        return;
    }

    Node *tmp1 = new Node(value);

    if (index == 0)
    {
        tmp1->next = head;
        if (head != NULL)
        {
            head->prev = tmp1;
        }
        head = tmp1;
    }
    else
    {
        Node *tmp = head;

        // while (tmp != NULL)
        // {
        //     tmp = tmp->next;
        // }
        // tmp = tmp->next;

        while (tmp != NULL && index > 1)
        {
            tmp = tmp->next;
            index--;
        }

        tmp1->prev = tmp;
        tmp1->next = tmp->next;

        if (tmp->next != NULL)
        {
            tmp->next->prev = tmp1;
        }
        tmp->next = tmp1;
    }

    left_to_right(head);
    right_to_left(head);
    size++;
}

int main()
{
    Node *head = NULL;
    int size = 0;

    int n;
    cin >> n;

    while (n--)
    {
        int X, V;
        cin >> X >> V;
        insert(head, size, X, V);
    }

    return 0;
}
