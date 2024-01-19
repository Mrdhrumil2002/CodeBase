#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> v1){
    for(auto it: v1){
        cout<<it<<" ";
    }
    return;
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

    vector<int> v1 = {1, 2, 5, 6, 4, 8, 8, 6, 4, 8, 9, 65, 2, 5};
    printVec(v1);
    return 0;
}