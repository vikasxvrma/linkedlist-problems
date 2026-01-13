// here we are going to clone a linked list which is not normal but a special linked list 
// because it has two pointers called next and random 
// we have two approaches 
// 1. create a new linked list using next pointer then trace random for each node and then again in clone list 
// locate the random and create it it will lead to O(n2)
// 2. we have second approach which says first create a clone list using next pointer then it says 
// we will use mapping which will store originalnode->random and clonenode->random so the time complexity will be O(1);
// lets code and try 
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node*random=NULL;
    //  constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random=NULL;
        
    }
};
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
Node* clonelist(Node*head)
{
    Node*clonehead=NULL;
    if(head==NULL)
    {
      return clonehead;
    }
    // we have copied atleast at clone list which has next pointers till now 
    Node*temp=head;
    while(temp!=NULL)
    {
        insertAtend(temp->data,clonehead);
        temp=temp->next;
    }
    // lets do mapping 
    map<Node*,Node*> oldTonew;
    temp=head;
    Node*temp1=clonehead;
    while(temp!=NULL&&temp1!=NULL)
    {
        oldTonew[temp]=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }
    // now lets do mapping of random pointer 
    temp=head;
    temp1=clonehead;
    while(temp!=NULL && temp1!=NULL)
    {
    temp1->random= oldTonew[temp->random];
    temp=temp->next;
    temp1=temp1->next;
    }
    return clonehead;
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
        cout << temp->data << " " ;
        cout<< "random ->data " << temp->random->data <<endl;
        cout<<endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    cout << "lets clone  the linked list   " << endl;
    Node *head = NULL;
    insertAtend(1, head);
    insertAtend(2, head);
    insertAtend(3, head);
    insertAtend(4, head);
    insertAtend(5, head);
    // lets assign random data to each nodes as given in question of gfg 
    head->random=head->next->next;
    head->next->random=head;
    head->next->next->random=head->next->next->next->next;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next;
    cout << "the original linked list  " << endl;
    print(head);
    Node*clonehead=clonelist(head);
    cout << "this is the cloned list    " << endl;
    print(clonehead);
}