#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        int ans = m * n;
        int ans1 = r * c;
        if (ans != ans1)
            return mat;
        int nc = 0, nr = 0;
        vector<vector<int>> v(r, vector<int>(c));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (nc == c)
                {
                    nr++;
                    nc = 0;
                }
                v[nr][nc] = mat[i][j];
                nc++;
            }
        }
        return v;
    }
};