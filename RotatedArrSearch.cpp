#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Solution
{
public:
    int rotatedArrSearch(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[low] < nums[mid] && nums[mid] < target)
                low = mid + 1;
            else if (nums[low] < nums[mid] && target < nums[mid])
              
            else if (nums[mid] < nums[low] && target < nums[mid])
                low = mid + 1;
            else if (nums[mid] < nums[low] && nums[mid] < target)
                low = mid + 1;
        }
        return -1;
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

    int n, target;
    cin >> n;
    cin >> target;
    vector<int> nums(n, 0);
    for (auto it : nums)
        cin >> it;

    Solution s1;
    cout << s1.rotatedArrSearch(nums, target) << endl;

    return 0;
}