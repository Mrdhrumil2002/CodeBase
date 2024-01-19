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

Node *sortin0s1s2s(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    // 0 1 2 -1
    // 0 1 -1
    // 0 2
    // 0
    // 1 2
    // 1
    // 2
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = (twoHead->next);
    two->next = NULL;
    head = zeroHead->next;
    delete (zeroHead, oneHead, twoHead);
    return head;
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

    vector<int> vec = {1, 2, 0, 1, 2, 0, 2, 1, 0, 1, 0, 2, 2, 0, 2, 1, 0, 1, 2, 1, 0, 1, 2, 0, 0, 2, 1, 1, 0, 2};
    Node *head = arrToDLL(vec);
    head = sortin0s1s2s(head);
    printDLL(head);

    return 0;
}