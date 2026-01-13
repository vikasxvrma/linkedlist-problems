// here we are learning cicular linked list where last node has address of first or head node
// lets code that is important
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
void disppointer(Node*&head,Node*&tail)
{
    cout<<"the head ="<<head->data <<endl;
    cout<<"the tail =" <<tail->data<<endl;
}
int getlength(Node *&head)
{
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void deletefromstart(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "linked list is already empty " << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    tail->next = head;
    temp->next = NULL;
    delete temp;
}
void deletefromend(Node *&head, Node *&tail)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "linked list is already empty " << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        tail->next = NULL;
        tail = NULL;
        head = NULL;
        return;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    tail->next = NULL;
    delete tail;
    tail = temp;
}
void deletefromposition(Node *&head, int index, Node *&tail)
{
    if (index < 1)
    {
        cout << "cannot perform deletion invalid index" << endl;
        return;
    }
    if (index == 1)
    {
        deletefromstart(head, tail);
        return;
    }
    if (index > getlength(head))
    {
        cout << "index out of bound " << endl;
        cout << "you may delete wrong element " << endl;
        return;
    }
    // reach at desired index
    Node *temp = head;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node *runner = temp->next;
    if (runner->next == head)
    {
        // to delete last element
        deletefromend(head, tail);
        return;
    }
    // when we have to delete in between
    temp->next = runner->next;
    runner->next = NULL;
    delete runner;
}
void insertathead(int d, Node *&head, Node *&tail)
{
    // this is stack insertion of new node
    Node *newhead = new Node(d);
    if (head == NULL)
    {
        head = newhead;
        tail = newhead;
        tail->next = head;
        return;
    }
    newhead->next = head;
    head = newhead;
    tail->next = head;
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
void insertatposition(int d, int index, Node *&head, Node *&tail)
{
    // create new node first
    Node *newnode = new Node(d);
    // insert at desire position
    // first reach the desired position
    if (index <= 1)
    {
        insertathead(d, head, tail);
        return;
    }
    Node *temp = head;
    for (int i = 1; i < index - 1; i++)
    {
        // if it goes out of bound
        if (temp == NULL || temp->next == NULL)
        {
            cout << "index is out of bound  ,so inserting at end " << endl;
            insertatend(d, head, tail);
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
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
    insertathead(10, head, tail);
    insertathead(20, head, tail);
    insertathead(30, head, tail);
    print(head);
    disppointer(head,tail);
    cout << "inserting 0 at the end of linked list as a queue " << endl;
    insertatend(0, head, tail);
    print(head);
    disppointer(head,tail);
    cout << "inserting 15 at 3rd position of the linked list " << endl;
    insertatposition(15, 3, head, tail);
    print(head);
    disppointer(head,tail);
    cout<<"deleting 2nd element from the list"<<endl;
    deletefromposition(head,2,tail);
    print(head);
    disppointer(head,tail);
}