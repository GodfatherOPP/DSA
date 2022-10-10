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

void verticalTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    map<int, map<int, vector<int>>> result;
    queue<pair<Node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        result[hd][level].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : result)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {

                cout << k
                     << " ";
            }
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

    cout << "vertical Traversal:  ";
    verticalTraversal(root);
    return 0;
}