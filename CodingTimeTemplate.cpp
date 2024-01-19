#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
typedef unsigned long long int ll;
using namespace std;


// output
// at 1 billion iteration
// normal          4094 us 
// O.F.Handle      3953 us 
// BIT Man 1       4113 us
// BITMan + OF     3961 us
// BITman OF v2    4266 us


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
    long long noOfInt = 2000000000;
    int left = rand();
    int right = rand();

    // normal
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= noOfInt; i++)
    {
        int mid = (left + right) / 2;
        if (mid > numeric_limits<int>::max())
            throw range_error(" overflow");
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "normal          " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " us " << endl;

    // overflow handle
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= noOfInt; i++)
    {
        int mid1 = left + ((right - left) / 2);
        if (mid1 > numeric_limits<int>::max())
            throw range_error(" overflow");
    }
    end = chrono::high_resolution_clock::now();
    cout << "O.F.Handle      " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " us " << endl;

    // bit man
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= noOfInt; i++)
    {
        int mid2 = ((left + right) >> 1);
        if (mid2 > numeric_limits<int>::max())
            throw range_error(" overflow");
    }
    end = chrono::high_resolution_clock::now();
    cout << "BIT Man 1       " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " us" << endl;

    // bit man 2
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= noOfInt; i++)
    {
        int mid3 = left + ((right - left) >> 1);
        if (mid3 > numeric_limits<int>::max())
            throw range_error(" overflow");
    }
    end = chrono::high_resolution_clock::now();
    cout << "BITMan + OF     " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " us" << endl;

    // bitman 3
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i <= noOfInt; i++)
    {
        int mid4 = (left >> 1) + (right >> 1);
        if (mid4 > numeric_limits<int>::max())
            throw range_error(" overflow");
    }
    end = chrono::high_resolution_clock::now();
    cout << "BITman OF v2    " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " us" << endl;

    return 0;
}
