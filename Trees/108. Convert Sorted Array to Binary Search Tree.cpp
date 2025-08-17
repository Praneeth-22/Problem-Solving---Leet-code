// 108. Convert Sorted Array to Binary Search Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:


// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

//  /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    TreeNode* helperfunc(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helperfunc(nums,start,mid-1);
        root->right = helperfunc(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helperfunc(nums,0,nums.size()-1);
    }
};