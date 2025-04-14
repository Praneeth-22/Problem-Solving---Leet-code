// 55. Jump Game
// Solved
// Medium
// Topics
// Companies
// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

class Solution {
public:
    bool rec(vector<int>& nums,int idx){
        if(idx == nums.size()-1) return true;
        if(nums[idx] == 0) return false;
        int maxJump = idx+nums[idx];
        for(int i=idx+1;i<=maxJump;i++){
            if(i<nums.size() && rec(nums,i)) return true;
        }
        return false;
    }
    bool memo(vector<int>& nums,int idx,vector<int>& dp){
        if(idx == nums.size()-1) return true;
        if(nums[idx] == 0) return false;
        if(dp[idx]!=-1) return dp[idx];
        int maxJump = idx+nums[idx];
        for(int i=idx+1;i<=maxJump;i++){
            if(i<nums.size() && memo(nums,i,dp)) return dp[idx] =true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        //brute force recursion o(n^n) , o(n)
        //return rec(nums,0);
        // dp memorization o(n*n), o(n) + o(n)
        vector<int> dp(nums.size(),-1);
        return memo(nums,0,dp);
    }
};