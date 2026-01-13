// this below code is to reverse a linked list using iterative approach
// lets code
// logic : we do nothing but traverse each node and establish a pointer to its previous node
// that will reverse the linked list
// lets do it
#include <iostream>
using namespace std;
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
Node* reverserecur1(Node*&head)
{
    // base case 
   if(head==NULL || head->next==NULL)
   {
    return head;
   }
   Node* smallhead=reverserecur1(head->next);
   head->next->next=head;
   head->next=NULL;
   return smallhead;

}
void reverserecur(Node *&head, Node *curr, Node *prev)
{
    // this is recursive way to solve or reverse the linked list
    // try to solve smaller problem
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    //  below is to solve smaller problem
    Node *forward = curr->next;
    curr->next = prev;
    reverserecur(head, forward, curr);
}
void reversell(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
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
    return;
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
    cout << "learning to reverse a linked list " << endl;
    Node *head = NULL;
    insertatend(10, head);
    insertatend(20, head);
    insertatend(30, head);
    insertatend(40, head);
    insertatend(50, head);
    cout << "before reversing the linked list " << endl;
    print(head);
    reversell(head);
    cout << "after reversing  the linked list " << endl;
    print(head);
    Node *curr = head;
    Node *prev = NULL;
    reverserecur(head, curr, prev);
    cout << "after reversing  the linked list using recursion " << endl;
    print(head);
    head=reverserecur1(head);
    cout << "after reversing  the linked list using recursion " << endl;
    print(head);
}