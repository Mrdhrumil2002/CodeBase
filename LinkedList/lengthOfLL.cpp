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
    for (int i = 0; i < vec.size(); i++)
    {
        Node *temp = new Node(vec[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int counter = 0;
    Node *temp = head;

    while (temp)
    {
        // cout << temp->data << " ";
        temp = temp->next;
        counter++;
    }

    return counter;
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

    vector<int> vec = { 6, 21, 5};
    Node *head = arrToLL(vec);
    cout << lengthOfLL(head);
    return 0;
}