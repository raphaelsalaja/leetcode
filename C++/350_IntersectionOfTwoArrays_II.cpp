// import vector
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        // sort the two arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // iterate through the two arrays
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        // while both arrays have elements
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            // if the current element of the first array is less
            // than the current element of the second array
            if (*it1 == *it2)
            {
                // add the current element to the result
                result.push_back(*it1);
                it1++;
                it2++;
            }
            else if (*it1 < *it2)
            {
                // move the first array's iterator to the next element
                it1++;
            }
            else
            {
                // move the second array's iterator to the next element
                it2++;
            }
        }
        return result;
    }
};