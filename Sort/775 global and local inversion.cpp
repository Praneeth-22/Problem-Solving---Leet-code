//775. Global and Local Inversions
//Attempted
//Medium
//Topics
//Companies
//Hint
//You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].
//
//The number of global inversions is the number of the different pairs (i, j) where:
//
//0 <= i < j < n
//nums[i] > nums[j]
//The number of local inversions is the number of indices i where:
//
//0 <= i < n - 1
//nums[i] > nums[i + 1]
//Return true if the number of global inversions is equal to the number of local inversions.
//
// 
//
//Example 1:
//
//Input: nums = [1,0,2]
//Output: true
//Explanation: There is 1 global inversion and 1 local inversion.
//Example 2:
//
//Input: nums = [1,2,0]
//Output: false
//Explanation: There are 2 global inversions and 1 local inversion.
// 
//
//Constraints:
//
//n == nums.length
//1 <= n <= 105
//0 <= nums[i] < n
//All the integers of nums are unique.
//nums is a permutation of all the numbers in the range [0, n - 1].
//

#include <vector>
using namespace std;

class Solution {
public:
    int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int cnt = 0;
        int left = low; // starting index of left half
        int right = mid + 1; // starting index of right half

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                cnt += (mid - left + 1); // Increment count of inversions
            }
        }
        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);
        for (int i = low; i <= high; i++) arr[i] = temp[i - low];
        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid); // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high); // merging
        return cnt;
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        int globalInversions = mergeSort(nums, 0, nums.size() - 1);
        int localInversions = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                localInversions++;
        }
        return globalInversions == localInversions;
    }
};

