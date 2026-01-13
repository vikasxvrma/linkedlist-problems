// here we are going to check whether a linked list is palindrome or not
// i ll use the same approach as of array like using two pointer from either end
// lets see can i or not
// lets code
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
    //  constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
Node*getreverse(Node*&head)
{
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=NULL;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool ispalindrome(Node*head)
{
    // this is another approach where we will traverse half linkedlist using slow and fast 
    // then we will reverse other half in place and compare halves 
    // lets try and lets code 
    if(head==NULL|| head->next==NULL)
    {
        return true;
    }
    Node*fast=head;
    Node*slow=head;
    while(fast!=NULL&& fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    // slow is at mid 
    // lets reverse the other half 
    Node*middle=slow;
    middle->next=getreverse(slow->next);
    // lets do comparison
    Node*temp=head;
    Node*temp1=middle->next;
    bool ispal=true;
    while(temp!=NULL&&temp1!=NULL)
    {
        if(temp->data!=temp1->data)
        {
            ispal=false;
            break;
        }
        else{
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    getreverse(middle->next);
    return ispal;
}
// void insertAthead(int d, Node *&head)
// {
//     Node *newnode = new Node(d);
//     if (head == NULL)
//     {
//         head = newnode;
//         return;
//     }
//     newnode->next = head;
//     head = newnode;
// }
// bool ispalindrome(Node *&head)
// {
//     //    we cannot traverse back like array because it is singly linked list
//     // so i am storing these nodes in different linked list in rversse order
//     // lets cook
//     if (head == NULL || head->next == NULL)
//     {
//         return true;
//     }
//     Node *temp = head;
//     Node *toCompare = NULL;
//     while (temp != NULL)
//     {
//         insertAthead(temp->data, toCompare);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp != NULL)
//     {
//         if (toCompare->data != temp->data)
//         {
//             return false;
//         }
//         else
//         {
//             temp = temp->next;
//             toCompare = toCompare->next;
//         }
//     }
//     return true;
// }
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
    cout << "lets split the linked list  in two " << endl;
    Node *head = NULL;
    insertAtend(1, head);
    insertAtend(0, head);
    insertAtend(2, head);
    insertAtend(7, head);
    insertAtend(7, head);
    insertAtend(7, head);
    insertAtend(2, head);
    insertAtend(0, head);
    insertAtend(1, head);
    cout << "this is the linked list  " << endl;
    print(head);
    if (ispalindrome(head))
    {
        cout << "and it is a palindrome    " << endl;
    }
    else
    {
        cout << "and it is not a palindrome " << endl;
    }
}