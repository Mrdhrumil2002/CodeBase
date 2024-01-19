#include <bits/stdc++.h>
using namespace std;

int ceiling(int *arr, int *target, int *size)
{

    int left = 0;
    int right = *size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == *target)
            return arr[mid];
        else if (arr[mid] < *target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return arr[right];
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

    int size;
    cin >> size;

    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int target = 9;

    cout << ceiling(array, &target, &size) << endl;

    return 0;
}