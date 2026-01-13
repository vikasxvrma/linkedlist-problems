// lets find the middle node of linked list using pro and noob
// which reduces time complexity really ??
// lets code this is important
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
Node* middleLL(Node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node*pro =head;
    Node*noob=head;
    while(pro!=NULL&& pro->next!=NULL)
    {
        pro=pro->next->next;
        noob=noob->next;
    }
    return noob;
}
void insertAtEnd(int d, Node *&head)
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
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
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
    cout << "lets find the middle of the linked list " << endl;
    Node *head = NULL;
    insertAtEnd(10, head);
    insertAtEnd(17, head);
    // insertAtEnd(23, head);
    // insertAtEnd(45, head);
    // insertAtEnd(67, head);
    // insertAtEnd(78, head);
    cout << "the linked list is " << endl;
    print(head);
    Node *middle = middleLL(head);
    cout << "the middle of the linked list is " << endl;
    cout << middle->data << endl;
}