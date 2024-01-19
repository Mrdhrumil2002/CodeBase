class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {

        int sumir(vector<int> & runningCosts, int k)
        {

            int sum[runningCost.size()];
            int sum1 = 0;
            for (j = 0; j < k; j++)
            {
                sum1 = runningCost[j] + sum1;
                sum[j] = (j + 1) * sum1;
            }

            return sum;
        }
    }
};