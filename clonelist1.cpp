// here we are going to clone a linked list which is not normal but a special linked list
// because it has two pointers called next and random
// we have two approaches
// 1. create a new linked list using next pointer then trace random (distance from node to random )for each node and then again in clone list
// locate the random and create it it will lead to O(n2)
// 2. we have second approach which says first create a clone list using next pointer then it says
// we will use mapping which will store originalnode->random and clonenode->random so the time complexity will be O(n);
// this is another approach which space wise optimised like in this case we will not use mapping but we will do
// real time tracing the random not storing in mapping so that it gives O(1) space complexity
// lets code and try
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    Node *random = NULL;
    //  constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
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
Node *clonelist(Node *head)
{
    Node *clonehead = NULL;
    if (head == NULL)
    {
        return clonehead;
    }
    // step1  we have copied clone list which has next pointers till now
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     insertAtend(temp->data, clonehead);
    //     temp = temp->next;
    // }
    // //    step 2 now we will add clonelist nodes in between original list so that we can access random
    //  lets try not to create separate list and create a node while joining them in original list
    // lets see

    Node *temp = head;
    Node *next = NULL;
    while (temp != NULL)
    {
        Node *clone = new Node(temp->data);
        next = temp->next;
        temp->next = clone;
        clone->next = next;
        temp = next;
    }
    clonehead = head->next;

    // temp=head;
    // Node*temp1=clonehead;
    // Node*next1=NULL;
    // Node*next2=NULL;
    // while(temp1!=NULL)
    // {
    //     next1=temp->next;
    //     temp->next=temp1;
    //     next2=temp1->next;
    //     temp1->next=next1;
    //     temp=next1;
    //     temp1=next2;
    // }
    // temp=head;

    // step 3 lets assign the random pointers to clone list
    temp=head;
    Node*temp1=clonehead;
    Node*next1=NULL;
    Node*next2=NULL;
    while (temp != NULL)
    {
        if(temp->next!=NULL)
        {
            if(temp->random!=NULL)
            {
              temp->next->random = temp->random->next;
            }
            else{
                temp->next->random=temp->random;
            }
        }
        temp = temp->next->next;
    }
    // revert back to original or you can say differentiate original linked list and clone linked list
    temp = head;
    temp1 = clonehead;
    next1 = NULL;
    next2 = NULL;
    while (temp1 != NULL)
    {
        next1 = temp->next->next;
        temp->next = next1;
        next2 = temp1->next;
        temp1->next = next2;
        temp = next1;
        temp1 = next2;
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
        cout << temp->data << " ";
        cout << "random ->data " << temp->random->data << endl;
        cout << endl;
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
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
    cout << "the original linked list  " << endl;
    print(head);
    Node *clonehead = clonelist(head);
    cout << "this is the cloned list    " << endl;
    print(clonehead);
}