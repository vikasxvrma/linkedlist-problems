// here we are going to sort a linked list in order of 0s , 1s,2s
// when unordered sorted list of 0,1,2 is given
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
void insertAtnew(Node *curr, Node *&tail)
{
    tail->next=curr;
    tail=curr;
}
Node *sort_012(Node *&head)
{
    // another approach where we are making three linked list and joining them after
    // three linked list as of zero , one ,and two and for each node goes to specific linked list
    // at the end we will combine lets see can we do it or not
    // ofcourse we can do it
    // lets code
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *zero = new Node(-1);
    Node *zerotail = zero;
    Node *one = new Node(-1);
    Node *onetail = one;
    Node *two = new Node(-1);
    Node *twotail = two;
    Node *temp = head;
    // created 3 different sub linked list
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            insertAtnew(temp, zerotail);
        }
        else if (temp->data == 1)
        {
            insertAtnew(temp, onetail);
        }
        else if (temp->data == 2)
        {
            insertAtnew(temp, twotail);
        }
        temp = temp->next;
    }
    // lets try to merge all three different linked list
    if (one->next != NULL)
    {
        zerotail->next = one->next;
    }
    else
    {
        zerotail->next = two->next;
    }
    onetail->next = two->next;
    twotail->next = NULL;
    Node*newhead = zero->next;
    delete one;
    delete two;
    delete zero;
    return newhead;
}
// void sort_012(Node *&head)
// {
//     //  this is the first approach where we are sorting by first storing the elements count and replacing then in original sorted linked list
//     // lets see can we do it or not
//     //  i only use map data structure because that is what i have learned
//     map<int, int> count;
//     count[0] = 0;
//     count[1] = 0;
//     count[2] = 0;
//     if (head == NULL || head->next == NULL)
//     {
//         return;
//     }
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         count[temp->data]++;
//         temp = temp->next;
//     }
//     temp = head;
//     for (int j = 0; j <= 2; j++)
//     {
//         for (int i = 1; i <= count[j]; i++)
//         {
//             temp->data = j;
//             temp = temp->next;
//         }
//     }
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
    insertAtend(2, head);
    insertAtend(0, head);
    insertAtend(2, head);
    insertAtend(1, head);
    insertAtend(0, head);
    insertAtend(2, head);
    insertAtend(1, head);
    cout << "before sorting the linked list in 0s,1s,2s " << endl;
    print(head);
    Node *newhead = sort_012(head);
    cout << "after sorting the linked list   " << endl;
    print(newhead);
}