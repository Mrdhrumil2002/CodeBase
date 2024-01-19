#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

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


//given array is sorted 
//i have implement stop bit as 0 
// testcase :  1 1 1 1 1 2 2 2 2 2 2 3 3 3 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 7 7 7 8 8 8 8 8 8 8 9 9 9 9 10 22 25 77 89 92 94 96 97 98 99 0
// target : 25
    vector<int> nums;
    while (true)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
            break;
        nums.emplace_back(temp);
    }

    int low = 0;
    int high = 1;
    int dif = 2;
    int target = 25;
//track down our target
    while (target > nums[high])
    {
        low = high + 1;
        dif = 2 * dif;
        high = high + dif;
        // cout<<low<<" "<<high<<endl;
    }
    cout << low << " " << high << " "<<nums.size();
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (nums[mid] == target)
        {
            cout << nums[mid] << " FOUND @ " << mid;
            return 0;
        }
        else if(nums[mid]>target) high = mid-1;
        else low = mid+1;
    }
    
    return 0;
}