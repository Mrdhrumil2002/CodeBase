#include <iostream>
using namespace std;

long permu(int n)
{
    long array[10000001];
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;
    for (int i = 4; i < 10000000; i++)
    {
        array[i] = array[i - 1] * 2 - (i - 3);
    };
    return array[n];
}

int main()
{
    int test;
    cin >> test;
    for (int z = 0; z < test; z++)
    {
        string string;
        cin >> string;
        long counter = 0;
        for (int i = 1; i < string.length(); i++)
        {
            if (string[i] != string[i - 1])
            
            {
                counter = counter + permu(i+1);
            }
        }
    }
    return 0;
}