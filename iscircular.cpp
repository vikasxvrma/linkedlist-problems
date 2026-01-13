#include <iostream>
using namespace std;
// Node creation
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
bool isCircular(Node *head)
{

    if(head==NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void insertatend(int d, Node *&head, Node *&tail)
{
    // this is queue insertion of new node

    // check if head is null then create head
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = head;
        return;
    }
    // Node *temp = head;
    // below code is to traverse till the end
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = newnode;
    // tail = newnode;
    // no need to traverse we have tail pointer for that😎
    newnode->next = head;
    tail->next = newnode;
    tail = newnode;
    return;
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty " << endl;
        return;
    }

    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
int main()
{
    cout << "lets implement circular linked list " << endl;
    Node *head = NULL;
    Node *tail = NULL;
    insertatend(0, head, tail);
    insertatend(5, head, tail);
    insertatend(10, head, tail);
    insertatend(15, head, tail);
    print(head);
    if (isCircular(head))
    {
        cout << "yes it is a circular linked list " << endl;
    }
    else
        cout << "No it is not a circular linked list " << endl;
}
