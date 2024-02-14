//463. Island Perimeter
//Easy
//Topics
//Companies
//You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
//
//Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//
//The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
// 
//
//Example 1:
//
//
//Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
//Output: 16
//Explanation: The perimeter is the 16 yellow stripes in the image above.
//Example 2:
//
//Input: grid = [[1]]
//Output: 4
//Example 3:
//
//Input: grid = [[1,0]]
//Output: 4
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int pmt = 0;
        int nei_row[4] = {-1, 0, 1, 0};
        int nei_col[4] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int waterCnt = 0;
                    for (int it = 0; it < 4; it++) {
                        int nrow = i + nei_row[it];
                        int ncol = j + nei_col[it];
                        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m ||
                            grid[nrow][ncol] == 0) {
                            waterCnt++;
                        }
                    }
                    pmt += waterCnt;
                }
            }
        }
        return pmt;
    }
};

int main(){
	Solution s;
	vector<vector<int>>grid = {
	{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}
	};
	
	cout<< s.islandPerimeter(grid);
//[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
	return 0;
}
