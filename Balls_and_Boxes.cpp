#include <iostream>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        int N;
        cin >> N;
        int K;
        cin >> K;
        if (N < K)
        {
            cout << "NO" << endl;
        }
       
    };

    return 0;
}