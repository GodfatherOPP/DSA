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

void topView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    map<int, int> result;

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *frontNode = temp.first;
        int hd = temp.second;
        q.pop();
        if (result.find(hd) == result.end())
        {
            result[hd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : result)
    {
        cout << i.second << " ";
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

    cout << "Top View:  ";
    topView(root);
    return 0;
}