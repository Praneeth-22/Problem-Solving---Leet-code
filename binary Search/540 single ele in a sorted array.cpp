//540. Single Element in a Sorted Array
//Solved
//Medium
//Topics
//Companies
//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
//
//Return the single element that appears only once.
//
//Your solution must run in O(log n) time and O(1) space.
//
// 
//
//Example 1:
//
//Input: nums = [1,1,2,3,3,4,4,8,8]
//Output: 2
//Example 2:
//
//Input: nums = [3,3,7,7,10,11,11]
//Output: 10

class Solution {
public:
    // (ev,odd) , (ev,odd) , ele , (odd,ev),(odd,ev)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if( n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low = 1;
        int high =n-2;
        while(low<=high){
            long long int kz= low+high;
            int mid = kz/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2 == 1 && nums[mid] == nums[mid-1] ||mid%2==0 && nums[mid] == nums[mid+1]) low = mid+1;
            else high = mid -1;
        }
        return -1;
    }
};