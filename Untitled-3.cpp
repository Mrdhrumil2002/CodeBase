//{ Driver Code Starts
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> FactDigit(int N)
    {
        int fact[10];
        fact[0] = 1;
        vector <int> anss;
        for (int i = 0; i < 10; i++)
        {
            fact[i] = i * fact[i - 1];
        }
        for (int i = 9; i >= 0; i--)
        {
            while (N >= fact[i])
            {
                N = N - fact[i];
                anss.push_back(i);
            }
        }
        return anss;
    };
};

//{ Driver Code Starts.
int
main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.FactDigit(N);
        for (auto i : ans)
            cout << i;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends