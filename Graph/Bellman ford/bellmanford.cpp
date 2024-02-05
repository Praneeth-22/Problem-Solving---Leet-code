//Bellman ford algo - V x E

#include<bits/stdc++.h>
using namespace std;

class solution{
	public:
		vector<int> bellmon_ford(int v,vector<vector<int>>& edges,int s){
			vector<int> dist(v,1e8);
			dist[s] = 0;
			for(int i=0;i<v-1;i++){
				for(auto it:edges){
					int u = it[0];
					int v= it[1];
					int wt = it[2];
					if(dist[u]!=1e8 && dist[u]+wt < dist[v]) dist[v] = dist[u]+wt;
				}
			}
			for(auto it: edges){
				int u = it[0];
					int v= it[1];
					int wt = it[2];
					if(dist[u]!=1e8 && dist[u]+wt < dist[v]) return{-1};
			}
			return dist;
		}
};

int main(){
    solution s;

    int v = 5; // Set the number of vertices
    vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 3}, {0, 3, 5}, {3, 4, 1}, {2, 4, 7}}; // Example edges and weights
    int source = 0; // Set the source vertex

    vector<int> result = s.bellmon_ford(v, edges, source);

    if(result[0] == -1){
        cout << "Negative cycle detected. Graph contains a negative-weight cycle.";
    } else {
        cout << "Shortest distances from source " << source << " are:\n";
        for(int i = 0; i < v; ++i){
            cout << "To vertex " << i << ": " << result[i] << "\n";
        }
    }

    return 0;
}

