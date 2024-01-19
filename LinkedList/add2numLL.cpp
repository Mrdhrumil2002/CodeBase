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
    Node(void)
    {
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
Node *add2numLL(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *head3 = new Node(-1);

    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *temp3 = head3;

    int carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {

        // int sum = (temp1->data) + (temp2->data) + carry; // cant add directly as "NULL + <number> ==> error"
        int sum = carry;
        if (temp1) // security checks: if temp1 is NULL...it wont add into sum;
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;
        carry = sum / 10;

        Node *sumi = new Node(sum % 10);
        temp3->next = sumi;

        // temp1 = temp1->next; // this wil give nullpointer exception because of "null->next" is error
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
        temp3 = temp3->next;
    }
    if (carry)
    {
        Node *sumi = new Node(carry);
        temp3->next = sumi;
    }
    return head3->next;
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
    vector<int> vec1 = {5, 3, 8}; // 835
    vector<int> vec2 = {6, 8, 9}; // 986
    Node *head1 = arrToLL(vec1);
    Node *head2 = arrToLL(vec2);
    Node *head3 = add2numLL(head1, head2); // 1821
    printLL(head3);

    return 0;
}