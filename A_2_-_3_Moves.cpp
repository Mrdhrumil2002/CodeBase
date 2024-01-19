#include<iostream>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        int point;
        int time;
        cin >> point;
        if (point == 1) {
            cout << 2 << endl;

        }
        else if (point == 0) {
            cout << 0 << endl;
        }
        else if (point % 3 == 0) {
            time = point / 3;
            cout << time << endl;
        }
        else if (point == 2 || point == 4) {
            time = point / 2;
            cout << time << endl;
        }
        else if (point % 3 == 2) {
            time = ((point - point % 3) / 3) + 1;
            cout << time << endl;
        }
        else if (point % 3 == 1) {
            time = ((point - point % 3) / 3) + 1;
            cout << time << endl;
        }
    };

    return 0;
}