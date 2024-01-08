#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
			void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &grid,int nei_row[],int nei_col[]){
				visited[row][col] = 1;
				int n = grid.size();
				int m = grid[0].size();
				for(int i=0;i<4;i++){
					int nrow = row + nei_row[i];
					int ncol = col +nei_col[i];
					if(nrow>=0 && nrow<n && ncol >=0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '0'){
						dfs(nrow,ncol,visited,grid,nei_row,nei_col);
					}
				}
			}
		vector<vector<char>> fill (int n, int m,vector<vector<char>> grid){
			//
			vector<vector<int>> visited (n,vector<int>(m,0));
			int nei_row[] = {-1,0,1,0};
			int nei_col[] = {0,1,0,-1};
			for(int j =0;j<m;j++){
				//first row check
				if(!visited[0][j] && grid[0][j]== '0'){
					dfs(0,j,visited,grid,nei_row,nei_col);
				}
				//last row check
				if(!visited[n-1][j] && grid[n-1][j] == '0'){
					dfs(n-1,j,visited,grid,nei_row,nei_col);
				}
			}
			for(int i=0;i<n;i++){
				//first col check
				if(!visited[i][0] && grid[i][0] == '0'){
					dfs(i,0,visited,grid,nei_row,nei_col);
				}
				if(!visited[i][m-1] && grid[i][m-1] == '0'){
					dfs(i,m-1,visited,grid,nei_row,nei_col);
				}
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(!visited[i][j] && grid[i][j] == '0'){
						grid[i][j] = 'X';
					}
				}
			}
			return grid;
			
		}
};
int main() {
    // Example usage
    Solution solution;
    int n = 3, m = 3;
    vector<vector<char>> grid = {{'X', 'X', 'X'}, {'X', '0', 'X'}, {'X', 'X', 'X'}};
    vector<vector<char>> result = solution.fill(n, m, grid);

    // Display the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
