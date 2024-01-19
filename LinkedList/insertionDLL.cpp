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

Node *insertionHead(Node *head, Node *insertNode)
{
    if (head == NULL)
        return head;
    insertNode->next = head;
    insertNode->back = nullptr;
    head->back = insertNode;
    insertNode = head;

    return head;
}
Node *insertionHead(Node *head, int val)
{
    if (head == NULL)
        return head;
    Node *insertNode = new Node(val, head, nullptr);
    head->back = insertNode;

    // head = insertNode;
    // return head;
    // or

    return insertNode;
}
Node *insertionTail(Node *head, int val)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    while (temp->next != NULL)
    {

        temp = temp->next;
    }
    Node *insertNode = new Node(val, nullptr, temp);
    temp->next = insertNode;

    return head;
}
Node *insertionKth(Node *head, int k, int val)
{
    if (head == NULL)
        return head;

    if (k == 1)
        return insertionHead(head, val);
    Node *temp = head;
    int counter = 0;
    while (temp->next != NULL)
    {
        counter++;
        if (k == counter)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;

    Node *insertNode = new Node(val, temp, prev);
    prev->next = insertNode;
    temp->back = insertNode;

    return head;
}
void insertionValAfterNode(Node *cur, int val)
{
    Node *after = cur->next;
    Node *insertNode = new Node(val, after, cur);

    cur->next = insertNode;
    after->back = insertNode;
}
void insertionValBeforeNode(Node *cur, int val)
{
    Node *prev = cur->back;
    Node *insertNode = new Node(val, cur, prev);

    prev->next = insertNode;
    cur->back = insertNode;
}

void insertionValbeforeVal(Node *head, int val1, int val)
{
    Node *temp = head;

    while (temp->data != val1)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;

    Node *insertNode = new Node(val, temp, prev);
    prev->next = insertNode;
    temp->back = insertNode;
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
    int val = -160;
    int val1 = 85;
    Node *head = arrToDLL(vec);

    Node *temp = head;
    int nodeNum = 10;
    while (--nodeNum)
    {
        temp = temp->next;
    }

    // head = insertionHead(head, val);
    // head = insertionTail(head, val);
    // head = insertionKth(head, k, val);
    // insertionValBeforeNode(temp, val);
    // insertionValAfterNode(temp, val);
    // insertionValbeforeVal(head, val1, val);
    printDLL(head);

    return 0;
}