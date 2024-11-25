// 222. Count Complete Tree Nodes
// Solved
// Easy
// Topics
// Companies
// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: 6
// Example 2:

// Input: root = []
// Output: 0
// Example 3:

// Input: root = [1]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5 * 104].
// 0 <= Node.val <= 5 * 104
// The tree is guaranteed to be complete.


class Solution {
public:
    int LDepth(TreeNode* root) {
        int depth = 0;
        while (root != nullptr) {
            root = root->left;
            depth++;
        }
        return depth;
    }
    int RDepth(TreeNode* root) {
        int depth = 0;
        while (root != nullptr) {
            root = root->right;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = LDepth(root);
        int rightDepth = RDepth(root);

        // If left and right depths are equal, it is a perfect binary tree
        if (leftDepth == rightDepth) {
            return pow(2, leftDepth) - 1;
        } else {
            // Otherwise, calculate recursively
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
