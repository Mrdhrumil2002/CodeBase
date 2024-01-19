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
    Node(int data1, Node *next1,Node* back1)
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

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
// START  input.txt and output.txt syntax
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
// END  input.txt and output.txt syntax






return 0;
}