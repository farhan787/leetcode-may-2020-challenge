// Problem link: https://leetcode.com/problems/valid-perfect-square

#include <iostream>
using namespace std;

// Time complexity => O(log (num))
// Space complexity => O(1)
bool isPerfectSquare(int num) {
    // num = 16
    // 1...16
    // mid = 8, 64 > 16
    // 1...7
    // mid = 3, 9 < 16
    // 4...7
    // mid = 5, 25 > 16
    // 4....4
    // mid = 4, 16 == 16

    int low = 1;
    int high = num;

    while (low <= high) {
        long currNum = low + (high - low) / 2;
        long currSqr = currNum * currNum;

        if (currSqr == num) {
            return true;
        } else if (currSqr < num) {
            low = currNum + 1;
        } else {
            high = currNum - 1;
        }
    }

    return false;
}

// Time complexity => O(sqrt(num))
// Space complexity => O(1)
bool isPerfectSquare(int num) {
    unsigned int currNum = 1;
    unsigned int currSqr = currNum * currNum;
    while (currSqr <= num) {
        if (currSqr == num) {
            return true;
        }
        ++currNum;
        currSqr = currNum * currNum;
    }
    return false;
}

int main() {
}
