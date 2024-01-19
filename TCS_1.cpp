#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;

vector<bool> sieve_of_eratosthenes(int n, int q)
{
    vector<bool> is_prime((n + 1), true);

    for (int p = 2; p * p <= n; p++)
    {
        if (is_prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }
    
    for (int i = 0; i < is_prime.size(); i++)
    {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << endl
         << endl;
    for (int i = 0; (i + q) < is_prime.size(); ++i)
        is_prime[i] = is_prime[i + q];

    for (int i = is_prime.size() - 1; i + q >= is_prime.size() ; --i)
        is_prime[i] = false;

    for (int i = 0; i < is_prime.size(); i++)
    {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << endl
         << endl;
    return is_prime;
}

class Solution
{
public:
    int lowestNum(vector<int> nums, int q, long long int prod)
    {
        int ans;
        bool compItFlag = true;

        ans = prod;
        vector<bool> prime = sieve_of_eratosthenes(prod+1, q);

        for (int i = prime.size() - 1; i >= 0; --i)
        {
            if (prime[i])
            {
                for (auto it : nums)
                {
                    if ((i % it) != 0 && it != q)
                    {
                        compItFlag = false;
                        break;
                    }
                }
                if (compItFlag && i < ans)
                    ans = i;
            }
            compItFlag = true;
        }
        return ans == prod ? ans + q : -1;
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
    int size;
    cin >> size;
    vector<int> nums(size, 0);

    auto start = chrono::high_resolution_clock::now();

    int q = 1;
    long long int prod = 1;
    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }
    for (auto it : nums)
    {
        q = min(q, it);
        prod *= it;
    }
    prod /= q;

    Solution ans;
    int answer = ans.lowestNum(nums, q, prod);
    answer == -1 ? cout << "None" << endl : cout << answer << endl;

    auto end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;

    return 0;
}