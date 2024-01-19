
/**
 * Definition for singly-linked list.
 * struct Node {
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
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

class Solution
{
public:
    Node *mergeTwoLists(Node *temp1, Node *temp2)
    {
        Node *head = new Node(-1);
        Node *temp = head;
        if (temp1 == NULL)
            return temp2;
        if (temp2 == NULL)
            return temp1;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data >= temp2->data)
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            else
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            temp = temp->next;
            if (temp2 == NULL)
                temp->next = temp1;
            if (temp1 == NULL)
                temp->next = temp2;
        }
        return head->next;
    }
    Node *sortList(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *fast = head;
        Node *slow = head;
        fast = fast->next->next;
        while (fast != NULL && fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;
        }
        Node *head2 = slow->next;
        slow->next = NULL;
        Node *headLord1 = sortList(head);
        Node *headLord2 = sortList(head2);
        return mergeTwoLists(headLord1, headLord2);
    }
};

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
    vector<int> vec1 = {1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 8, 21, 25};
    vector<int> vec2 = {1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 8, 21, 25};
    Node *head1 = arrToLL(vec1);
    Node *head2 = arrToLL(vec2);
    Solution s1;
    Node *head = s1.mergeTwoLists(head1, head2);
    printLL(head);
    return 0;
}