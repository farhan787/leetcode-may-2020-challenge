// Problem link: https://leetcode.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <vector>
using namespace std;

// Time complexity => O(|s| * log|s|)
// Space complexity => O(|s\)
unordered_map<char, int> getCharCounts(string& s) {
    unordered_map<char, int> charCounts;
    for (char ch : s) {
        charCounts[ch]++;
    }
    return charCounts;
}

priority_queue<pair<int, char>> getMaxHeap(string& s, unordered_map<char, int>& charCounts) {
    priority_queue<pair<int, char>> maxHeap;
    unordered_set<char> alreadyInsertedInHeap;

    for (char ch : s) {
        if (alreadyInsertedInHeap.find(ch) != alreadyInsertedInHeap.end()) continue;

        pair<int, char> charInfo(charCounts[ch], ch);
        maxHeap.push(charInfo);
        alreadyInsertedInHeap.insert(ch);
    }
    return maxHeap;
}

string getFreqSortedStr(priority_queue<pair<int, char>>& maxHeap) {
    string freqSortedStr = "";
    while (!maxHeap.empty()) {
        pair<int, char> topPair = maxHeap.top();
        for (int i = 0; i < topPair.first; i++) {
            freqSortedStr += topPair.second;
        }
        maxHeap.pop();
    }
    return freqSortedStr;
}

string frequencySort(string s) {
    unordered_map<char, int> charCounts = getCharCounts(s);
    priority_queue<pair<int, char>> maxHeap = getMaxHeap(s, charCounts);

    string freqSortedStr = getFreqSortedStr(maxHeap);
    return freqSortedStr;
}

int main() {
}
