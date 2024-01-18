#include<bits/stdc++.h>
using namespace std;

class solution{
	public:
		vector<int> shortest_path(vector<vector<int>>&edges,int n,int m,int src){
			vector<int> adj[n];
			for(auto it: edges){
				adj[it[0]].push_back(it[1]);
				adj[it[1]].push_back(it[0]);
			}
			vector<int>dist(n,INT_MAX);
			queue<int>q;
			dist[src] = 0;
			q.push(src);
			while(!q.empty()){
				int node = q.front();
				q.pop();
				for(auto it: adj[node]){
					if(dist[node]+1 < dist[it]){
						dist[it] = 1+dist[node];
						q.push(it);
					}
				}
			}
			for(int i =0;i<n;i++){
				if(dist[i] == INT_MAX) dist[i] = -1;
			}
			return dist;
		}
};

int main(){
    solution sol;
    
    // Example edges
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    
    int n = 9; // Number of nodes
    int m = 10; // Number of edges
    int src = 0; // Source node
    
    vector<int> result = sol.shortest_path(edges, n, m, src);

    // Print the shortest distances from the source node
    cout << "Shortest distances from the source node " << src << " are: ";
    for(int distance : result){
        cout << distance << " ";
    }

    return 0;
}

