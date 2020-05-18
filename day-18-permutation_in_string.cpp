// Problem link: https://leetcode.com/problems/permutation-in-string

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|s1| + |s2|)
// Space complexity => O(1)
vector<int> getCharCounts(string& str) {
    vector<int> charCounts(26, 0);
    for (char ch : str) {
        charCounts[ch - 'a']++;
    }
    return charCounts;
}

bool areCharCountsEqual(vector<int>& charCounts1, vector<int>& charCounts2) {
    for (int i = 0; i < 26; i++) {
        if (charCounts1[i] != charCounts2[i]) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    vector<int> s1CharCounts = getCharCounts(s1);
    vector<int> s2CharCounts(26, 0);

    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < (int)s2.length(); windowEnd++) {
        char currChar = s2[windowEnd];
        ++s2CharCounts[currChar - 'a'];

        int windowLen = windowEnd - windowStart + 1;
        if (windowLen == (int)s1.length()) {
            if (areCharCountsEqual(s1CharCounts, s2CharCounts)) {
                return true;
            }
            char charAtWindowStart = s2[windowStart];
            --s2CharCounts[charAtWindowStart - 'a'];

            ++windowStart;
        }
    }
    return false;
}

int main() {
}
