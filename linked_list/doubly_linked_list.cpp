#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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
    newnode->prev = temp;
}
void insertAtHead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    head->prev = newnode;
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

int main()
{
    node *n = new node(10);
    insertAtTail(n, 20);
    insertAtTail(n, 30);
    insertAtTail(n, 40);
    insertAtTail(n, 50);
    insertAtTail(n, 60);
    insertAtTail(n, 70);
    insertAtHead(n, 80);
    display(n);

    // cout << n->data;

    return 0;
}