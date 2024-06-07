//2367. Number of Arithmetic Triplets
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
//
//i < j < k,
//nums[j] - nums[i] == diff, and
//nums[k] - nums[j] == diff.
//Return the number of unique arithmetic triplets.
//
// 
//
//Example 1:
//
//Input: nums = [0,1,4,6,7,10], diff = 3
//Output: 2
//Explanation:
//(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
//(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
//Example 2:
//
//Input: nums = [4,5,6,7,8,9], diff = 2
//Output: 2
//Explanation:
//(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
//(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
// 
//
//Constraints:
//
//3 <= nums.length <= 200
//0 <= nums[i] <= 200
//1 <= diff <= 50
//nums is strictly increasing.
class Solution {
public:
bool binarySearch(vector<int> &nums,int k){
    int low =0,high = nums.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == k) return true;
        else if(nums[mid]<k) low=mid+1;
        else high =mid-1;
    }
    return false;
}
    int arithmeticTriplets(vector<int>& nums, int diff) {
        //using set
          int cnt=0;
        // unordered_set<int> st;
        // for (auto it:nums) st.insert(it);
        // for(int i=0;i<nums.size();i++){
        //     if(st.count(nums[i]+diff)&& st.count(nums[i]+(2*diff))) cnt++;
        // }
       
        //binary search
        for(int i=0;i<nums.size();i++){
            if(binarySearch(nums,nums[i]+diff) && binarySearch(nums,nums[i]+(2*diff))) cnt++;
        }
         return cnt;
    }
};
