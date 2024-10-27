// 448. Find All Numbers Disappeared in an Array
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 105
// 1 <= nums[i] <= n
 

// Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // extra space
        int n = nums.size();
        vector<int> res;
        // unordered_set<int> st;
        // for (int i = 0; i < n; i++) {
        //     st.insert(nums[i]);
        // }
        // for (int i = 1; i <= n; i++) {
        //     if (st.find(i) == st.end()) {
        //         res.push_back(i);
        //     }
        // }
        //optimal solution
        for(int i =0;i<n;i++){
            int ind = abs(nums[i])-1;
            nums[ind] = (nums[ind]>0)? -nums[ind]:nums[ind];
        }
        for(int i =0;i<n;i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};