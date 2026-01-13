// lets reverse doubly linked list with both approach iterative as well as recursive
// lets code this is important
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
Node *reverserecur(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        return head;
    }
    Node *small_head = reverserecur(head->next);
    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;
    return small_head;
}
void reversell(Node *&head)
{
    // this is iterative approach
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        curr->prev = forward;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
void insertAtEnd(int d, Node *&head)
{
    // creation of new node
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
    newnode->prev = temp;
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
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    cout << "lets reverse doubly linked list " << endl;
    Node *head = NULL;
    insertAtEnd(10, head);
    insertAtEnd(20, head);
    insertAtEnd(30, head);
    insertAtEnd(40, head);
    insertAtEnd(50, head);
    cout << "before reversal of doubly linked list " << endl;
    print(head);
    reversell(head);
    cout << "after  reversal of doubly linked list using iterative approach  " << endl;
    print(head);
    head = reverserecur(head);
    cout << "after  reversal of doubly linked list using recursive approach  " << endl;
    print(head);
}