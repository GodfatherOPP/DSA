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

int calcHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}

int calcDiameter(Node *root)
{
    // time complexity is O(n^2)
    if (root == NULL)
    {
        return 0;
    }
    int currDiameter = (calcHeight(root->left) + calcHeight(root->right) + 1);
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    return max(currDiameter, max(lDiameter, rDiameter));
}

int Diameter(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = Diameter(root->left, &lh);
    int rDiameter = Diameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDiameter, max(lDiameter, rDiameter));
}

int main()
{

    struct Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    // root->left->left->left = new Node(2);

    root->right->left = new Node(6);
    root->right->right = new Node(8);
    cout << "height = " << calcHeight(root) << "\n";
    cout << "Diameter = " << calcDiameter(root) << "\n";
    int Height = 0;
    cout << "Diameter 2 = " << Diameter(root, &Height);
    return 0;
}