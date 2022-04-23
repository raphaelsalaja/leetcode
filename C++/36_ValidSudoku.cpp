#include <vector>
#include <iostream>
#include <string>
#include <bitset>
#include <iterator>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bitset<9>> bitsetarray(27);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char n = board[i][j];
                if (n != '.')
                {
                    if (bitsetarray[i][n] > 0 || bitsetarray[9 + j][n] > 0 || bitsetarray[18 + (3 * (i / 3)) + (j / 3)][n] > 0)
                        return false;
                    bitsetarray[i][n] = true;
                    bitsetarray[9 + j][n] = true;
                    bitsetarray[18 + (3 * (i / 3)) + (j / 3)][n] = true;
                }
            }
        }
        return true;
    }
};

/*

Intuition

Since we have 9 rows, 9 columns, and 9 boxes, each requiring unique values in the range 0 to 9,
we can use bitsets here as the size of each bitset is known at compile time which is 9, for nine possible valid values.
Bitset can be substituted with a boolean array too. Algorithm

We create an array of 27 (equal to 9 + 9 + 9) bitsets, each having a size of 9 elements.
We label the first nine bitsets[0,8] to represent the nine rows, the next nine bitsets[9,17] to represent the columns and the remaining nine bitsets[18,26] to represent the boxes
We iterate through the matrix given one by one and check if the corresponding row, column and box bitset has the matrix value index set to true
(equivalent to checking if that number has been seen before in the corresponding row,column or box)using the formula:

    Matrix[i][j] is in:
        Row i = BitSetArray[i]
        Column j = BitSetArray[9+j]
        Box k = BitSetArray[18+(3*(i/3))+(j/3)]

If seen in any of the above bitsets (i.eBitsetArray[0-26][Matrix[i][j]] is set then return false (invalid sudoku table);

If all matrix elements are done being scanned return true;

*/