//2610. Convert an Array Into a 2D Array With Conditions
//Medium
//1.4K
//65
//Companies
//You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
//
//The 2D array should contain only the elements of the array nums.
//Each row in the 2D array contains distinct integers.
//The number of rows in the 2D array should be minimal.
//Return the resulting array. If there are multiple answers, return any of them.
//
//Note that the 2D array can have a different number of elements on each row.
//
// 
//
//Example 1:
//
//Input: nums = [1,3,4,1,2,3,1]
//Output: [[1,3,4,2],[1,3],[1]]
//Explanation: We can create a 2D array that contains the following rows:
//- 1,3,4,2
//- 1,3
//- 1
//All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
//It can be shown that we cannot have less than 3 rows in a valid array.
//Example 2:
//
//Input: nums = [1,2,3,4]
//Output: [[4,3,2,1]]
//Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
// 
//
//Constraints:
//
//1 <= nums.length <= 200
//1 <= nums[i] <= nums.length



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        int max_occ =0;
        for(auto i : nums){
            m[i]++;
            max_occ = max(max_occ,m[i]);
        }
        vector<vector<int>> res(max_occ);
        for(auto i: m){
            int val = i.first;
            int freq = i.second;
            for(int i=0;i<freq;i++){
                res[i].push_back(val);
            }
        }
        return res;
    }
};

int main() {
    // Example usage:
    Solution solution;
    
    std::vector<int> nums = {4, 2, 4, 5, 1, 2, 2, 8, 4, 6, 8, 8};
    std::vector<std::vector<int>> result = solution.findMatrix(nums);

    // Displaying the result
    std::cout << "Resulting Matrix:\n";
    for (const auto& row : result) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
