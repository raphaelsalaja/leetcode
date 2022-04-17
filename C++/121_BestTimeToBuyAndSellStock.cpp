#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int result = 0;

        int n = prices.size();

        int bought_price = prices[0];

        for (int i = 1; i < n; ++i)
        {

            // selling here
            int profit = prices[i] - bought_price;
            result = max(result, profit);

            // buying here... check if we could buy a share cheaper
            bought_price = min(bought_price, prices[i]);
        }

        return result;
    }
};