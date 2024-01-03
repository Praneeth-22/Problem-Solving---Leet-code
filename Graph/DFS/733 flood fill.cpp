//733. Flood Fill
//Easy
//8.1K
//808
//Companies
//An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
//
//You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
//
//To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
//
//Return the modified image after performing the flood fill.
//
// 
//
//Example 1:
//
//
//Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
//Output: [[2,2,2],[2,2,0],[2,0,1]]
//Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
//Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
//Example 2:
//
//Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
//Output: [[0,0,0],[0,0,0]]
//Explanation: The starting pixel is already colored 0, so no changes are made to the image.
// 
//
//Constraints:
//
//m == image.length
//n == image[i].length
//1 <= m, n <= 50
//0 <= image[i][j], color < 216
//0 <= sr < m
//0 <= sc < n




#include <bits/stdc++.h>
class Solution {
    private:
    void dfs_traversal(vector<vector<int>> &image,vector<vector<int>> &res, int sr, int sc,int color,int nei_row[],int nei_col[],int init_color){
        int n = image.size();
        int m = image[0].size();
        res[sr][sc] =color;
        for(int i=0;i<4;i++){
            int nrow = sr + nei_row[i];
            int ncol = sc + nei_col[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == init_color && res[nrow][ncol] != color){
                dfs_traversal(image,res,nrow,ncol,color,nei_row,nei_col,init_color);
            }
        }
    }
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            //implementing using dfs
            int init_color = image[sr][sc];
            vector<vector<int>> res = image;
            int nei_row[] = {-1,0,1,0};
            int nei_col[] = {0,1,0,-1};
            dfs_traversal(image,res,sr,sc,color,nei_row,nei_col,init_color);
            return res;
            //time - O(n x m)
        }
};
