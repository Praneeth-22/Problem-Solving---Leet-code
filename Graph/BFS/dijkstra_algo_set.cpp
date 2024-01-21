#include<bits/stdc++.h>
using namespace std;

class Dij{
public:
    vector<int> dijkstra(int v, vector<vector<pair<int, int>>> adj, int s){
        set<pair<int,int>> s;
        vector<int> dist(v,1e9);
        dist[s] = 0;
        st.insert({0,s});
        while(!s.empty()){
        	auto it = *(s.begin());
        	int dis = it.first;
        	int node =it.second;
			s.erase(it);
			for(auto it : adj[node]){
				int adj_node = it[0];
				int edg_wei = it[1];
				if(edg_wei + dis < dist[adj_node]){
				
					if(dist[adj_node] ! = 1e9){
						s.erase({dist[adj_node],adj_node});
					}
						dist[adj_node] = edg_wei + dis;
						s.insert({dist[adj_node],adj_node});
				}
			}	 
		}
		return dist;
    }
};

int main(){
    Dij d;
    vector<vector<pair<int, int>>> adj = {{
        {1, 4},
        {2, 2},
        {1, 5},
        {3, 1}
    }};
    
    vector<int> res = d.dijkstra(4, adj, 1);
    
    cout << "Shortest distances from source 0: ";
    for(auto it : res) cout << it << " ";
    
    return 0;
}



