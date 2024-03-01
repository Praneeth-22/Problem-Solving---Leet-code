//2643. Row With Maximum Ones
//Solved
//Easy
//Topics
//Companies
//Hint
//Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
//
//In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
//
//Return an array containing the index of the row, and the number of ones in it.
//
// 
//
//Example 1:
//
//Input: mat = [[0,1],[1,0]]
//Output: [0,1]
//Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
//Example 2:
//
//Input: mat = [[0,0,0],[0,1,1]]
//Output: [1,2]
//Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].
//Example 3:
//
//Input: mat = [[0,0],[1,1],[0,0]]
//Output: [1,2]
//Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].


class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2,0);
        int cnt = 0,tempCnt=0;
        for(int i =0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1) tempCnt++;
            }
            if(tempCnt>cnt){
                ans[0] = i;
                ans[1] = tempCnt;
                cnt = tempCnt;
            }
            tempCnt=0;
        }
        return ans;
    }


    //  int lowerBound(vector<int>& arr, int n, int x) {
    //     int low = 0;
    //     int high = n - 1;
    //     int ans = -1; // Initialize ans to -1
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (arr[mid] == x) {
    //             ans = mid;
    //             low = mid + 1;
    //         } else if (arr[mid] < x) {
    //             low = mid + 1;
    //         } else {
    //             high = mid - 1;
    //         }
    //     }
    //     return ans;
    // }
    
    // vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    //     vector<int> ans(2, 0);
    //     int cnt = 0, tempCnt = 0;
    //     for (int i = 0; i < mat.size(); i++) {
    //         tempCnt = lowerBound(mat[i], mat[i].size(), 1);
    //         if (tempCnt> cnt) {
    //             ans[0] = i;
    //             ans[1] = tempCnt;
    //             cnt = tempCnt;
    //         }
    //         tempCnt = 0;
    //     }
    //     return ans;
    // }
};
