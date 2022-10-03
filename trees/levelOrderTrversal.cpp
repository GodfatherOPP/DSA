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
void displayLevelOrder(Node *root)
{

    if (root == NULL)
    {
        cout << "tree is empty \n";
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(Node *root, int k)
{

    if (root == NULL)
    {
        cout << "tree is empty \n";
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int Level = 0, sum = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (Level == k)
            {
                sum += node->data;
            }

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            Level++;
        }
    }
    return sum;
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

    displayLevelOrder(root);
    cout << "     " << sumAtK(root, 0) << " " << sumAtK(root, 1) << " " << sumAtK(root, 2);
    return 0;
}