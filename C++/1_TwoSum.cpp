#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans = {};
        for (int i = 0; i < nums.size(); i++)
        {
            int alt = target - nums[i];

            auto itr = find(nums.begin() + i + 1, nums.end(), alt);

            if (itr != nums.end())
            {
                ans.push_back(i);
                ans.push_back(distance(nums.begin(), itr));
            }
        }

        return ans;
    }
};