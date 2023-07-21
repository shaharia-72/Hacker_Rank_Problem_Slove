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
