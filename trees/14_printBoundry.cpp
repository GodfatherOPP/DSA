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

void printLeftBoundry(Node *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    cout << root->data << " ";
    if (root->left)
    {
        printLeftBoundry(root->left);
    }
    else
    {
        printLeftBoundry(root->right);
    }
}

void printLeafNodes(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);

    return;
}

void printRightBoundry(Node *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        printLeftBoundry(root->right);
    }
    else
    {
        printLeftBoundry(root->left);
    }
    cout << root->data << " ";
}

void printBoundry(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printLeftBoundry(root->left);
    printLeafNodes(root);
    printRightBoundry(root->right);
}

int main()
{

    /*
               5
           3       7
         2   4   6   8

    */

    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Print Boundry :  ";
    printBoundry(root);
    return 0;
}