

#include<bits/stdc++.h>
using namespace std;

class find_path{
	public:
		vector<int> shortest_path(int n,int m,vector<vector<int>>&edges){
			vector<pair<int,int>> adj[n+1]; // 0 indexed
			for(auto it : edges){
				adj[it[0]].push_back({it[1],it[2]}); // node , weight
				adj[it[1]].push_back({it[0],it[2]});
			}
			//
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			vector<int> dist(n+1,1e9);
			vector<int> parent(n+1);
			for(int i =1;i<=n;i++) parent[i] = i;
			dist[1] = 0;
			pq.push({0,1});
			while(!pq.empty()){
				auto it = pq.top();
				int node = it.second;
				int dist_of_node = it.first;
				pq.pop();
				for(auto it:adj[node]){
					int dist_to_node = it.second;
					int to_node = it.first;
					if(dist_to_node + dist_of_node < dist[to_node]){
						dist[to_node] = dist_to_node + dist_of_node;
						pq.push({dist_to_node + dist_of_node,to_node});
						parent[to_node] = node;
					}
				}
			}
			if(dist[n] == 1e9) return{-1};
			vector<int> path;
			int node = n;
			while(parent[node] != node){
				path.push_back(node);
				node = parent[node];
			}
			path.push_back(1);
			reverse(path.begin(),path.end());
			return path;
		}
};

int main() {
    int n = 8; // Set the number of nodes
    int m = 66; // Set the number of edges

    // Define the edges using predefined values
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 1},
        // Add more edges as needed
    };

    find_path sp;
    vector<int> result = sp.shortest_path(n, m, edges);

    if (result[0] == -1) {
        cout << "No valid path exists." << endl;
    } else {
        cout << "Shortest Path: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

