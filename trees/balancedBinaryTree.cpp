#include <iostream>
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

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = Height(root->left);
    int rh = Height(root->right);

    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    // Time complexity is O(n)
    if (root == NULL)
    {
        return true;
    }

    if (isBalanced(root->left) == false || isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = Height(root->left);
    int rh = Height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Balanced(Node *root, int *Height)
{
    if (root == NULL)
    {
        *Height = 0;
        return true;
    }

    int lh = 0, rh = 0;
    if (Balanced(root->left, &lh) == false || Balanced(root->right, &rh) == false)
    {
        return false;
    }

    *Height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    int h1 = 0, h2 = 0;
    cout << "isBalanced 1 = " << Balanced(root, &h1) << "\n";
    cout << "isBalanced 2 = " << Balanced(root2, &h2) << "\n";
    return 0;
}