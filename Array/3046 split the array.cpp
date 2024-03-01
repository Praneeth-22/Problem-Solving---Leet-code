//3046. Split the Array
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that:
//
//nums1.length == nums2.length == nums.length / 2.
//nums1 should contain distinct elements.
//nums2 should also contain distinct elements.
//Return true if it is possible to split the array, and false otherwise.
//
// 
//
//Example 1:
//
//Input: nums = [1,1,2,2,3,4]
//Output: true
//Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and nums2 = [1,2,4].
//Example 2:
//
//Input: nums = [1,1,1,1]
//Output: false
//Explanation: The only possible way to split nums is nums1 = [1,1] and nums2 = [1,1]. Both nums1 and nums2 do not contain distinct elements. Therefore, we return false.
// 
//
//Constraints:
	
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n = nums.size()/2;
        // 607/all pass
        // set<int> s1;
        // set<int> s2;
        // for( int i:nums){
        //     if(s1.size()<=n && s1.find(i) == s1.end()) s1.insert(i);
        //     else if(s2.size()<=n && s2.find(i) == s2.end()) s2.insert(i);
        //     else return false;
        // }
        // return true;
        //
        unordered_map<int,int> mp;
        for( auto i : nums){
            mp[i]++;
            if(mp[i]>2) return false;
        }
        return true; 
    }
};
