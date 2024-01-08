//1020. Number of Enclaves
//Medium
//3.8K
//71
//Companies
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
//
// 
//
//Example 1:
//
//
//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//Example 2:
//
//
//Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//Output: 0
//Explanation: All 1s are either on the boundary or can reach the boundary.
// 
//
//Constraints:
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 500
//grid[i][j] is either 0 or 1.


#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<int>> &    grid,int nei_row[],int nei_col[]){
			visited[row][col] = 1;
			int n = grid.size();
			int m = grid[0].size();
			for(int i=0;i<4;i++){
				int nrow = row + nei_row[i];
				int ncol = col +nei_col[i];
				if(nrow>=0 && nrow<n && ncol >=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
					dfs(nrow,ncol,visited,grid,nei_row,nei_col);
				}
			}
		}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
            int m = grid[0].size();
        vector<vector<int>> visited (n,vector<int>(m,0));
			int nei_row[] = {-1,0,1,0};
			int nei_col[] = {0,1,0,-1};
			for(int j =0;j<m;j++){
				//first row check
				if(!visited[0][j] && grid[0][j]== 1){
					dfs(0,j,visited,grid,nei_row,nei_col);
				}
				//last row check
				if(!visited[n-1][j] && grid[n-1][j] == 1){
					dfs(n-1,j,visited,grid,nei_row,nei_col);
				}
			}
			for(int i=0;i<n;i++){
				//first col check
				if(!visited[i][0] && grid[i][0] == 1){
					dfs(i,0,visited,grid,nei_row,nei_col);
				}
				if(!visited[i][m-1] && grid[i][m-1] == 1){
					dfs(i,m-1,visited,grid,nei_row,nei_col);
				}
			}
            int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(!visited[i][j] && grid[i][j] == 1){
						cnt++;
					}
				}
			}
			return cnt;
    }
};

int main() {
    Solution solution;

    // Example grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 1, 1}
    };

    int result = solution.numEnclaves(grid);

    cout << "Number of Enclaves: " << result << endl;

    return 0;
}

