//64. Minimum Path Sum
//Solved
//Medium
//Topics
//Companies
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//
// 
//
//Example 1:
//
//
//Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
//Output: 7
//Explanation: Because the path 1 ? 3 ? 1 ? 1 ? 1 minimizes the sum.
//Example 2:
//
//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12
// 
//
//Constraints:
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 200
//0 <= grid[i][j] <= 200

class Solution {
public:
    int func(int m,int n, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if( m== 0 && n==0) return grid[m][n];
        if(m<0 || n<0) return 1e9;
        if(dp[m][n] != -1) return dp[m][n];
        long long up = grid[m][n] + func(m-1,n,grid,dp);
        long long left = grid[m][n] + func(m,n-1,grid,dp);
        return dp[m][n] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return func(m-1,n-1,grid,dp);
        vector<int> prev(m,0);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i == 0 && j==0) dp[i][j] = grid[i][j];
        //         else{
        //             int up = grid[i][j];
        //             if(i>0) up+=dp[i-1][j];
        //             else up+=1e9;
        //             int left = grid[i][j];
        //             if(j>0) left+=dp[i][j-1];
        //             else left+= 1e9;
        //             dp[i][j] = min(left,up);
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
       for (int i = 0; i < m; i++) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    cur[j] = grid[i][j];
                } else {
                    int up = grid[i][j];
                    if (i > 0) up += prev[j];
                    else up += 1e9;

                    int left = grid[i][j];
                    if (j > 0) left += cur[j - 1];
                    else left += 1e9;

                    cur[j] = min(left, up);
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }

};
