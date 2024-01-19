#include <bits/stdc++.h>
#include <vector>
using namespace std;

void swapAcc(vector<long long> &first, vector<long long> &second, int in1,
             int in2)
{
    if (first[in1] > second[in2])
        swap(first[in1], second[in2]);
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b)
{

    // optimize solution 2 tc: O(log(m+n) + (m+n)) sc: o(1)

    int m = a.size();
    int n = b.size();
    int gFlag = 0;
    int len = m + n;

    for (int gap = (len / 2) + (len % 2); gap > 0; gap = (gap / 2) + (gap % 2))
    {

        for (int left = 0, right = gap; right < len; left++, right++)
        {

            if (left >= m)
                swapAcc(b, b, left - m, right - m);

            else if (right >= m)
                swapAcc(a, b, left, right - m);

            else if (a[left] > a[right])
                swapAcc(a, a, left, right);
        }
        if (gap == 1)
            break;
    }
    return;
}

void printVector(const vector<long long> &vec)
{
    for (const auto &element : vec)
    {
        cout << element << " ";
    }
    cout << endl;
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
 
    // Generate two sorted vectors
    vector<long long> a = {1, 3, 5, 7, 8, 9, 15, 35, 65, 85, 95, 215, 335, 448, 555, 666, 777, 888, 999, 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    vector<long long> b = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42};

    // Call the mergeTwoSortedArraysWithoutExtraSpace function
    mergeTwoSortedArraysWithoutExtraSpace(a, b);

    // Print the sorted arrays
    cout << "Sorted Array A: ";
    printVector(a);

    cout << "Sorted Array B: ";
    printVector(b);

    return 0;
}
