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
int maxPathSumUtil(Node *root, int &ans)
{

    if (root == NULL)
        return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));

    ans = max(nodeMax, ans);
    return max(root->data, max(root->data + left, root->data + right));
}

int maxPathSum(Node *root)
{
    int ans = INT32_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}
int main()
{

    /*
              -50
           3       7
         2   4   6   8

    */

    struct Node *root = new Node(-50);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout << "Max path Sum is  :  " << maxPathSum(root);
    return 0;
}