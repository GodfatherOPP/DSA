#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *solve(Node *root, int &k, int node)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }
    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if (left != NULL && right == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT32_MAX;
            return root;
        }
        return left;
    }
    if (left == NULL && right != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT32_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int KthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}
int main()
{

    // Find number of paths in tree which have sum k
    /*
               5
           3       1
         2   4   6   4

    */

    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(4);
    cout << "\n kth ancestor of a tree (k==2):  " << KthAncestor(root, 1, 4);
    return 0;
}