// Problem link: https://leetcode.com/problems/majority-element/

#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
   public:
    char character_;
    bool isWordEnding_;
    unordered_map<char, TrieNode*> neighbours_;

    TrieNode(char character, bool isWordEnding = false) {
        this->character_ = character;
        this->isWordEnding_ = isWordEnding;
    }
};

class Trie {
   public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode('*');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for (char currChar : word) {
            bool isCharPresent = temp->neighbours_[currChar];
            if (!isCharPresent) {
                TrieNode* newCharNode = new TrieNode(currChar);
                temp->neighbours_[currChar] = newCharNode;
            }
            temp = temp->neighbours_[currChar];
        }
        temp->isWordEnding_ = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for (char currChar : word) {
            bool isCharPresent = temp->neighbours_[currChar];
            if (!isCharPresent) {
                return false;
            }
            temp = temp->neighbours_[currChar];
        }
        return temp->isWordEnding_;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char currChar : prefix) {
            bool isCharPresent = temp->neighbours_[currChar];
            if (!isCharPresent) {
                return false;
            }
            temp = temp->neighbours_[currChar];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
}
