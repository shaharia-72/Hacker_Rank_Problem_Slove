/*Problem Statement

You have a doubly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

You need to insert the value V at index X. Assume that index starts from 0.
After that for each query you need to print the linked list from left to right and right to left.
If the index is invalid, then print "Invalid".
Note: You must use doubly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 1000;
0 <= V <= 1000
Output Format

For each query print the linked list from left to right and right to left or print "Invalid" as asked.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.
Sample Input 0

5
1 10
0 10
1 20
3 30
2 30
Sample Output 0

Invalid
L -> 10
R -> 10
L -> 10 20
R -> 20 10
Invalid
L -> 10 20 30
R -> 30 20 10
Sample Input 1

10
0 10
1 20
0 30
1 40
6 50
0 60
4 70
4 80
2 90
1 100
Sample Output 1

L -> 10
R -> 10
L -> 10 20
R -> 20 10
L -> 30 10 20
R -> 20 10 30
L -> 30 40 10 20
R -> 20 10 40 30
Invalid
L -> 60 30 40 10 20
R -> 20 10 40 30 60
L -> 60 30 40 10 70 20
R -> 20 70 10 40 30 60
L -> 60 30 40 10 80 70 20
R -> 20 70 80 10 40 30 60
L -> 60 30 90 40 10 80 70 20
R -> 20 70 80 10 40 90 30 60
L -> 60 100 30 90 40 10 80 70 20
R -> 20 70 80 10 40 90 30 100 60 */
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

void insert(Node *&head, int index, int value)
{
    if (index < 0)
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

        while (tmp != NULL && index > 1)
        {
            tmp = tmp->next;
            index--;
        }

        if (tmp == NULL)
        {
            cout << "Invalid" << endl;

            return;
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
}

int main()
{
    Node *head = NULL;

    int n;
    cin >> n;

    while (n--)
    {
        int X, V;
        cin >> X >> V;
        insert(head, X, V);
    }

    return 0;
}
