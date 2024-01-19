#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int N;
        cin >> N;
        vector<int> arr1(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        int K;
        cin >> K;
        set<int> set;
        for (int i = 0; i < K; i++)
        {
            int temp;
            cin >> temp;
            set.insert(temp);
        }

        for (int i = 0; i < N; i++)
        {
            if (set.count(arr1[i]) == 1)
            {
                continue;
            }
            else
            {
                cout << arr1[i] << " " ;
            }
        }
        cout << endl;
    }
    return 0;
}
