#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
        // cout << "new node created";
    }
};
void insertAtTail(node *head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertAtHead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
}
void display(node *head)
{
    if (head == NULL)
    {
        cout << "empty linked list";
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data;
}

node merge(node a, node b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    if (a.data < b.data)
    {
        a.next = merge(a.next, b);

        return a;
    }
    else
    {

        b.next = merge(a.next, b);
        return b;
    }
}

node getmid(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node mergeSort(node *head)
{

    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    node mid = getmid(head);
    node *right = mid->next;
    mid->next = NULL;

    node *left = head;

    node l1 = mergeSort(left);
    node l2 = mergeSort(right);

    return merge(l1, l2);
}

int main()
{
    node *n = new node(5);

    insertAtTail(n, 7);
    insertAtHead(n, 4);
    insertAtTail(n, 8);
    insertAtTail(n, 6);
    display(n);

    cout << endl
         << mergeSort(n) << endl;

    return 0;
}