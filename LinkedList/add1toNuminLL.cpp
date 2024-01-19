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
Node *add1toLL(Node *head)
{ // 5 9 1   + 1
    head = reverseLL(head);
    // 1 9 5
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    int carry = 1;

    while (temp != NULL)
    {
        if (carry == 0)
            break;
        int sum = carry + temp->data;
        temp->data = (sum % 10);

        carry = sum / 10;
        // 9 9 9
        temp = temp->next;
    }
    // 2 9 5
    if (carry)
    {
        head = reverseLL(head);
        Node *newHead = new Node(carry, head);
        return newHead;
    }

    head = reverseLL(head);

    // TC O(3N)
    // SC O(1)
    return head;
}

int carry = 1;
int recursionHelper(Node *head)
{
    if (head == NULL)
    // return carry; // 1) as we know carry is intialy 1 then we can directly substitute 1 in place of carry. 2) advantage is that we had not to declare global fxn
    {
        return 1;
    }
    head->data = head->data + recursionHelper(head->next);
    if (head->data < 10)
        return 0;
    carry = head->data / 10;
    head->data = head->data % 10;
    return carry;
}
Node *add1toLLRecursion(Node *head)
{

    if (head == NULL)
        return head;

    carry = recursionHelper(head);
    if (carry)
    {
        Node *newHead = new Node(1, head);
        return newHead;
    }
    return head;
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
    // vector<int> vec = {25, 6, 3, 1, 4, 8, 6, 5, 1, 2, 3, 85, 6, 21, 5};
    vector<int> vec1 = {0,0,0,0,0};
    Node *head = arrToDLL(vec1);

    // head = add1toLL(head);
    head = add1toLLRecursion(head);

    // head = reverseRecursion(head);
    printLL(head);

    return 0;
}