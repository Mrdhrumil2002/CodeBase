#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *arrToDLL(vector<int> vec)
{
    Node *head = new Node(vec[0]);

    Node *mov = head;

    for (int i = 1; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        temp->back = mov;
        mov->next = temp;
        mov = temp;
    }
    return head;
}

Node *deletionHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;
}
Node *deletionTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }

    Node *cur = prev->back;
    prev->back = nullptr;
    cur->next = nullptr;
    delete prev;

    return head;
}

Node *deletionKth(Node *head, int k)
{
    if (head == NULL)
        return head;

    int counter = 0;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        counter++;
        if (k == counter)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL && front == NULL)
        delete temp;
    else if (prev == NULL)
        return deletionHead(head);

    else if (front == NULL)
        return deletionTail(head);
    else
    {
        front->back = prev;
        prev->next = front;

        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }

    return head;
}

void deletionNode(Node *delNode)
{
    Node *temp = delNode;
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return;
}
void printDLL(Node *head)
{
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
    int k = 11;
    int val = 5;
    Node *head = arrToDLL(vec);

    Node *temp = head;
    int nodeNum = 11;
    while (--nodeNum)
    {
        temp = temp->next;
    }

    // head = deletionHead(head);
    // head = deletionTail(head);
    // head = deletionKth(head, k);
    deletionNode(temp);
    printDLL(head);

    return 0;
}