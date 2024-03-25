//90. Subsets II
//Solved
//Medium
//Topics
//Companies
//Given an integer array nums that may contain duplicates, return all possible 
//subsets
// (the power set).
//
//The solution set must not contain duplicate subsets. Return the solution in any order.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//
//Input: nums = [0]
//Output: [[],[0]]

class Solution {
public:
    void SubsetSum(vector<int>& arr, int index, vector<vector<int>>& res,
                   vector<int>& temp) {
        res.push_back(temp);
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            temp.push_back(arr[i]);
            SubsetSum(arr, i + 1, res, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        SubsetSum(nums, 0, res, temp);
        return res;
    }
};
