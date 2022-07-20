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
void deleteAtHead(node *&head, int val)
{
    if (head == NULL)
        return;
    //    node* temp =head;
    if (head->data == val)
    {
        node *nodetodelete = head;
        head = head->next;
        delete nodetodelete;
        return;
    }
    return;
}
void deletion(node *&head, int val)
{
    if (head == NULL || head->next == NULL)
    {
        deleteAtHead(head, val);
        return;
    }
    node *temp = head;

    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "\nno such data found " << endl;
        return;
    }
    node *nodetodelete = temp->next;
    temp->next = temp->next->next;

    delete nodetodelete;
}
void reverse(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *prevptr = NULL;
    node *currentptr = head;
    node *nextptr;

    while (currentptr != NULL)
    {
        nextptr = currentptr->next;
        currentptr->next = prevptr;

        prevptr = currentptr;
        currentptr = nextptr;
    }
    head = prevptr;
}
// using flyod's algorithm or hare and tortoise algorithm
void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *start = NULL; // position from where cycle is starting
    int count = 1;
    do
    {
        if (pos == count)
        {
            start = temp;
        }
        temp = temp->next;
        count++;
    } while (temp->next != NULL);

    temp->next = start;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void deleteCycle(node *&head)
{

    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            break;
        }
    }
    fast = head;
    while (fast->next == slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}
int main()
{
    node *n = new node(5);

    insertAtTail(n, 6);
    insertAtTail(n, 7);
    insertAtTail(n, 8);
    insertAtHead(n, 4);

    // display(n);
    // search(n, 19);
    // search(n, 7);
    // reverse(n);
    // cout << endl;

    // deletion(n, 5);
    // display(n);
    // node *newhead = deleteAtHead(n, 5);
    // display(newhead);
    // cout << endl;

    // cout << detectCycle(n) << endl;
    // makeCycle(n, 3);
    // cout << detectCycle(n) << endl;
    // deleteCycle(n);
    // cout << detectCycle(n) << endl;
    // display(n);

    return 0;
}