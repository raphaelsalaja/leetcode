#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int m_duplicate = m;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            // check if the int in num 1 is less than num 2
            if (nums1[i] < nums2[j])
            {
                // if its true then add to i to move forward
                i++;
            }
            else
            {
                // if its not the instert at the nesscessary position then add to all indexes
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
                i++;
                m++;
            }
        }
        while (j < n)
        {

            nums1.insert(nums1.begin() + i, nums2[j]);

            i++;

            j++;
        }
        int totalLength = n + m_duplicate;
        nums1.erase(nums1.begin() + totalLength, nums1.end());
    }
};