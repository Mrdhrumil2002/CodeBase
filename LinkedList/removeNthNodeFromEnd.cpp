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

Node *removeNthNodefromEnd(Node *head, int N)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < N; ++i)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *deltemp = slow->next;
    slow->next = slow->next->next;
    delete deltemp;
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
    int k = 2;
    //    25, 6, 3, 1,  4, 8, 6, 5, 1, 2, 3,85, 6,21, 5};
    vector<int> vec = {25, 6, 3, 1, 4, 8, 6, 5, 1, 2, 3, 85, 6, 21, 5};
    Node *head = arrToDLL(vec);
    head = removeNthNodefromEnd(head, k);
    printDLL(head);

    return 0;
}