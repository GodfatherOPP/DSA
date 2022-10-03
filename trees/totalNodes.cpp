#include <iostream>
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

int totalNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}
int totalNodesSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return totalNodesSum(root->left) + totalNodesSum(root->right) + root->data;
}
int main()
{
    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    cout << totalNodes(root) << " " << totalNodesSum(root);
    return 0;
}