// Problem link: https://leetcode.com/problems/find-all-anagrams-in-a-string

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|p| + |s|)
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

vector<int> findAnagrams(string s, string p) {
    vector<int> anagramIndices;

    vector<int> pCharCounts = getCharCounts(p);
    vector<int> sCharCounts(26, 0);

    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < (int)s.length(); windowEnd++) {
        char currChar = s[windowEnd];
        ++sCharCounts[currChar - 'a'];

        int wordLen = windowEnd - windowStart + 1;
        if (wordLen == (int)p.length()) {
            if (areCharCountsEqual(sCharCounts, pCharCounts)) {
                anagramIndices.push_back(windowStart);
            }

            char charAtWindowStart = s[windowStart];
            --sCharCounts[charAtWindowStart - 'a'];
            ++windowStart;
        }
    }
    return anagramIndices;
}

int main() {
}
