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
Node *reverseGrp(Node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    for (int i = 1; i < k; i++)
    {
        if (temp == NULL)
        {
            return head;
        }
        temp=temp->next;
    }
    int count = 0;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = reverseGrp(forward, k);
    }
    return prev;
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
    int k;
    cout << "enter size of group as to reverse " << endl;
    cin >> k;
    head= reverseGrp(head, k);
    cout << "after reversing the linked list in " << k << " groups " << endl;
    print(head);
}