// Problem link: https://leetcode.com/problems/ransom-note/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|magazine| + |ransomNote|)
// Space complexity => O(1)
bool canConstruct(string ransomNote, string magazine) {
    vector<int> charCount(26, 0);
    for (char ch : magazine) {
        charCount[ch - 'a']++;
    }

    for (char ch : ransomNote) {
        if (charCount[ch - 'a'] == 0) {
            return false;
        }
        charCount[ch - 'a']--;
    }
    return true;
}

int main() {
}
