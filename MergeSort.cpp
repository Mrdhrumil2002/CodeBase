#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void merge(vector<int> &nums , int low , int mid , int high){
        vector<int> temp;
        int i=low, j=mid+1;
        while( i<=mid && j<=high){
            if(nums[i] > nums[j]){
                temp.emplace_back(nums[j]);
                j++;
            }
            else {
                temp.emplace_back(nums[i]);
                i++;
            }
        }
        while(j<=high){
            temp.emplace_back(nums[j]);
            j++;
        }
        while(i<=mid ){
            temp.emplace_back(nums[i]);
            i++;
        }

        for(int k=low; k<=high; k++)nums[k] = temp[k-low];
        
    }
    void mergeSort(vector<int> &nums , int low , int high){
        if(low >= high)return;
        int mid = low +(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low , mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
    }
};

int main(){
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
    for(int i=0; i<n; i++) cin>>nums[i];
    Solution ans;

    auto k = ans.sortArray(nums);
    for(int i=0; i<n; i++) cout<<nums[i]<<" ";
    
    return 0;
}