// starting  cicular doubly linked list
#include <iostream>
using namespace std;
// creation of node as class
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
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
void deletelement(Node *&head, Node *&tail, int element)
{
    // in order to delete the specific element
    if (head == NULL)
    {
        cout << "cant delete as linked list is empty " << endl;
        return;
    }
    // we assume element is present
    Node *temp = head;
    bool found = false;
    do
    {
        if (temp->data == element)
        {
           found=true;
           break;
        }
        temp=temp->next;

    }while (temp != head);
    if(!found)
    {
        cout<<"element not found ,so you cant delete "<<endl;
        return;
    }
    if(temp==head&& head==tail)
    {
        // only one element 
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if (temp == head)
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        delete temp;
        return;
    }
    if(temp==tail)
    {
        tail=temp->prev;
        head->prev=tail;
        tail->next=head;
        delete temp;
        return;
    }
    // in case of in between elements
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return;
}
void deletelastnode(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "nothing to delete " << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
}
void deletionfromposition(int index, Node *&head, Node *&tail)
{
    if (index < 1)
    {
        cout << "invalid index cannot perform deletion" << endl;
        return;
    }
    if (head == NULL)
    {
        cout << "linkedlist is empty" << endl;
        return;
    }
    if (index == 1)
    {
        // case of deleting first node
        Node *temp = head;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        head = head->next;
        tail->next = head;
        head->prev = tail;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        // at any position including last
        Node *temp = head;
        if (index > getlength(head))
        {
            cout << "cannot delete out of bound" << endl;
            return;
        }
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            // deletion of last node
            tail = temp->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}
void insertathead(int d, Node *&head, Node *&tail)
{
    Node *newnode = new Node(d);
    // when there is no element or creation of first node
    if (head == NULL)
    {// last element or tail
        head = newnode;
        head->prev = tail;
        tail = newnode;
        tail->next = head;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    head->prev = tail;
    tail->next = head;
    return;
}
void insertatend(int d, Node *&head, Node *&tail)
{
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        head->prev = tail;
        tail->next = head;
        return;
    }
    // Node *temp = head;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = newnode;
    // newnode->prev = temp;
    // no need to traverse
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    return;
}
void insertatposition(int index, Node *&head, Node *&tail, int d)
{
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        if (index == 1)
        {
            cout << "linked list is empty inserting at head " << endl;
            insertathead(d, head, tail);
            return;
        }
        cout << "linked list is empty ,so inserting at index =1" << endl;
        insertathead(d, head, tail);
        return;
    }
    if (index == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        tail->next = head;
        head->prev = tail;
        return;
    }
    else
    {
        Node *temp = head;
        if (index > getlength(head) + 1)
        {
            cout << "invalid index,keep it under length of linked list" << endl;
            return;
        }
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        if (temp->next == head)
        {
            // insertion at end
            insertatend(d, head, tail);
            return;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
        return;
    }
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
    cout << "learning execution of doubly linked list " << endl;
    Node *head = NULL;
    Node *tail = NULL;
    cout << "insertion in stack manner " << endl;
    insertathead(10, head, tail);
    insertathead(30, head, tail);
    insertathead(20, head, tail);
    print(head);
    cout << "the length of linked list is " << getlength(head) << endl;
    cout << "deleting first three insertion " << endl;
    deletionfromposition(1, head, tail);
    deletionfromposition(1, head, tail);
    deletionfromposition(1, head, tail);
    // print(head);
    cout << "insertion in queue manner " << endl;
    insertatend(40, head, tail);
    insertatend(50, head, tail);
    insertatend(60, head, tail);
    insertatend(70, head, tail);
    print(head);
    cout << "inserting an element 55 at 3rd position " << endl;
    insertatposition(3, head, tail, 55);
    print(head);
    cout << "the length of linked list is " << getlength(head) << endl;
    cout<<"deleting element 60 from the list "<<endl;
    deletelement(head,tail,60);
    print(head);
}