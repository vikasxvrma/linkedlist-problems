// here we going to perform merger sort  on a linked list
// kind of approach is similar to merger sort on arrays
// we are using recursive approach lets see
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
Node *merge(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    // dummy node
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    while (head1 != NULL)
    {
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
    while (head2 != NULL)
    {
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    Node *newhead = ans->next;
    return newhead;
}
Node *mergeSort(Node *&head)
{
    //    base case
    if (head->next == NULL)
    {
        return head;
    }
    Node *fast = head->next;
    Node *slow = head;
    // code to find middle
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *middle = slow;
    Node *otherhead = middle->next;
    middle->next = NULL;
    Node *head1 = mergeSort(head);
    Node *head2 = mergeSort(otherhead);
    // in order to merge sorted parts
    Node *newhead = merge(head1, head2);
    return newhead;
}
void insertAtend(int d, Node *&head, Node *&tail)
{
    //  create a node
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
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
    Node *tail = NULL;
    insertAtend(10, head, tail);
    insertAtend(21, head, tail);
    insertAtend(13, head, tail);
    insertAtend(27, head, tail);
    insertAtend(15, head, tail);
    insertAtend(7, head, tail);
    insertAtend(23, head, tail);
    insertAtend(11, head, tail);
    cout << "before sorting the linked list  " << endl;
    print(head);
    Node *newhead = mergeSort(head);
    cout << "after sorting the linked list   " << endl;
    print(newhead);
}