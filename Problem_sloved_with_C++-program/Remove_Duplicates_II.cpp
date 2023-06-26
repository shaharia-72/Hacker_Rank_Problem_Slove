/*Problem Statement

You need to take a linked list of integer value as input using STL List. You need to remove the duplicate values and print the unique values in ascending order.

Note: You need to solve this using STL list, otherwise you will not get marks.

Input Format

Input will contain the values of the linked list, and will terminate with -1.
Constraints

1 <= N <= 10^5; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output the new linked list in ascending order.
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

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next_address;
//     Node(int val)
//     {
//         this->val = val;
//         this->next_address = NULL;
//     }
// };

// void li_list(Node *&head, Node *&tail, int val)
// {

//     Node *n = new Node(val);

//     if (head == NULL)
//     {
//         head = n;
//         tail = n;
//         return;
//     }
//     tail->next_address = n;
//     tail = n;
// };

// void Remove_Duplicate(Node *head, Node *tail)
// {
//     list<int> mylist;

//     Node *tmp = head;
//     while (tmp != NULL)
//     {
//         mylist.push_back(tmp->val);
//         tmp = tmp->next_address;
//     }
//     mylist.sort();
//     mylist.unique();
//     tmp = head;
//     while (!mylist.empty())
//     {
//         tmp->val = mylist.front();
//         mylist.pop_front();
//         tmp = tmp->next_address;
//     }

//     for (int value : mylist)
//     {
//         li_list(head, tail, value);
//     }
// }

// void display(Node *head)
// {
//     Node *tmp = head;
//     while (tmp != NULL)
//     {
//         cout << tmp->val << " ";
//         tmp = tmp->next_address;
//     }
// }

// int main()
// {
//     int val;
//     Node *head = NULL;
//     Node *tail = NULL;

//     while (cin >> val)
//     {
//         if (val == -1)
//         {
//             break;
//         }
//         li_list(head, tail, val);
//     }

//     Remove_Duplicate(head, tail);
//     display(head);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> mylist;
    int val;

    while (cin >> val && val != -1)
    {
        mylist.push_back(val);
    }

    mylist.sort();
    mylist.unique();

    for (int val : mylist)
    {
        cout << val << " ";
    }

    return 0;
}