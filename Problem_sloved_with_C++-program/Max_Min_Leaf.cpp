/*Problem Statement

You will be given a binary tree as input in level order. You need to give the maximum and minimum values of all the leaf nodes available.

For example:

image

The output for the above tree will be: 60 40

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the maximum value then the minimum value of all leaf nodes.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60 40*/

#include <bits/stdc++.h>
using namespace std;

class B_tree_Node
{
public:
    int val;
    B_tree_Node *left;
    B_tree_Node *right;

    B_tree_Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to input a binary tree
B_tree_Node *B_tree_input()
{
    int val;
    cin >> val;
    B_tree_Node *root;

    // If the value is -1, it represents a NULL node, so the tree is empty
    if (val == -1)
        return NULL;
    else
        root = new B_tree_Node(val);

    queue<B_tree_Node *> q;
    q.push(root);

    // Continue to input nodes level by level using BFS traversal
    while (!q.empty())
    {
        B_tree_Node *parent = q.front();
        q.pop();

        // Input the left and right child values of the current parent node
        int l, r;
        cin >> l >> r;

        B_tree_Node *root_left;
        B_tree_Node *root_right;

        // If the child value is -1, it represents a NULL node
        if (l == -1)
            root_left = NULL;
        else
            root_left = new B_tree_Node(l);

        if (r == -1)
            root_right = NULL;
        else
            root_right = new B_tree_Node(r);

        // Assign the left and right children to the current parent node
        parent->left = root_left;
        parent->right = root_right;

        // Keep adding non-NULL children to the queue for further processing
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }

    return root;
}

// Function to perform level-order traversal and print the nodes' values
// int max_min(B_tree_Node *root, int &max, int &min)
void max_min(B_tree_Node *root, int &max, int &min)
{
    if (root == NULL)
    {
        return;
    }

    queue<B_tree_Node *> q;
    q.push(root);

    while (!q.empty())
    {
        B_tree_Node *current = q.front();
        q.pop();

        if (current->left == NULL && current->right == NULL)
        {
            if (current->val > max)

            {
                max = current->val;
            }

            if (current->val < min)
            {
                min = current->val;
            }
        }
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

int main()
{
    B_tree_Node *root = B_tree_input();

    // int max = 0;
    // int min = 0;
    // int max, min;
    // int max = INT_MAX;
    // int min = INT_MIN;
    int min = INT_MAX;
    int max = INT_MIN;

    max_min(root, max, min);
    cout << max << " " << min << endl;

    return 0;
}