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
void solve(Node *root, int k, int &count, vector<int> v)
{

    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    solve(root->left, k, count, v);
    solve(root->right, k, count, v);
    int size = v.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += v[i];
        if (sum == k)
        {
            count++;
        }
    }
}
int KsumPath(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
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
    cout << "\n No. of paths with sum 10 :  " << KsumPath(root, 10);
    return 0;
}