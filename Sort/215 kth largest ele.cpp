//215. Kth Largest Element in an Array
//Solved
//Medium
//Topics
//Companies
//Given an integer array nums and an integer k, return the kth largest element in the array.
//
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//Can you solve it without sorting?
//
// 
//
//Example 1:
//
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//Example 2:
//
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        //bubble sort
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        //selection sort
        
        // return nums[nums.size()-k];
        return nums[n-k];
    }
};
