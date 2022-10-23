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

void solve(Node *root, int &maxSum, int &maxLength, int sum, int len)
{
    if (root == NULL)
    {
        if (len > maxLength)
        {
            maxLength = len - 1;
            maxSum = sum;
        }
        else if (len == maxLength)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum += root->data;
    cout << "\n"
         << maxSum << " " << maxLength << " " << sum << " " << len;

    solve(root->left, maxSum, maxLength, sum, len + 1);
    solve(root->right, maxSum, maxLength, sum, len + 1);
}
int sumOfLongestBloodline(Node *root)
{

    int maxSum = 0, maxLength = 0, sum = 0, len = 0;
    solve(root, maxSum, maxLength, sum, len);
    return maxSum;
}

int main()
{

    /*
               5
           3       7
         2   4   6   4

    */

    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(4);
    cout << "\n Max Sum of Longest BLoodline:  " << sumOfLongestBloodline(root);
    return 0;
}