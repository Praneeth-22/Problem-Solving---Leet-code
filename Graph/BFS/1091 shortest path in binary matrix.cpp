//1091. Shortest Path in Binary Matrix
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//
//All the visited cells of the path are 0.
//All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
//
// 
//
//Example 1:
//
//
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//
//
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
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
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        if(n-1 == 0 )return 1;
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        vector<int> r = {0, 1, -1, 0, 1, -1, 1, -1};
        vector<int> c = {1, 0, 0, -1, 1, 1, -1, -1};

        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if (row == n - 1 && col == n - 1) 
                    return cnt + 1;

                for (int i = 0; i < 8; i++) {
                    int x = row + r[i];
                    int y = col + c[i];

                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }

            cnt++;
        }

        return -1; 
    }
};

