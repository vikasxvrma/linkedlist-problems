// here we are going to split the linked list into two parts
// i will use fast and slow pointers , as fast pointer will approach the end of linked list
// slow will be at half of linked list
// lets see it works or not
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
Node *splitTwo(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *secondHalfhead = slow->next;
    slow->next = NULL;
    return secondHalfhead;
}
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
    insertAtend(4, head);
    insertAtend(2, head);
    insertAtend(2, head);
    insertAtend(4, head);
    insertAtend(3, head);
    insertAtend(4, head);
    insertAtend(3, head);
    insertAtend(5, head);
    cout << "before splitting the linked list into two parts " << endl;
    print(head);
    Node *newhead = splitTwo(head);
    cout << "the first half of the linked list  " << endl;
    print(head);
    cout << "the other half of the linked list " << endl;
    print(newhead);
}