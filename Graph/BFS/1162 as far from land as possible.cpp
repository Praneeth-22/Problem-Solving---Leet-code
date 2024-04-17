//1162. As Far from Land as Possible
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
//
// 
//
//Example 1:
//
//
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//
//
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//
//Constraints:
//
//n == grid.length
//n == grid[i].length
//1 <= n <= 100
//grid[i][j] is 0 or 1
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        int x[4] = { -1, 0, 1, 0 };
        int y[4] = { 0, -1, 0, 1 };
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            auto [xi, yi] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nei_x = xi + x[i];
                int nei_y = yi + y[i];
                if(nei_x >= 0 && nei_y >= 0 && nei_x < n && nei_y < n && dist[nei_x][nei_y] == -1) {
                    dist[nei_x][nei_y] = dist[xi][yi] + 1;
                    q.push({nei_x, nei_y});
                }
            }
        }
        int mx = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mx = max(mx, dist[i][j]);
            }
        }
        return mx <= 0 ? -1 : mx;
    }
};

