/*Problem Statement

You need to take a singly linked list of integer value as input. You need to tell if the singly linked list forms a palindrome or not.

Note: You need to solve this using singly linked list, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" if it forms a palindrom otherwise print "NO".
Sample Input 0

1 2 3 2 1 -1
Sample Output 0

YES
Sample Input 1

1 2 2 1 -1
Sample Output 1

YES
Sample Input 2

1 -1
Sample Output 2

YES
Sample Input 3

1 2 3 1 -1
Sample Output 3

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
    Node *original = new Node(val);

    if (head == NULL)
    {
        head = original;
    }
    else
    {
        Node *original_head = head;
        while (original_head->next_address != NULL)
        {
            original_head = original_head->next_address;
        }
        original_head->next_address = original;
    }
}
// void display(Node *head)
// {
//     Node *tmp = head;
//     while (tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next_address;
//     }
// }

void print_original(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next_address;
    }
    cout << endl;
}

// void reverse(Node *&head)
// {
//     if (head == NULL)
//     {
//         return;
//     }

//     Node *tmp = reverse(head);
//     head->next->next = head;
//     head->next = NULL;
//     return;
// }

Node *reverse(Node *tmp, Node *cur)
{
    if (tmp == NULL)
    {
        return cur;
    }

    Node *reverse_node = tmp->next_address;
    tmp->next_address = cur;

    return reverse(reverse_node, tmp);
}

void print_reverse(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next_address;
    }
    cout << endl;
}

// bool palindrome(Node *head)
// {
//     Node *rev_head = NULL;
//     Node *rev_tail = NULL;
//     Node *tmp = head;

//     while (tmp != NULL)
//     {
//         reverse(rev_head, rev_tail, tmp->val);
//         tmp = tmp->next_address;
//     }

//     reverse(rev_head, rev_head);
//     tmp = head;
//     Node *tmp2 = rev_head;

//     while (tmp != NULL)
//     {
//         if (tmp->val == tmp2->val)
//         {
//             return false;
//         }
//         tmp = tmp->next_address;
//         tmp2 = tmp2->next_address;
//     }
//     return true;
// }

bool palindrome(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *tmp = head;
    Node *tmp1 = head;

    // while (tmp1->next_address != NULL)
    while (tmp1->next_address != NULL && tmp1->next_address->next_address != NULL)
    {
        tmp = tmp->next_address;
        tmp1 = tmp1->next_address->next_address;
    }

    Node *head2 = reverse(tmp->next_address, NULL);

    Node *ori = head;
    Node *rev = head2;

    while (ori != NULL && rev != NULL)
    {
        if (ori->val != rev->val)
        {
            return false;
        }
        ori = ori->next_address;
        rev = rev->next_address;
    }

    return true;
}

int main()
{
    Node *head = NULL;
    int value;

    while (cin >> value && value != -1)
    {
        li_list(head, value);
    }

    // print_original(head);
    // Node head = reverse(head);
    // Node *result = reverse(head, NULL);
    // print_reverse(result);

    if (palindrome(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    // Node *result = reverse(head, NULL);
    // print_reverse(result);

    return 0;
}