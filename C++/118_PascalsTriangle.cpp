#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            // create a new row
            // fill the first and last element
            vector<int> v(i + 1, 1);
            for (int j = 1; j < i; j++)
                // fill the rest of the elements
                v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            // add the row to the answer
            ans.push_back(v);
        }
        return ans;
    }
};