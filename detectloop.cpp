// this below code is to detect loop in linked list
// very east just traverse and stor each address as true in map type data structur
// lets code
#include <iostream>
#include <map>
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

Node *getStartNode(Node *&head, Node *intersection)
{
    Node *slow = head;
    // Node*fast=intersection;
    while (intersection != slow)
    {
        intersection = intersection->next;
        slow = slow->next;
    }
    return slow;
}
Node *floydDetectLoop(Node *head)
{
    // here we are using floyd loop detection algo
    // which does a great job by using two pointer approach fast and slow
    // fast takes two steps whereas slow just one
    // it the linked list is not circular then fast ans slow will never meet or fast ==null
    // it will meet in case of circular loop
    // lets code
    if ((head == NULL))
    {
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return fast;
        }
    }
    return NULL;
}
void removeloop(Node *&head, Node *&intersection, Node *&startnode)
{
    while (intersection->next != startnode)
    {
        intersection = intersection->next;
    }
    intersection->next = NULL;
}
bool detectLoop(Node *&head)
{
    map<Node *, bool> visited;
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "present at " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp=temp->next;
    }
    return false;
}
void insertatend(int d, Node *&head, Node *&tail)
{
    // this is queue insertion of new node

    // check if head is null then create head
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        tail->next = head;
        return;
    }
    // Node *temp = head;
    // below code is to traverse till the end
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = newnode;
    // tail = newnode;
    // no need to traverse we have tail pointer for that😎
    newnode->next = head;
    tail->next = newnode;
    tail = newnode;
    return;
}
void print(Node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty " << endl;
        return;
    }

    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}
int main()
{
    cout << "lets implement circular linked list " << endl;
    Node *head = NULL;
    Node *tail = NULL;
    insertatend(0, head, tail);
    insertatend(5, head, tail);
    insertatend(10, head, tail);
    insertatend(15, head, tail);
    print(head);
    Node *intersection = floydDetectLoop(head);

    if (detectLoop(head))
    {
        cout << "yes it has a circular loop list " << endl;
    }
    else
        cout << "No it does  not a circular  loop linked list " << endl;

    if (intersection != NULL)
    {
        cout << "yes it has a circular loop list " << endl;
    }
    else
        cout << "No it does  not a circular  loop linked list " << endl;
    Node *startnode = getStartNode(head, intersection);
    cout << "the starting of the circular node is " << startnode->data << endl;

    cout << "lets remove the circular loop by not linking startnode to loop it again" << endl;
    removeloop(head, intersection, startnode);
    cout << "is my code has worked or not " << endl;
    if (detectLoop(head))
    {
        cout << "yes it has a circular loop list " << endl;
    }
    else
        cout << "hurrayyy !!! it does  not contain  a circular  loop linked list " << endl;
}
