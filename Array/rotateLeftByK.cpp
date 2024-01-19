#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void reverse(vector<int> &nums, int start, int end)
    {
        int n = (end - start); // 7
        for (int i = start; (2 * i) < n; i++)
        {
            swap(nums[i], nums[end - i]);
        }
        return;
    }
    void rotate(vector<int> &nums, int d)
    {
        int k = nums.size() - 1;
        d = d % (k + 1);

        reverse(nums, 0, k);
        reverse(nums, 0, k - d);
        reverse(nums, k - d + 1, k);
    }
};
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
    Solution s1;
    s1.rotate(v1, 3);

    printVec(v1);
    return 0;
}