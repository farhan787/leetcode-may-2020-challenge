// Problem link: https://leetcode.com/problems/jewels-and-stones

#include <iostream>
#include <vector>
using namespace std;

bool isCapitalChar(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

// Time complexity => O(|J| + |S|)
// Space complexity => O(1)
int numJewelsInStones(string J, string S) {
    int numJewels = 0;

    vector<char> smallCharCount(26, 0);
    vector<char> capitalCharCount(26, 0);

    for (char jewel : J) {
        if (isCapitalChar(jewel)) {
            capitalCharCount[jewel - 'A']++;
        } else {
            smallCharCount[jewel - 'a']++;
        }
    }

    for (char stone : S) {
        if (isCapitalChar(stone) && capitalCharCount[stone - 'A'] > 0) {
            ++numJewels;
        }

        else if (!isCapitalChar(stone) && smallCharCount[stone - 'a'] > 0) {
            ++numJewels;
        }
    }

    return numJewels;
}

int main() {
}
