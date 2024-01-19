#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, top = 0;
        int right = m - 1, bottom = n - 1;

        while (top <= bottom && right >= left)
        {

            if (top <= bottom && right >= left)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.emplace_back(matrix[top][i]);
                    cout << "L2R"
                         << " ";
                }

                top++;
            }
            cout << endl;
            if (top <= bottom && right >= left)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.emplace_back(matrix[i][right]);
                    cout << "T2B"
                         << " ";
                }

                right--;
            }
            cout << endl;
            if (top <= bottom && right >= left)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.emplace_back(matrix[bottom][i]);
                    cout << "R2L"
                         << " ";
                }

                bottom--;
            }
            cout << endl;
            if (top <= bottom && right >= left)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.emplace_back(matrix[i][left]);
                    cout << "B2T"
                         << " ";
                }

                left++;
            }
            cout << endl;
        }

        return ans;
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
    vector<vector<int>> v1 = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}};

    vector<vector<int>> v3 = {
        {1, 2, 3},
        {6, 9, 8},
        {7, 4, 5}};
    Solution s1;
    vector<int> v2 = s1.spiralOrder(v1);
    for (auto it : v2)
    
        cout << it << " ";
    return 0;
}