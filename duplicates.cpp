// here we are going to remove duplicates in sorted linked list 
// lets traverse the linked list and if next node's data part is same as current delete next 
// lets code
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next=NULL;
    //  constructor 
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
void removeDuplicates(Node*&head)
{
   if(head==NULL || head->next==NULL)
   {
    return ;
   }
   Node*temp=head;
   while(temp->next!=NULL)
   {
    if(temp->data==temp->next->data)
    {
        Node*toDelete=temp->next;
        temp->next=temp->next->next;
        delete toDelete;
    }
    else{
        temp=temp->next;
    }
   }
   return;
}
void insertAtend(int d,Node*&head)
{
    //  create a node 
    Node*newnode=new Node(d);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void print(Node *head)
{
    if(head==NULL)
    {
        cout<<"linked list is empty "<<endl;
        return;
    }
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data << " ";
        temp=temp->next;
    }
    cout<<endl;

}
int main()
{
    cout<<"lets remove duplicates from linked list "<<endl;
    Node*head=NULL;
    insertAtend(1,head);
    insertAtend(1,head);
    insertAtend(2,head);
    insertAtend(2,head);
    insertAtend(4,head);
    insertAtend(4,head);
    insertAtend(5,head);
    insertAtend(5,head);
    cout<<"before removing duplicates linked list look like " <<endl;
    print(head);
    removeDuplicates(head);
    cout<<"after removing duplicates linked list look like " <<endl;
    print(head);
    
}