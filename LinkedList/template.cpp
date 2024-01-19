#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main() {
// START  input.txt and output.txt syntax
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
// END  input.txt and output.txt syntax

vector<int> vec = { 5,6,3,1,4,8,6,5,1,2,3,85,6,21,5};
Node* X = new Node(vec[10] , nullptr);
// Node* X = new Node( <val> , <pointer> );
cout<<X<<endl;
cout<<X->data<<endl;
cout<<X->next<<endl;

return 0;
}