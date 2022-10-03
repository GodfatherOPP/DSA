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

int sumReplacement(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    root->data += sumReplacement(root->left) +
                  sumReplacement(root->right);
    return root->data;
}
void display_inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    display_inorder(root->left);
    cout << root->data << " ";
    display_inorder(root->right);
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
    cout << "root sum = " << sumReplacement(root) << "\n";
    display_inorder(root);
    return 0;
}