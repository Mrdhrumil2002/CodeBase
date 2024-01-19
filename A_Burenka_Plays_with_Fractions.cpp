#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        long double a, b, c, d;
        
        cin >> a >> b >> c >> d;
        long double deno = a*d;
        long double nume = b*c;
        
        if (deno == nume)
        {
            cout << '0' << endl;
        }
        else if (a == 0 || c == 0)
        {
            cout << '1' << endl;
        }
        
        else if (fmod(nume , deno) == 0 || fmod(deno,nume) == 0)
        {
            cout << '1' << endl;
        }
        else
        {
            cout << '2' << endl;
        }
    };

    return 0;
}