//81. Search in Rotated Sorted Array II
//Solved
//Medium
//Topics
//Companies
//There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
//
//Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
//
//Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
//
//You must decrease the overall operation steps as much as possible.
//
// 
//
//Example 1:
//
//Input: nums = [2,5,6,0,0,1,2], target = 0
//Output: true
//Example 2:
//
//Input: nums = [2,5,6,0,0,1,2], target = 3
//Output: false


class Solution {
public:
    bool search(vector<int>& a, int target) {
        // return find(nums.begin(),nums.end(),target) != nums.end();  o(n)
        int low =0;
        int high = a.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid] == target) return true;
            if(a[low] == a[mid] && a[mid] == a[high]){
                low++,high--;
                continue;
            }
            if(a[low]<=a[mid]){
                if(a[low]<=target && target<=a[mid]) high = mid-1;
                else low = mid+1;
            }else{
                if(a[mid]<=target && target<=a[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};
