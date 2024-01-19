#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class railway
{
public:
    int findMinPlatforms(int n, vector<int> arrTime, int k, vector<int> depTime)
    {
        int curr = 0;
        int maxi = 0;

        sort(arrTime.begin(), arrTime.end());
        sort(depTime.begin(), depTime.end());

        for(int i=0, j=0; i<n ;){
            if(arrTime[i]<=depTime[j]){
                curr++;
                maxi = max(curr,maxi);
                i++;
            }
            else{
                curr--;
                j++;
            }
        }
        return maxi;
    }
};

int main()
{
    // START  input.txt and output.txt syntax
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // END  input.txt and output.txt syntax

    int n;
    cin >> n;
    vector<int> arrTime;
    for (int i = 0; i < n; ++i)
    {   
        int temp;
        cin >> temp;
        arrTime.push_back(temp);
    }
    int k;
    cin >> k;
    vector<int> depTime;
    for (int i = 0; i < k; ++i)
    {
        int temp;
        cin >> temp;
        depTime.push_back(temp);
    }

    railway o1;
    cout << o1.findMinPlatforms(n, arrTime, k, depTime) << endl;
    return 0;
}