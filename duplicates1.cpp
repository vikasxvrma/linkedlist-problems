// here we are going to remove duplicates in unsorted linked list
// in this what i ll do is i ll store each node's data and compare it to rest if i found any other
// then i ll delete that node from linked list
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
// void removeDuplicates(Node *&head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return;
//     }
//     Node *temp = head;
//     while (temp!= NULL)
//     {
//         Node *runner = temp;
//         while (runner->next != NULL)
//         {
//             if (temp->data == runner->next->data)
//             {
//                 Node *toDelete = runner->next;
//                 runner->next = runner->next->next;
//                 delete toDelete;
//             }
//             else
//             {
//                 runner = runner->next;
//             }
//         }
//         temp = temp->next;
//     }
// }
// another version to remove Duplicates
void removeDuplicates(Node *&head)
{
    // we will use map to store those elements which are present and if another comes we
    // would delete them from linked list
    map<int, bool> visited;
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    visited[head->data] = true;
    Node *runner = head;
    while (runner->next != NULL)
    {
        if (visited[runner->next->data])
        {
            Node *toDelete = runner->next;
            runner->next = runner->next->next;
            delete toDelete;
        }
        else
        {
            visited[runner->next->data] = true;
            runner = runner->next;
        }
    }
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
    cout << "lets remove duplicates from linked list " << endl;
    Node *head = NULL;
    insertAtend(4, head);
    insertAtend(2, head);
    insertAtend(2, head);
    insertAtend(4, head);
    insertAtend(3, head);
    insertAtend(4, head);
    insertAtend(3, head);
    insertAtend(5, head);
    cout << "before removing duplicates linked list look like " << endl;
    print(head);
    removeDuplicates(head);
    cout << "after removing duplicates linked list look like " << endl;
    print(head);
}