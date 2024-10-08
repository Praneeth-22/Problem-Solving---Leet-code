//783. Minimum Distance Between BST Nodes
//Solved
//Easy
//Topics
//Companies
//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
//
// 
//
//Example 1:
//
//
//Input: root = [4,2,6,1,3]
//Output: 1
//Example 2:
//
//
//Input: root = [1,0,48,null,null,12,49]
//Output: 1
// 
//
//Constraints:
//
//The number of nodes in the tree is in the range [2, 100].
//0 <= Node.val <= 105

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
    int inOrderTraversal(TreeNode* root,int& prev,int& diff){
        if(root == nullptr) return diff;
        inOrderTraversal(root->left,prev,diff);
        if(prev!= -1){
            diff = min(root->val - prev,diff);
        }
        prev = root->val;
        inOrderTraversal(root->right,prev,diff);
        return diff;
    }
    int minDiffInBST(TreeNode* root) {
        int prev = -1,diff = INT_MAX;
        return inOrderTraversal(root,prev,diff);
    }
};
