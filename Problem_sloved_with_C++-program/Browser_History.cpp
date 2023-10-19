/*Problem Statement

You are given a doubly linked list of strings. These strings refer to web addresses without any spaces. You will be given Q queries. In each query you will be given some commands. Type of commands are -

visit address - You need to go to that address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
next - You need to go to the next address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
prev - You need to go to the previous address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
Note: You can use Linked List or STL List to solve this problem.

Input Format

First line will contain the values of the doubly linked list, and will terminate with the string "end".
Second line will contain Q.
Next Q lines will contain the commands. It is guranteed that you will get "visit address" command at first which will contain a valid address. It will not contain valid address everytime!
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
1 <= Q <= 1000;
1 <= |Address| <= 100; Here |Address| is the length of the string address.
Output Format

For each query output as asked.
Sample Input 0

facebook google phitron youtube twitter end
12
visit phitron
prev
prev
prev
prev
next
visit twitter
next
next
prev
visit django
prev
Sample Output 0

phitron
google
facebook
Not Available
Not Available
google
twitter
Not Available
Not Available
youtube
Not Available
phitron*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

void printAddress(list<string> &addresses)
{
    if (!addresses.empty())
    {
        cout << addresses.front() << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

int main()
{
    list<string> addresses;
    string address;

    while (cin >> address)
    {
        if (address == "end")
        {
            break;
        }
        addresses.push_back(address);
    }

    int Q;
    cin >> Q;

    string command, arg;

    while (Q--)
    {
        cin >> command;

        if (command == "visit")
        {
            cin >> arg;
            bool found = false;

            for (const auto &addr : addresses)
            {
                if (addr == arg)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << addresses.front() << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (addresses.size() > 1)
            {
                addresses.pop_front();
                cout << addresses.front() << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (addresses.size() > 1)
            {
                addresses.pop_back();
                cout << addresses.back() << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
