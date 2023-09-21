/*Problem Statement

You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree.

For example:

image

The output for the above tree will be: 210

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the total sum of that tree.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

210*/

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
int sum(B_tree_Node *root)
{
    if (root == NULL)
        return 0;

    int sum_of_all_left_node = sum(root->left);
    int sum_of_all_right_node = sum(root->right);

    int sum = sum_of_all_left_node + sum_of_all_right_node + root->val;
    return sum;
}

int main()
{
    B_tree_Node *root = B_tree_input();
    int sum_result = sum(root);
    cout << sum_result << endl;

    return 0;
}
