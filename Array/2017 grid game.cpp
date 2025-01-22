// 2017. Grid Game
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

// The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

 

// Example 1:


// Input: grid = [[2,5,4],[1,5,1]]
// Output: 4
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 0 + 4 + 0 = 4 points.
// Example 2:


// Input: grid = [[3,3,1],[8,5,2]]
// Output: 4
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 3 + 1 + 0 = 4 points.
// Example 3:


// Input: grid = [[1,3,1,15],[1,3,3,1]]
// Output: 7
// Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
// The cells visited by the first robot are set to 0.
// The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
 

// Constraints:

// grid.length == 2
// n == grid[r].length
// 1 <= n <= 5 * 104
// 1 <= grid[r][c] <= 105


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // first robot maximize its points and second robot wants its points
        // maximize.
        //  prefix sum for the first row and postfix sum for the second row
        int row = 2, col = grid[0].size();
        if(col==1) return 0;
        vector<vector<long long>> sum(row, vector<long long>(col));
        sum[0][0] = grid[0][0];
        sum[1][col - 1] = grid[1][col - 1];
        //prefix sum
        for (int i = 1; i < col; i++)
            sum[0][i] = grid[0][i] + sum[0][i - 1];
            //postfix sum
        for (int i = col-2; i >=0; i--)
            sum[1][i] = grid[1][i] + sum[1][i + 1];
        
        long long ans=LLONG_MAX;
        for(int i=0;i<col;i++){
            long long pre_robo_2,post_robo_2,diff;
            pre_robo_2 = sum[0][col-1] - sum[0][i];
            post_robo_2 = sum[1][0] -   sum[1][i];
            diff = max(pre_robo_2,post_robo_2);
            ans = min(ans,diff);
        }
        return ans;
    }
};