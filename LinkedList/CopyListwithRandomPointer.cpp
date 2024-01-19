#include <bits/stdc++.h>
using namespace std;



// wrong
// refere leetcode solution
//hint:{ use map of node node
// then store original and deep copy node in map}





















// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *newHead = new Node(-1);
        Node *tempNew = newHead;
        Node *temp = head;

        while (temp != NULL)
        {
            Node *cal = temp->next;
            Node *store = new Node(temp->val);
            temp->next = store;
            store->next = cal;
            temp = cal;
        }
        temp = head;
        while (temp != NULL)
        {
            Node *locStore = temp->next;
            if (temp->random)
                locStore->random = temp->random->next;
            else
                locStore->random = NULL;
            temp = temp->next->next;
        }
        temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            tempNew->next = temp;
            tempNew = tempNew->next;
            temp = temp->next;
            tempNew->next = NULL;
        }

        return newHead->next;
    }
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
        cout << temp->val << " ";
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
    Node *head = arrToLL(vec);
    Solution s1;
    head = s1.copyRandomList(head);
    printLL(head);
    return 0;
}