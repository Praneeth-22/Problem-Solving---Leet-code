// 230. Kth Smallest Element in a BST
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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
    void inorder(TreeNode* root,vector<int> &arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
     void inorderOptimal(TreeNode* root, int &cnt, int &ans, int k){
        if(!root) return;
        inorderOptimal(root->left,cnt,ans,k);
        cnt++;
        if(cnt==k){
            ans = root->val;
            return;
        }
        inorderOptimal(root->right,cnt,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        //brute force: inorder and same in sorted array
        // vector<int> arr;
        // inorder(root,arr);
        // return arr[k-1];
        //optimal
        int cnt=0,ans;
        inorderOptimal(root,cnt,ans,k);
        return ans;
    }
};