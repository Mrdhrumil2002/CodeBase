#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *arrToLL(vector<int> vec)
{
    if (vec.empty())
        return NULL;

    Node *head = new Node(vec[0]);
    Node *move = head;
    for (int i = 1; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}
Node *oddevenLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
 
    odd->next = evenHead;
    return head;
}

void printLL(Node *head)
{
    if (head == NULL)
        cout << "NULL";

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    // START  input.txt and output.txt syntax
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // END  input.txt and output.txt syntax

    vector<int> vec = {25, 6, 3, 1, 4, 8, 6, 5, 1, 2, 3, 85, 6, 21, 5};

    Node *head = arrToLL(vec);
    head = oddevenLL(head);
    printLL(head);

    return 0;
}