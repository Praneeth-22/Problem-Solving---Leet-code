// 872. Leaf-Similar Trees
// Solved
// Easy
// Topics
// Companies
// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true
// Example 2:


// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
 

// Constraints:

// The number of nodes in each tree will be in the range [1, 200].
// Both of the given trees will have values in the range [0, 200].


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void findLeaf(TreeNode* root, vector<int> &res) {
        if (!root)
            return;
        findLeaf(root->left, res);
        findLeaf(root->right, res);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            return;
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //
        vector<int> leaf1, leaf2;
        findLeaf(root1, leaf1);
        findLeaf(root2, leaf2);
        // if (leaf1.size() != leaf2.size())
        //     return false;
        // for (int i = 0; i < leaf1.size(); i++) {
        //     cout << leaf1[i] << " - " << leaf2[i];
        //     if (leaf1[i] != leaf2[i])
        //         return false;
        // }
        return leaf1==leaf2;
    }
};