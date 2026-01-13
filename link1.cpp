// from here we are going to learn another data structure which is my favourite linked list
// this is dynamic data structure efficient than array
// it is collection of nodes , what is node , it stores data part and address part (pointer ) , which p
// points to next part node so that the (this pointer is of node type only );
// only overhead of this data type is we need to traverse the whole linked list we can not jump
// because there is no indexing as of array data structure
// insertion and deletion is easy in linkedlist because we dont need to shift anything
// there are 4 types of linked list
// i) singly linked list (one data field &one pointer ) (so one way traversal )
// ii) doubly linked list (one data field &two  pointer ) (so two way traversal ) (one points prev and other next)
// iii)circular linked list (last node is pointing to first node )
// iv)circular-doubly linked list (last node is pointing to first node ) (two way traversal )

// lets code thats important
// just making some changes as to check or handle git 
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void deletefromstart(Node *&head)
{
    if (head == NULL)
    {
        cout << "linked list is already empty " << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
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
        tail = NULL;
        head = NULL;
        return;
    }
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
        deletefromstart(head);
        return;
    }
    // reach at desired index
    Node *temp = head;
    for (int i = 1; i < index-1; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            cout << "index is out of bound ,so deleting last node " << endl;
            deletefromend(head, tail);
            return;
        }
        temp = temp->next;
    }
    Node *runner = temp->next;
    if(runner==NULL)
    {
      cout<<"nothing to delete here !!"<<endl;
      return;
    }
    if(runner->next==NULL)
    {
        // to delete last element 
        deletefromend(head,tail);
        tail=temp;
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
        newhead->next = head;
        head = newhead;
        tail = newhead;
        return;
    }
    newhead->next = head;
    head = newhead;
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
        return;
    }
    Node *temp = head;
    // below code is to traverse till the end
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    tail = newnode;
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
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    cout << "starting learning linked list " << endl;
    Node *head = NULL;
    Node *tail = NULL;
    cout << "performing  stack insertion of 3 elements  " << endl;
    insertathead(10, head, tail);
    insertathead(20, head, tail);
    insertathead(30, head, tail);
    print(head);
    cout << endl;
    cout << "we have deleted from start  3 elements" << endl;
    deletefromstart(head);
    deletefromstart(head);
    deletefromstart(head);
    cout << "insertin in queue manner " << endl;
    insertatend(40, head, tail);
    insertatend(50, head, tail);
    insertatend(60, head, tail);
    insertatend(70, head, tail);
    insertatend(80, head, tail);
    print(head);
    cout << endl;
    cout << "inserting element 55 at position 4 " << endl;
    insertatposition(55, 4, head, tail);
    print(head);
    cout << endl;
    cout << "deleted from start " << endl;
    deletefromstart(head);
    print(head);
    cout << endl;
    cout << "deleted from end " << endl;
    deletefromend(head, tail);
    print(head);
    cout << endl;
    cout << "deleting 2nd node  " << endl;
    deletefromposition(head, 3, tail);
    print(head);
    cout << endl;
}