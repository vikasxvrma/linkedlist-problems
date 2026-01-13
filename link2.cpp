// starting doubly linked list
// making some changes to check git working 
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
int getlength(Node* &head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void deletelastnode(Node *&head)
{
    Node *temp = head;
    if(head==NULL)
    {
        cout<<"nothing to delete "<<endl;
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    // temp->next = NULL;
    delete temp;
}
void deletionfromposition(int index, Node *&head)
{
    if (index < 1)
    {
        cout << "invalid index cannot perform deletion" << endl;
        return;
    }
    if(head==NULL)
    {
        cout<<"linkedlist is empty"<<endl;
        return;
    }
    if (index == 1)
    {
        // case of deleting first node
        Node *temp = head;
        if(head->next==NULL)
        {
           delete head;
           head=NULL;
           return;
        }
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        // at any position including last
        Node *temp = head;
        for (int i = 1; i < index; i++)
        {
            if (temp == NULL )
            {
                cout << "index out of bound so,deleting last node" << endl;
                deletelastnode(head);
                return;
            }
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            temp->prev->next=NULL;
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
void insertathead(int d, Node *&head)
{
    Node *newnode = new Node(d);
    // when there is no element or creation of first node
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertatend(int d, Node *&head)
{
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
void insertatposition (int index,Node* &head,int d)
{
    Node* newnode=new Node(d);
    if(head==NULL)
    {
        if(index==1)
        {
            cout<<"linked list is empty inserting at head "<<endl;
            insertathead(d,head);
            return;
        }
        cout<<"linked list is empty ,so inserting at index =1"<<endl;
        insertathead(d,head);
        return;
    }
    if(index==1)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
    else{
        Node *temp= head;
        for(int i=1;i<index-1;i++)
        {
            if(temp==NULL ||temp->next==NULL)
            {
                cout<<"out of bound index so inserting at end "<<endl;
                insertatend(d,head);
                return;
            }
            temp=temp->next;
        }
       newnode->next=temp->next;
        if(temp->next!=NULL)
        {
            temp->next->prev=newnode;
        }
        newnode->prev=temp;
        temp->next=newnode;
        return;
    }
}
void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    cout << "learning execution of doubly linked list " << endl;
    Node *head = NULL;
    cout << "insertion in stack manner " << endl;
    insertathead(10, head);
    insertathead(20, head);
    insertathead(30, head);
    print(head);
    cout<<"the length of linked list is " << getlength(head)<<endl;
    cout << "deleting first three insertion " << endl;
    deletionfromposition(1, head);
    deletionfromposition(1, head);
    deletionfromposition(1, head);
    // print(head);
    cout << "insertion in queue manner " << endl;
    insertatend(40, head);
    insertatend(50, head);
    insertatend(60, head);
    insertatend(70, head);
    print(head);
    cout<<"inserting an element 55 at 3rd position "<<endl;
    insertatposition(3,head,55);
    print(head);
    cout<<"the length of linked list is " << getlength(head)<<endl;
}