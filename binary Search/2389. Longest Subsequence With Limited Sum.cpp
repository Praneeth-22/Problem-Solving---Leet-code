//2389. Longest Subsequence With Limited Sum
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given an integer array nums of length n, and an integer array queries of length m.
//
//Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].
//
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//
// 
//
//Example 1:
//
//Input: nums = [4,5,2,1], queries = [3,10,21]
//Output: [2,3,4]
//Explanation: We answer the queries as follows:
//- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
//- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
//- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
//Example 2:
//
//Input: nums = [2,3,4,5], queries = [1]
//Output: [0]
//Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>sum(n,0);
        int temp_sum=0;
        sum[0] = nums[0];
        for(int i=1;i<n;i++){
            temp_sum = sum[i-1];
            sum[i] = temp_sum+nums[i];
        }
        int m = queries.size();
        vector<int> res(m);
        for(int i=0;i<m;i++){
            int l=0,r=n-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(sum[mid] <=queries[i]){
                    l= mid+1;
                }else if(sum[mid] >queries[i]) r= mid-1;
            }
            res[i] = r+1;
        }
        return res;
    }
};
