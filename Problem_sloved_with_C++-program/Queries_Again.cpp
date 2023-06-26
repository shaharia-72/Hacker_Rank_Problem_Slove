#include <iostream>
using namespace std;

// Define the structure for a node in the doubly linked list
struct Node
{
    int val;
    Node *prev;
    Node *next;
};

// insert a node in index
Node *insertNode(Node *head, int index, int val)
{
    // Create a new node
    Node *newNode = new Node;
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, make the new node the head
        head = newNode;
    }
    else if (index == 0)
    {
        // If the index is 0, insert the new node at the beginning
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {
        // Traverse the list to find the position to insert the new node
        Node *current = head;
        int currentPosition = 0;

        while (currentPosition < index - 1 && current != NULL)
        {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL)
        {
            // Invalid index, print "Invalid"
            cout << "Invalid" << endl;
            return head;
        }

        // Insert the new node at the desired index
        newNode->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

// doubly linked list from left to right and right to left
void print_doubly(Node *head)
{
    cout << "L -> ";
    Node *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    cout << "R -> ";
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->prev;
    }
    cout << endl;
}

int main()
{
    int Q;
    cin >> Q;

    Node *head = NULL;

    for (int i = 0; i < Q; i++)
    {
        int X, V;
        cin >> X >> V;
        head = insertNode(head, X, V);
        print_doubly(head);
    }

    // Free the memory allocated for the linked list
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
