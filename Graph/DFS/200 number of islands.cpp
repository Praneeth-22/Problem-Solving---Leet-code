//200. Number of Islands
//Medium
//21.7K
//473
//Companies
//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
//
// 
//
//Example 1:
//
//Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//Output: 1
//Example 2:
//
//Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//Output: 3
// 
//
//Constraints:
//
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 300
//grid[i][j] is '0' or '1'.


#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void bfs_traversal(int row,int col, vector<vector<int>> & visited,vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            //traversal
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol <= 1;delcol++){
                    int nrow = i + delrow;
                    int ncol = j + delcol;
                    if(nrow >=0 && nrow < n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

    public:
        int numIslands(vector<vector<char>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int cnt=0;
            vector<vector<int>> visited(row,vector<int>(col,0)); // visited 2-d vector
            for(int i = 0;i< row;i++){
                for(int j=0;j<col;j++){
                    if( !visited[i][j] && grid[i][j] == '1'){
                        cnt++;
                        bfs_traversal(i,j,visited,grid);
                    }
                }
            }
            return cnt;
        }
        //O (n 2)
};
