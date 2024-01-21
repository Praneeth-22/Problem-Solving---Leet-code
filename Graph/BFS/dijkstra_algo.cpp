#include<bits/stdc++.h>
using namespace std;

class Dij{
public:
    vector<int> dijkstra(int v, vector<vector<pair<int, int>>> adj, int s){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(v, 1e9);
        dist[s] = 0;
        pq.push({0, s});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adj_edge_wei = it.second;
                int adj_node = it.first;
                
                // relaxation
                if(dis + adj_edge_wei < dist[adj_node]){
                    dist[adj_node] = dis + adj_edge_wei;
                    pq.push({dist[adj_node], adj_node});
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



