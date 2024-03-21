#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, -1)); // Initialize distances to -1
        queue<pair<int, int>> q;

        // Push all cells with value 1 into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
        	auto ele = q.front();
            int row = ele.first;
            int col = ele.second;
            q.pop();

            int row_nei[] = {-1, 0, 1, 0};
            int col_nei[] = {0, 1, 0, -1};
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + row_nei[i];
                int ncol = col + col_nei[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && dist[nrow][ncol] == -1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};

int main() {
    // Example usage
    vector<vector<int>> inputMatrix = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1}
    };

    Solution solution;
    vector<vector<int>> result = solution.updateMatrix(inputMatrix);

    // Display the result
    for (const auto& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}

