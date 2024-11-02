// 993. Cousins in Binary Tree
// Solved
// Easy
// Topics
// Companies
// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

// Example 1:


// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:


// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:


// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [2, 100].
// 1 <= Node.val <= 100
// Each node has a unique value.
// x != y
// x and y are exist in the tree.

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
        bool findDepth(TreeNode* root,int &parent,int &depth,int &val,int currdepth){
            if(!root) return false;
            if((root->left && root->left->val == val)|| (root->right && root->right->val == val)){
                 parent = root->val;
                 depth = currdepth+1;
                 return true;
            }
            
            return findDepth(root->left,parent,depth,val,currdepth+1) ||
            findDepth(root->right,parent,depth,val,currdepth+1);
        }
        bool isCousins(TreeNode* root, int x, int y) {
            if(!root||root->val == x || root->val == y) return false;
            int lparent = -1;
            int rparent = -1;
            int leftpos=-1,rightpos=-1;
            findDepth(root,lparent,leftpos,x,0);
            findDepth(root,rparent,rightpos,y,0);
            return leftpos == rightpos && lparent!=rparent;
        }
    };