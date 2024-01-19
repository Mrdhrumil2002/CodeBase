#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int low, int high)
{
    int pivot = nums[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (nums[i] <= pivot && i < high)
        {
            i++;
        }
        while (nums[j] > pivot && j > low)
        {
            j--;
        }
        if(i<j)swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);

    return j;
}
void quickSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pivot = helper(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
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

    int n;
    cin >> n;
    vector<int> nums(n,0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    quickSort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    return 0;
}