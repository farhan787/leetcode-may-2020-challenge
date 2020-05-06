// Problem link: https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(n); n = size of nums
// Space complexity => O(1)
int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < (int)nums.size(); ++i) {
        int num = nums[i];
        if (num == candidate) ++count;
        else --count;

        if (count < 1) {
            candidate = num;
            count = 1;
        }
    }
    return candidate;
}

int main() {
}
