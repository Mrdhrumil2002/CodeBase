#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        int size;
        cin >> size;

        int arr[size];
        int max, index;
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            if (i > 0)
            {
                if (arr[i] > arr[i - 1])
                {
                    max = arr[i];
                    index = i;
                }
            }
        }
        if (index > size / 2)
        {
            rotate(vec1.at(index), vec1.at(index) - (size - index), vec1.end());
        }
        else
        {
            rotate(vec1.at(index), vec1.at(index) + (size - index), vec1.end());
        }
        cout << max - arr[0] << endl;
    };

    return 0;
}