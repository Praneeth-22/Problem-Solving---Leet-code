// 542 neares 1

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        //
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps; // dist of itself
            int row_nei[] = {-1, 0, 1, 0};
            int col_nei[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = row + row_nei[i];
                int ncol = col + col_nei[i];
                //
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                    // dist[nrow][ncol] = min(dist[nrow][ncol], steps + 1);
                }
            }
        }

        return dist;
    }
};

int main() {
    // Example usage
    vector<vector<int>> inputMatrix = {
        {0, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 1}
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

