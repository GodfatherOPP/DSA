// INCOMPLETE
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

void zigZagTravarsal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    bool LeftToRight = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            int index = LeftToRight ? i : size - i - 1;
            ans[index] = node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        LeftToRight = !LeftToRight;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
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

    cout << "Zig-Zag Travarsal  :  ";
    zigZagTravarsal(root);
    return 0;
}