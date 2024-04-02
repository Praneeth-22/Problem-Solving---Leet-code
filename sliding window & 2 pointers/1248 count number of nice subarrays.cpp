//1248. Count Number of Nice Subarrays
//Medium
//Topics
//Companies
//Hint
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
//
//Return the number of nice sub-arrays.
//
// 
//
//Example 1:
//
//Input: nums = [1,1,2,1,1], k = 3
//Output: 2
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
//Example 2:
//
//Input: nums = [2,4,6], k = 1
//Output: 0
//Explanation: There is no odd numbers in the array.
//Example 3:
//
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//Output: 16

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0,right = k-1;
        int n = nums.size();
        int cnt=0;
        while(right<n){
            int temp=0;
            for(int i=left;i<right;i++){
                if(nums[i]%2 !=0) temp++;
            }
            right++;
        }
    }
};
