//896. Monotonic Array
//Solved
//Easy
//Topics
//Companies
//An array is monotonic if it is either monotone increasing or monotone decreasing.
//
//An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
//
//Given an integer array nums, return true if the given array is monotonic, or false otherwise.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,2,3]
//Output: true
//Example 2:
//
//Input: nums = [6,5,4,4]
//Output: true
//Example 3:
//
//Input: nums = [1,3,2]
//Output: false
// 
//
//Constraints:
//
//1 <= nums.length <= 105
//-105 <= nums[i] <= 105
class Solution {
public:
    bool isInc(vector<int>& nums, int l, int r) {
        if (l >= r) return true;
        int mid = l + (r - l) / 2;
        return isInc(nums, l, mid) && isInc(nums, mid + 1, r) && nums[mid] <= nums[mid + 1];
    }

    bool isDec(vector<int>& nums, int l, int r) {
        if (l >= r) return true; 
        int mid = l + (r - l) / 2;
        return isDec(nums, l, mid) && isDec(nums, mid + 1, r) && nums[mid] >= nums[mid + 1];
    }
    // bool isInc(vector<int>& nums, int l, int r) {
    //     for(int i=1;i<=r;i++){
    //         if(nums[i]<=nums[i-1]){
    //             continue;
    //         }else return false;
    //     }
    //     return true;

    // }
    //    bool isDec(vector<int>& nums, int l, int r) {
    //     for(int i=1;i<=r;i++){
    //         if(nums[i]>=nums[i-1]){
    //             continue;
    //         }else return false;
    //     }
    //     return true;

    // }
    bool isMonotonic(vector<int>& nums) {
        return isInc(nums, 0, nums.size() - 1) || isDec(nums, 0, nums.size() - 1);
    }
};

