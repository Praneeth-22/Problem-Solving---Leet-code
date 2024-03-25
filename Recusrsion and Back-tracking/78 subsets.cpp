//78. Subsets
//Solved
//Medium
//Topics
//Companies
//Given an integer array nums of unique elements, return all possible 
//subsets
// (the power set).
//
//The solution set must not contain duplicate subsets. Return the solution in any order.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//Example 2:
//
//Input: nums = [0]
//Output: [[],[0]]

class Solution {
public:
void SubsetSum(vector<int>&arr,int index,vector<vector<int>>&res,vector<int>& temp){
	if(index == arr.size()){
		res.push_back(temp);
		return;
	}
    temp.push_back(arr[index]);
	SubsetSum(arr,index+1,res,temp);
    temp.pop_back();
	SubsetSum(arr,index+1,res,temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        	vector<vector<int>>res;
            vector<int> temp;
	SubsetSum(nums,0,res,temp);
	return res;
    }
};
