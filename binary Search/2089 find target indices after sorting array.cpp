//2089. Find Target Indices After Sorting Array
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given a 0-indexed integer array nums and a target element target.
//
//A target index is an index i such that nums[i] == target.
//
//Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,5,2,3], target = 2
//Output: [1,2]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The indices where nums[i] == 2 are 1 and 2.
//Example 2:
//
//Input: nums = [1,2,5,2,3], target = 3
//Output: [3]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The index where nums[i] == 3 is 3.
//Example 3:
//
//Input: nums = [1,2,5,2,3], target = 5
//Output: [4]
//Explanation: After sorting, nums is [1,2,2,3,5].
//The index where nums[i] == 5 is 4.
// 
//
//Constraints:
//
//1 <= nums.length <= 100
//1 <= nums[i], target <= 100

#include <vector>
using namespace std;

class Solution {
public:
    void mergeSort(int l, int r, vector<int>& nums) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, r, nums);
        merge(l, r, mid, nums);
    }

    void merge(int l, int r, int mid, vector<int>& nums) {
        vector<int> combine(r - l + 1);
        int left = l;
        int right = mid + 1;
        int ind = 0;

        while (left <= mid && right <= r) {
            if (nums[left] <= nums[right]) {
                combine[ind++] = nums[left++];
            } else {
                combine[ind++] = nums[right++];
            }
        }

        while (left <= mid) {
            combine[ind++] = nums[left++];
        }

        while (right <= r) {
            combine[ind++] = nums[right++];
        }

        for (int i = l; i <= r; i++) {
            nums[i] = combine[i - l];
        }
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        mergeSort(0, n - 1, nums);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

