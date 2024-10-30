// 101. Symmetric Tree
// Attempted
// Easy
// Topics
// Companies
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100
 

// Follow up: Could you solve it both recursively and iteratively?


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
    void preOrder(TreeNode* root, vector<int>& pre) {
        if (root == nullptr) {
            pre.push_back(-1);
            return;
        }
        pre.push_back(root->val);
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
    void postOrder(TreeNode* root, vector<int>& post) {
        if (root == nullptr) {
            post.push_back(-1);
            return;
        }
        post.push_back(root->val);
        postOrder(root->right, post);
        postOrder(root->left, post);
    }
    bool isMirror(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val) && isMirror(left->left,right->right) && isMirror(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // extra space
        if (root == nullptr)
            return true;
        // vector<int> pre, post;
        // preOrder(root->left, pre);
        // postOrder(root->right, post);
        // return pre == post;
        //optimal solution
        return isMirror(root->left,root->right);
    }
};