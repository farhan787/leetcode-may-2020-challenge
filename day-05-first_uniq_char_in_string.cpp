// Problem link: http://leetcode.com/problems/first-unique-character-in-a-string

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|s|)
// Space complexity => O(1)
int firstUniqChar(string s) {
    vector<int> charCount(26, 0);
    for (char ch : s) {
        charCount[ch - 'a']++;
    }

    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];
        if (charCount[ch - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
}
