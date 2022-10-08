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

void leftView(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty \n";
        return;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                cout << curr->data << " ";
            }

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
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

    cout << "Right View of BST = ";
    leftView(root);
    return 0;
}