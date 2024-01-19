#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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
    /// @brief
    /// @param vec
    /// @return
};
Node *arrToLL(vector<int> vec)
{
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
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeKth(Node *head, int k)
{
    // if LL is empty START
    if (head == NULL)
        return head;
    // if LL is empty END

    // when k = 1, remove head
    if (k == 1)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }

    int counter = 0;
    Node *temp = head;

    // while (counter < (k-1))
    // {
    //     counter++;
    //     temp = temp->next;
    // }
    // Node *prev = temp;
    // temp = temp->next;
    // prev->next = temp->next;
    // delete temp;
    // or can be used like this below
    Node *prev = temp;
    while (temp)
    {
        counter++;
        if (counter == k)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
Node *removeVal(Node *head, int val)
{
    // if LL is empty START
    if (head == NULL)
        return head;
    // if LL is empty END
    // when k = 1, remove head
    if (head->data == val)
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }

    // int counter = 0;
    Node *temp = head;
    Node *prev = temp;
    while (temp)
    {
        // counter++;
        if (temp->data == val)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *insertVal(Node *head, int val, int k)
{

    if (head = NULL)
    {
        if (k == 1)
            return new Node(val, head);
        else
            return head;
    }

    if (k == 1)
        return new Node(val, head);

    int counter = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        counter++;
        if (counter == (k - 1))
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;
            return head;
        }
        temp = temp->next;
    }
    return head;
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

    vector<int> vec = {25, 6, 3, 1, 4, 5};
    Node *head = arrToLL(vec);
    int k = 4;
    int val = 21;
    head = insertVal(head, val, k);
    printLL(head);
    return 0;
}