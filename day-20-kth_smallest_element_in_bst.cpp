// Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Time complexity => O(height of bst);
// Space complexity => O(height of bst) for call stack
void inorderDFS(TreeNode* root, int k, int& count, int& kthSmallestNum) {
    if (!root) return;

    inorderDFS(root->left, k, count, kthSmallestNum);

    ++count;
    if (count == k) {
        kthSmallestNum = root->val;
        return;
    }

    inorderDFS(root->right, k, count, kthSmallestNum);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int kthSmallestNum = -1;

    inorderDFS(root, k, count, kthSmallestNum);
    return kthSmallestNum;
}

int main() {
}
