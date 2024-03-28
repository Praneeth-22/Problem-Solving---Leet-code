//
//46. Permutations
//Solved
//Medium
//Topics
//Companies
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//Example 2:
//
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]
//Example 3:
//
//Input: nums = [1]
//Output: [[1]]
// 
//
//Constraints:

// class Solution {
// public:
//     void recursiveCall(vector<int>& nums, vector<int>& temp,
//                        vector<vector<int>>& res, int n, int taken[]) {
//         if (temp.size() == n) {
//             res.push_back(temp);
//             return;
//         }
//         for (int i = 0; i < n; i++) {
//             if (!taken[i]) {
//                 temp.push_back(nums[i]);
//                 taken[i] = 1;
//                 recursiveCall(nums, temp, res, n, taken);
//                 taken[i] = 0;
//                 temp.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> temp;
//         int n = nums.size();
//         int taken[n];
//         for(int i =0; i<n;i++) taken[i] = 0;
//         recursiveCall(nums, temp, res, n, taken);
//         return res;
//     }
// };  

class Solution {
public:
void recursiveCall(int index,vector<int> &nums,vector<vector<int>> &res){
    if(index == nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        recursiveCall(index+1,nums,res);
        swap(nums[index],nums[i]);
    }
}
 vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        recursiveCall(0,nums,res);
        return res;
    }
};  
