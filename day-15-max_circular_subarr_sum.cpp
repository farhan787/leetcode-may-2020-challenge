// Problem link: https://leetcode.com/problems/maximum-sum-circular-subarray

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(n); n = size of nums
// Space complexity => O(1)
int getKadaneSubarrSum(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        int num = nums[i];
        currSum = max(currSum + num, num);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int getKadaneNegArrSum(vector<int>& nums) {
    int maxSum = -nums[0];
    int currSum = -nums[0];

    for (int i = 1; i < (int)nums.size(); i++) {
        int num = -nums[i];
        currSum = max(currSum + num, num);
        maxSum = max(maxSum, currSum);
    }
    return -maxSum;
}

int getArrSum(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    return sum;
}

int maxSubarraySumCircular(vector<int>& nums) {
    int numsSum = getArrSum(nums);
    int maxSubarrSum = getKadaneSubarrSum(nums);
    int maxSubarrNegativeSum = getKadaneNegArrSum(nums);

    if (numsSum == maxSubarrNegativeSum) {
        return maxSubarrSum;
    }

    int anotherMaxSumCandidate = numsSum - maxSubarrNegativeSum;
    return max(maxSubarrSum, anotherMaxSumCandidate);
}

int main() {
}
