// 2658. Maximum Number of Fish in a Grid
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

// Example 1:


// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
// Example 2:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// Output: 1
// Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

// Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10
class Solution {
public:
    int dfs(vector<vector<int>> grid, int row, int col, int n, int m,
            vector<vector<int>> &visited) {

        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 ||
            visited[row][col] == 1)
            return 0;
        int sum = grid[row][col];
        visited[row][col] = 1;
        sum += dfs(grid, row + 1, col, n, m, visited);
        sum += dfs(grid, row, col + 1, n, m, visited);
        sum += dfs(grid, row, col - 1, n, m, visited);
        sum += dfs(grid, row - 1, col, n, m, visited);
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && visited[i][j] == 0) {
                    int currAns = dfs(grid, i, j, n, m, visited);
                    ans = max(currAns, ans);
                }
            }
        }
        return ans;
    }
};