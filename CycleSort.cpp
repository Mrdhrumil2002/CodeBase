#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &nums , int pi){
int temp = nums[nums[pi]];
nums[nums[pi]] = nums[pi];
cycleSort(nums,temp);
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

int n;
cin>>n;
vector<int> nums(n,0);
for (int i = 0; i < n ; i++){cin>>nums[i];}
// cycleSort(nums,nums[0]);
for (int i = 0; i < n ; i++){cout<<nums[i]<<" ";}


return 0; 
}