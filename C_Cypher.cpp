#include<iostream>
#include <string>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for (int x = 0; x < test; x++) {


        int noofwheel; //3
        cin >> noofwheel; //  input 3
        int wheelno[noofwheel]; // 9 3 1

        for (int i = 0; i < noofwheel; i++)
        {
            cin >> wheelno[i]; // input 9 3 1 
        }

        int noofrotation; // [3] DDD

        for (int i = 0; i < noofwheel; i++)
        {
            cin >> noofrotation; // input [3]
            char rotate[noofrotation]; // 3 [DDD]

            for (int j = 0; j < noofrotation; j++)
            {
                cin >> rotate[j]; // input DDD

                if (rotate[j] == 'D') {
                    wheelno[i]++; // update  9 3 1
                }
                else {
                    wheelno[i]--;
                }
            }
        };
        for (int i = 0; i < noofwheel; i++) {


            if (wheelno[i] > 9) {
                wheelno[i] = wheelno[i] % 10;
            }
            else if (wheelno[i] < 0) {
                wheelno[i] = 10 + wheelno[i];
            }
        }
        for (int p = 0; p < noofwheel; p++)
        {
            cout << wheelno[p] << " "; //out put updated 9 3 1
        }
        cout << endl;
    }
    return 0;
}