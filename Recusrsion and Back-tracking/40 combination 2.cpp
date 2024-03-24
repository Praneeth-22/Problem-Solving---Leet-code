//40. Combination Sum II
//Solved
//Medium
//Topics
//Companies
//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note: The solution set must not contain duplicate combinations.
//
// 
//
//Example 1:
//
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//Example 2:
//
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//
//Constraints:
//
//1 <= candidates.length <= 100
//1 <= candidates[i] <= 50
//1 <= target <= 30

class Solution {
public:
    void findCmb(vector<int>&candidates,vector<int>& temp,vector<vector<int>>& res,int index,int target){

        if(target == 0 ){
            res.push_back(temp);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            findCmb(candidates,temp,res,i+1,target-candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        findCmb(candidates,temp,res,0,target);
        return res;
    }
};
