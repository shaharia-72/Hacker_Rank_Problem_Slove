/*Perfect Binary Tree
Problem
Submissions
Leaderboard
Discussions
Problem Statement

You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

Here is an example of perfect binary tree:

image

Also there is formula available to tell if a binary tree is perfect or not. The formula is :

Total number of nodes = (2^maxHeight)-1
Note: Here height is counted from 1. In the above image maximum height is 4, so total number of nodes are 2^4-1=15. So there should be 15 nodes to call it a perfect binary tree.

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output "YES" if the tree is perfect, "NO" otherwise.
Sample Input 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1 60 -1 -1 -1 -1 -1
Sample Output 1

NO
Sample Input 2

10 20 -1 -1 -1
Sample Output 2

NO
Sample Input 3

10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 3

YES
*/

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

int max_height(B_tree_Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l, r) + 1;
}

bool total_node(B_tree_Node *root)
{
    if (root == NULL)
        return true;

    int left_Height_node = max_height(root->left);
    int right_Height_node = max_height(root->right);

    return (left_Height_node == right_Height_node) && total_node(root->left) && total_node(root->right);
}

// int count_node(B_tree_Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int l = count_node(root->left);
//     int r = count_node(root->right);
//     return l + r + 1;
// }

int main()
{
    B_tree_Node *root = B_tree_input();

    // // int max = 0;
    // // int min = 0;
    // // int max, min;
    // // int max = INT_MAX;
    // // int min = INT_MIN;
    // int x;
    // cin >> x;

    // int tree_height = max_height(root);
    // int height = pow(2, tree_height) - 1;

    // int tree_count_node = count_node(root);

    // if (tree_count_node == height)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    //     cout << "NO" << endl;

    if (total_node(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}