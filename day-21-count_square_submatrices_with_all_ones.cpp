// Problem link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <iostream>
#include <vector>

using namespace std;

/*
Two approaches - 
1. Brute Force
2. Optimised DP solution
*/

// 1. INTUTIVE BRUTE FORCE SOLUTION ACCEPTED

// Time complexity => O(maxSquareSize * rows^2 * cols^2)
// Space complexity => O(1)
bool isSquareFound(vector<vector<int>>& matrix, int row, int col, int squareSize) {
    if (squareSize == 1) return matrix[row][col];

    const int rows = (int)matrix.size();
    const int cols = (int)matrix[0].size();

    // check if the square size we're looking for is out of bounds for current cell (row, col)
    if (col + squareSize > cols) return false;
    if (row + squareSize > rows) return false;

    for (int i = row; i < row + squareSize; i++) {
        for (int j = col; j < col + squareSize; j++) {
            if (matrix[i][j] == 0) return false;
        }
    }
    return true;
}

int countSquares(vector<vector<int>>& matrix) {
    const int rows = (int)matrix.size();
    const int cols = (int)matrix[0].size();

    int squareCount = 0;
    int lastSquareCount = squareCount;

    for (int squareSize = 1; true; squareSize++) {
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) continue;

                bool squareFound = isSquareFound(matrix, row, col, squareSize);
                if (squareFound) ++squareCount;
            }
        }
        if (squareCount == lastSquareCount) return squareCount;
        lastSquareCount = squareCount;
    }

    return squareCount;
}

// 2. Optimised DP Solution

// Time complexity => O(rows * cols)
// Space complexity => O(rows * cols)
int countSquares(vector<vector<int>>& matrix) {
    const int rows = (int)matrix.size();
    const int cols = (int)matrix[0].size();

    vector<vector<int>> dp = matrix;
    int squareCount = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (row == 0 || col == 0 || matrix[row][col] == 0) {
                // to count the squares of size 1 when row == 0 || col == 0
                squareCount += matrix[row][col];
                continue;
            }

            dp[row][col] += min({dp[row][col - 1], dp[row - 1][col], dp[row - 1][col - 1]});
            squareCount += dp[row][col];
        }
    }
    return squareCount;
}

int main() {
}
