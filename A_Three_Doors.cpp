#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, keyprovide, arr[3];
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> keyprovide;
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[keyprovide - 1] == 0) { cout << "NO" << endl; }
        else if (arr[arr[keyprovide - 1] - 1] != 0) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}