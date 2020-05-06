// Problem link: https://leetcode.com/problems/first-bad-version

#include <iostream>
#include <vector>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

// Time complexity => O(log n)
// Space complexity => O(1)
int firstBadVersion(int n) {
    int leftMostBadVersion = n;

    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            leftMostBadVersion = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return leftMostBadVersion;
}

int main() {
}
