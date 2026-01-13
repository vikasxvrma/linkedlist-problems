// here we are going to merge two sorted linked list
// i am thinking of approach as same as array two sorted
// we will take two pointer on different sorted linked list and
// and merge them together by checking lets try that is what we can do
// lets code
#include <iostream>
#include <map>
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
Node *solve(Node *&head1, Node *&head2)
{
    Node *curr1 = head1;
    Node *next1 = curr1->next;
    Node *curr2 = head2;
    Node *next2 = NULL;
    while(next1!=NULL&&curr2!=NULL)
    {
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data))
        {
           curr1->next=curr2;
           next2=curr2->next;
           curr2->next=next1;
           curr2=next2;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
            }
        }
    }
    return head1;
}
Node *mergeTwoSorted(Node *&head1, Node *&head2)
{
    // this is another approach where we insert another list element in first list using window approach lets see
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *newhead = NULL;
    if (head1->data <= head2->data)
    {
        newhead = solve(head1, head2);
    }
    else
    {
        newhead = solve(head2, head1);
    }
    return newhead;
}
// Node *mergeTwoSorted(Node *&head1, Node *&head2)
// {
//    if(head1==NULL)
//    return head2;
//    if(head2==NULL)
//    return head1;
//    Node*mergehead=NULL;
//    Node*mergetail=NULL;
//    if(head1->data<=head2->data)
//    {
//     mergehead=head1;
//     head1=head1->next;
//    }
//    else{
//     mergehead=head2;
//     head2=head2->next;
//    }
//    mergetail=mergehead;

//    while(head1!=NULL&& head2!=NULL)
//    {
//     if(head1->data<=head2->data)
//     {
//         mergetail->next=head1;
//         mergetail=head1;
//         head1=head1->next;
//     }
//     else{
//         mergetail->next=head2;
//         mergetail=head2;
//         head2=head2->next;

//     }
//    }
//    while(head1!=NULL)
//    {
//     mergetail->next=head1;
//     mergetail=head1;
//     head1=head1->next;
//    }
//    while(head2!=NULL)
//    {
//     mergetail->next=head2;
//     mergetail=head2;
//     head2=head2->next;
//    }
//     return mergehead;
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
    cout << "lets merge two sorted linked list " << endl;
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtend(10, head1);
    insertAtend(15, head1);
    insertAtend(20, head1);
    insertAtend(40, head1);
    insertAtend(13, head2);
    insertAtend(17, head2);
    insertAtend(29, head2);
    insertAtend(51, head2);
    cout << "before merging the two sorted linked list  " << endl;
    print(head1);
    cout << "the other linked list is " << endl;
    print(head2);
    Node *newhead = mergeTwoSorted(head1, head2);
    cout << "after merging both sorted linked list  " << endl;
    print(newhead);
}