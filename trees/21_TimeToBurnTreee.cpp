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
void BurnTree(Node *root, int &time, map<Node *, Node *> childToParent)
{
    if (root == NULL)
    {
        return;
    }

    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = 1;
    time++;
    while (!q.empty())
    {

        int size = q.size();

        int check = 0;
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (frontNode->left && !visited[frontNode->left])
            {
                check = 1;
                q.push(frontNode->left);
                visited[frontNode->left] = 1;
            }
            if (frontNode->right && !visited[frontNode->right])
            {
                check = 1;
                q.push(frontNode->right);
                visited[frontNode->right] = 1;
            }
            if (childToParent[frontNode] && !visited[childToParent[frontNode]])
            {
                check = 1;
                q.push(childToParent[frontNode]);
                visited[childToParent[frontNode]] = 1;
            }
        }
        if (check == 1)
        {
            time += 1;
        }
    }
}
Node *findTarget(Node *root, int value, map<Node *, Node *> &ChildToParent)
{
    if (root == NULL)
        return NULL;

    Node *target = NULL;
    queue<Node *> q;
    q.push(root);

    ChildToParent[root] = NULL;
    while (!q.empty())
    {
        Node *fNode = q.front();
        q.pop();
        if (fNode->data == value)
        {
            target = fNode;
        }

        if (fNode->left)
        {
            q.push(fNode->left);
            ChildToParent[fNode->left] = fNode;
        }
        if (fNode->right)
        {
            q.push(fNode->right);
            ChildToParent[fNode->right] = fNode;
        }
    }
    return target;
}
int TimeToBurn(Node *root, int value)
{
    int time = 0;
    map<Node *, Node *> ChildToParent;
    Node *target = findTarget(root, value, ChildToParent);

    BurnTree(target, time, ChildToParent);

    return time;
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
    cout << "\n TimeToBurn  " << TimeToBurn(root, 4);
    return 0;
}