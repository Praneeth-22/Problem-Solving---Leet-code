#include<bits/stdc++.h>
using namespace std;

class binaryMaze{
	public:
		int shortestPath(vector<vector<int>> &grid, pair<int,int> source,pair<int,int>dest){
			queue<pair<int,pair<int,int>>> q;
			int n = grid.size();
			int m = grid[0].size();
			vector<vector<int>> dist(n,vector<int>(m,1e9));
			dist[source.first][source.second] = 0;
			q.push({0,{source.first,source.second}});
			int nei_row[4] = {-1,0,1,0};
			int nei_col[4] = {0,-1,0,1};
			while(!q.empty()){
				auto it = q.front();
				q.pop();
				int dist_value = it.first;
				int row = it.second.first;
				int col = it.second.second;
				for(int i =0;i<4;i++){
					int nrow = row + nei_row[i];
					int ncol = col + nei_col[i];
					
					if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == 1 && dist_value + 1 <dist[nrow][ncol]){
						 dist[nrow][col] = dist_value+1;
						 if(nrow == dest.first && ncol == dest.second) return (dist_value+1);
						 q.push({dist_value+1,{nrow,ncol}});
					}
				}
			}
			return -1;
		}
};
int main() {
    binaryMaze bm;

    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    pair<int, int> source = {0, 0};
    pair<int, int> dest = {4, 4};

    int result = bm.shortestPath(grid, source, dest);

    if (result != -1) {
        cout << "Shortest Path Length: " << result << endl;
    } else {
        cout << "Destination is not reachable." << endl;
    }

    return 0;
}
