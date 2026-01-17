// here we are going to add two numbers represented by linked list
// my approach is traverse a linked list and store it in form of a no for both the list
// then add
// lets see it works or not
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
void insertAtend(int d, Node *&head)
{
    //  create a node
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    // making changes as to learn git 
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
Node *getreverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node *sumTwo(Node *head1, Node *head2)
{
    Node *resulthead = NULL;
    int sum = 0;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        sum = carry + head1->data + head2->data;
        carry = sum / 10;
        insertAtend(sum % 10, resulthead);
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != NULL)
    {
        sum = carry + head1->data;
        carry = sum / 10;
        insertAtend(sum % 10, resulthead);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        sum = carry + head2->data;
        carry = sum / 10;
        insertAtend(sum % 10, resulthead);
        head2 = head2->next;
    }
    while(carry!=0)
    {
        sum=carry;
        carry=sum/10;
        insertAtend(sum%10,resulthead);
    }
    return resulthead;
}
Node *addTwo(Node *&head1, Node *&head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return head1;
    }
    // step1 reverse both linked list so that we can add from last 
    Node *temp1 = getreverse(head1);
    Node *temp2 = getreverse(head2);
    //   now add both reversed linked list by function sumTwo 
    Node *resulthead = sumTwo(temp1, temp2);
    // step 3 reverse the final result linked list 
    Node *finalhead = getreverse(resulthead);
    return finalhead;
}
// this below code is gareeb approach
// int getnumber(Node*&head)
// {
//     if(head==NULL)
//     {
//         return 0;
//     }
//     if(head->next==NULL)
//     {
//         return head->data;
//     }
//     int no=0;
//     Node*temp=head;
//     while(temp!=NULL)
//     {
//         no=no*10+temp->data;
//         temp=temp->next;
//     }
//     return no;
// }
// int addTwo(Node*&head1,Node*&head2)
// {
//     if(head1==NULL&& head2==NULL)
//     {
//         return 0;
//     }
//     int n1=getnumber(head1);
//     int n2=getnumber(head2);
//     return n1+n2;

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
    cout << "lets merge two sorted linked list " << endl;
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtend(1, head1);
    insertAtend(0, head1);
    insertAtend(2, head1);
    insertAtend(1, head1);
    insertAtend(9, head2);
    insertAtend(9, head2);
    insertAtend(9, head2);
    insertAtend(9, head2);
    cout << "before adding  the two no as  linked list  " << endl;
    print(head1);
    cout << "the other linked list is " << endl;
    print(head2);
    Node *resulthead = addTwo(head1, head2);
    cout << "the result is  " << endl;
    print(resulthead);
}