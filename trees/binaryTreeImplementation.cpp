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

void display_preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    display_preorder(root->left);
    display_preorder(root->right);
}
void display_postorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    display_postorder(root->left);
    display_postorder(root->right);
    cout << root->data << " ";
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
int searchInorder(int inorder[], int start, int end, int curr)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTreeUsingPreorderAndInorder(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;
    int curr = preorder[index];
    index++;
    if (start > end)
    {
        return NULL;
    }

    Node *node = new Node(curr);
    int pos = searchInorder(inorder, start, end, curr);
    if (start == end)
    {
        return node;
    }
    node->left = buildTreeUsingPreorderAndInorder(preorder, inorder, start, pos - 1);
    node->right = buildTreeUsingPreorderAndInorder(preorder, inorder, pos + 1, end);

    return node;
}
Node *buildTreeUsingPostorderAndInorder(int postorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    static int index = 6;
    int curr = postorder[index];
    index--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = searchInorder(inorder, start, end, curr);
    node->right = buildTreeUsingPostorderAndInorder(postorder, inorder, pos + 1, end);
    node->left = buildTreeUsingPostorderAndInorder(postorder, inorder, start, pos - 1);
    return node;
}

int main()
{
    // struct Node *root = new Node(5);
    // root->left = new Node(3);
    // root->right = new Node(7);
    // root->left->left = new Node(2);
    // root->left->right = new Node(4);
    // root->right->left = new Node(6);
    // root->right->right = new Node(8);

    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8

        preorder = { 5 3 2 4 7 6 8 }
        postorder = { 2 4 3 6 8 7 5 }
        inorder = { 2 3 4 5 6 7 8}
    */

    // display_preorder(root);
    // cout << "\n";
    // display_postorder(root);
    // cout << "\n";
    // display_inorder(root);

    // buid tree using inorder and postorder
    int preorder[] = {5, 3, 2, 4, 7, 6, 8};
    int inorder[] = {2, 3, 4, 5, 6, 7, 8};
    int postorder[] = {2, 4, 3, 6, 8, 7, 5};

    // Node *root = buildTreeUsingPreorderAndInorder(preorder, inorder, 0, 6);
    // display_inorder(root);

    Node *root = buildTreeUsingPostorderAndInorder(postorder, inorder, 0, 6);
    display_postorder(root);
    return 0;
}