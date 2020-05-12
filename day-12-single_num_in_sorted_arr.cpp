// Problem link: https://leetcode.com/problems/single-element-in-a-sorted-array

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(log n); where n = size of nums
// Space complexity => O(1)
int singleNonDuplicate(vector<int>& nums) {
    int numsLen = (int)nums.size();

    int left = 0;
    int right = numsLen - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid - 1 >= 0 && mid + 1 < numsLen && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        // if first num in unique then return it, because we can't check the element before it
        // as nums[-1] is invalid and our logic will fail for this
        if (mid == 0 && mid + 1 < numsLen && nums[mid] != nums[mid + 1]) return nums[mid];

        // if nums[mid] == nums[mid-1] then move to find len of left and right arrays except
        // nums[mid] and nums[mid-1] and move to the array having odd length
        if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
            int leftLen = mid - 1;
            int rightLen = (int)nums.size() - 1 - mid;

            if (leftLen > 0 && leftLen & 1)
                right = mid - 1;
            else
                left = mid + 1;
        }

        // same thing as previous if condition but this time nums[mid] is matching with nums[mid+1]
        else if (mid + 1 < numsLen && nums[mid] == nums[mid + 1]) {
            int leftLen = mid;
            int rightLen = (int)nums.size() - mid - 2;

            if (leftLen > 0 && leftLen & 1)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return nums[right];
}

int main() {
}
