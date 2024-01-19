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
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeHead(Node *head)
{
    // 1 element ll edge case
    if (head = NULL)
        return head;
    // 1 element ll
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *removeTail(Node *head)
{
    // 1 element ll edge case
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    // 1 element ll
    Node *temp = head;
    while ((temp->next->next) != NULL)
    {
        temp = temp->next;
    }

    delete (temp->next);
    temp->next = nullptr;
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

    vector<int> vec = {25, 6, 3, 1, 4, 8, 6, 5, 1, 2, 3, 85, 6, 21, 5};
    Node *head = arrToLL(vec);
    // head = removeHead(head);
    head = removeTail(head);

    printLL(head);
    return 0;
}