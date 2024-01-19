#include<iostream>
using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        char yesno[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> yesno[i];
            yesno[i] = toupper(yesno[i]);
        }
        if (yesno[0] == 'Y' && yesno[1] == 'E' && yesno[2] == 'S') {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    };

    return 0;
}