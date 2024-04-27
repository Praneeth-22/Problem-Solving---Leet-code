//209. Minimum Size Subarray Sum
//Solved
//Medium
//Topics
//Companies
//Given an array of positive integers nums and a positive integer target, return the minimal length of a 
//subarray
// whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
//
// 
//
//Example 1:
//
//Input: target = 7, nums = [2,3,1,2,4,3]
//Output: 2
//Explanation: The subarray [4,3] has the minimal length under the problem constraint.
//Example 2:
//
//Input: target = 4, nums = [1,4,4]
//Output: 1
//Example 3:
//
//Input: target = 11, nums = [1,1,1,1,1,1,1,1]
//Output: 0
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0,ln = INT_MAX,sum=0;
        // sort(nums.begin(),nums.end());
        // while(l<=r){
        //     if(nums[l] == target || nums[r] == target){
        //         return 1;
        //     }else if(nums[l]+nums[r] < target){
        //         sum +=nums[r];
        //         ln+=1;
        //         l++;
        //     }
        //     else if(sum == target){
        //         return ln;
        //     }
        //     else{
        //         r--;
        //     }
        // }
        // return 0;

        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                ln =min(ln,(r-l+1));
                sum-=nums[l++];
            }
        }
        return ln == INT_MAX?0:ln;
    }
};
