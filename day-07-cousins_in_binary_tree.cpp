// Problem link: https://leetcode.com/problems/cousins-in-binary-tree

#include <iostream>
#include <queue>

using namespace std;

// Time complexity => O(height of tree)
// Space complexity => O(height of tree)

// We've used BFS to solve this problem becasue it's the most optimal way of verifying if two nodes are cousins
// or not, if they are cousins they might be on the first level and our algorithm will find the answer way much faster
// than DFS for this problem

struct NodeData {
    TreeNode* node;
    int depth;

    NodeData(TreeNode* root, int depth) {
        this->node = root;
        this->depth = depth;
    }
};

bool cousinFound(queue<NodeData>& q, int value, int depth) {
    int nullCount = 0;
    while (!q.empty()) {
        NodeData front = q.front();
        q.pop();

        TreeNode* node = front.node;
        if (node == NULL) {
            ++nullCount;
            continue;
        }

        if (node->val == value) {
            if (nullCount > 0 && front.depth == depth) {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool isCousins(TreeNode* root, int x, int y) {
    queue<NodeData> q;

    NodeData rootData(root, 0);
    q.push(rootData);

    while (!q.empty()) {
        NodeData front = q.front();
        q.pop();

        TreeNode* node = front.node;
        if (node == NULL) {
            continue;
        }

        int frontVal = front.node->val;

        if (frontVal == x) {
            return cousinFound(q, y, front.depth);
        }

        if (frontVal == y) {
            return cousinFound(q, x, front.depth);
        }

        if (node->left) {
            NodeData leftChild(node->left, front.depth + 1);
            q.push(leftChild);
        }

        if (node->right) {
            NodeData rightChild(node->right, front.depth + 1);
            q.push(rightChild);
        }

        NodeData siblingSeparator(NULL, front.depth);
        q.push(siblingSeparator);
    }
    return false;
}

int main() {
}
