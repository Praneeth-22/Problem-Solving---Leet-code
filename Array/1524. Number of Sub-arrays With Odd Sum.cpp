// 1524. Number of Sub-arrays With Odd Sum
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of integers arr, return the number of subarrays with an odd sum.

// Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: arr = [1,3,5]
// Output: 4
// Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
// All sub-arrays sum are [1,4,9,3,8,5].
// Odd sums are [1,9,3,5] so the answer is 4.
// Example 2:

// Input: arr = [2,4,6]
// Output: 0
// Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
// All sub-arrays sum are [2,6,12,4,10,6].
// All sub-arrays have even sum and the answer is 0.
// Example 3:

// Input: arr = [1,2,3,4,5,6,7]
// Output: 16
 

// Constraints:

// 1 <= arr.length <= 105
// 1 <= arr[i] <= 100

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //brute force O(n^2)
        // int oddSum = 0, curSum = 0;
        // const int MOD = 1e9 + 7;
        // int flag = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     curSum = arr[i];
        //     if (arr[i] % 2 == 1 && !flag) {
        //         oddSum++;
        //         flag = 1;
        //     }
        //     for (int j = i + 1; j < arr.size(); j++) {
        //         curSum += arr[j];
        //         if (curSum % 2 == 1)
        //             oddSum++;
        //     }
        //     flag = 0;
        // }
        // return oddSum%MOD;
        //prefix sum
         const int MOD = 1e9 + 7;
        int count = 0, prefixSum = 0;
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            // If current prefix sum is even, add the number of odd subarrays
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                // If current prefix sum is odd, add the number of even
                // subarrays
                count += evenCount;
                oddCount++;
            }

            count %= MOD;
        }

        return count;
    }
};