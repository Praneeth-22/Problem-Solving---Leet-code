// 257. Binary Tree Paths
// Solved
// Easy
// Topics
// Companies
// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

 

// Example 1:


// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
// Example 2:

// Input: root = [1]
// Output: ["1"]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// -100 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findPath(TreeNode* root, vector<string>& ans, string temp){
        temp+=to_string(root->val);
        if(root->left) findPath(root->left,ans,temp+"->");
        if(root->right) findPath(root->right,ans,temp+"->");
        if(!root->left && !root->right) ans.push_back(temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root) findPath(root,ans,"");
        return ans;
    }
};