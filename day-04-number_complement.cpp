// Problem link: https://leetcode.com/problems/number-complement/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(set bits in num)
// Space complexity => O(1)
int findComplement(int num) {
    int mask = 0;
    int temp = num;

    while (temp > 0) {
        temp = temp >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }

    int compNum = ~num & mask;
    return compNum;
}

int main() {
}
