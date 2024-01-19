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

Node *arrToDLL(vector<int> vec)
{
    Node *head = new Node(vec[0]);

    Node *mov = head;

    for (int i = 1; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        // temp->back = mov;
        mov->next = temp;
        mov = temp;
    }
    return head;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        Node *dummy = temp->next;
        temp->next = prev;
        prev = temp;
        temp = dummy;
    }
    return prev;
}
Node *reverseRecursion(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseRecursion(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

void printLL(Node *head)
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
    int k = 2;
    //    25, 6, 3, 1,  4, 8, 6, 5, 1, 2, 3,85, 6,21, 5};
    vector<int> vec = {25, 6, 3, 1, 4, 8, 6, 5, 1, 2, 3, 85, 6, 21, 5};
    Node *head = arrToDLL(vec);
    // head = reverseLL(head);
    head = reverseRecursion(head);
    printLL(head);

    return 0;
}