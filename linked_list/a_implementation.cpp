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
void search(node *head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "\nvalue " << val << " found in linked list ";
            return;
        }
        temp = temp->next;
    }
    cout << "\nvalue " << val << " not found in linked list ";
}
int main()
{
    node *n = new node(5);
    insertAtTail(n, 6);
    insertAtTail(n, 7);
    insertAtTail(n, 8);
    insertAtHead(n, 4);
    display(n);
    search(n, 19);

    search(n, 7);
    // cout << n->next->data;

    return 0;
}