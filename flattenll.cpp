// here we are going to flatten a linked list
// which means now a node will have child too
// but when we flatten we need to keep the linked list sorted too
// lets code

#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *child = NULL;
    //  constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->child = NULL;
    }
};
Node *mergeTwolist(Node *&head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->child = head1;
            head1 = head1->child;
        }
        else
        {
            temp->child = head2;
            head2 = head2->child;
        }
        temp = temp->child;
    }
    while (head1 != NULL)
    {
        temp->child = head1;
        head1 = head1->child;
    }
    while (head2 != NULL)
    {
        temp->child = head2;
        head2 = head2->child;
    }
    Node *newhead = ans->child;
    delete ans;
    return newhead;
}
Node *flatten(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //    fatten the right part
    head->next = flatten(head->next);
    head = mergeTwolist(head, head->next);
    head->next=NULL;
    return head;
}
void insertAtchild(int d, Node *&parent)
{
    if (parent == NULL)
    {
        return;
    }
    Node *childnode = new Node(d);
    Node *runner = parent;
    while (runner->child != NULL)
    {
        runner = runner->child;
    }
    runner->child = childnode;
    runner = childnode;
}
void insertAtend(int d, Node *&head)
{
    //  create a node
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->child != NULL)
        {
            Node *temp1 = temp->child;
            cout << "its child are :";
            while (temp1 != NULL)
            {
                cout << temp1->data << " ";
                temp1 = temp1->child;
            }
            cout << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    cout << "lets flatten  the linked list  in two " << endl;
    Node *head = NULL;
    insertAtend(10, head);
    insertAtend(24, head);
    insertAtend(7, head);
    insertAtend(13, head);

    insertAtchild(2, head);
    insertAtchild(5, head);
    insertAtchild(3, head);

    insertAtchild(6, head->next);
    insertAtchild(8, head->next);

    insertAtchild(1, head->next->next);
    insertAtchild(3, head->next->next);

    cout << "before flattening  the linked list  " << endl;
    print(head);
    Node *newhead = flatten(head);
    cout << "after flattening  the linked list   " << endl;
    Node *temp = newhead;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
}