#include<iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int arr[number][number];

    //        i = 5   4   3   2   1
    //        1  "_" "_" "_" "_" "1" 
    //        2  "_" "_" "_" "1" "1" 
    //    j = 3  "_" "_" "1" "2" "1" 
    //        4  "_" "1" "3" "3" "1" 
    //        5  "1" "4" "6" "4" "1" 
    for (int j = 1; j < number; j++)
    {  j = 2
        for (int i = number; i > 0; i--)
        {
            if (j >= i) {
                arr[4][j] = 1;
                arr[3][2] = 1;
                



            }
            else cout << " ";
        }

    }
    return 0;
}