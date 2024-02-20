#include<bits/stdc++.h>
using namespace std;
//Prim's algorithm

class Solution{
	public:
		int spanning_tree(int v, vector<vector<pair<int, int>>>adj[]){
			priority_queue<
				pair<int,int>,
				vector<pair<int,int>>,
				greater<pair<int,int>>> pq;
			vector<int> visited(v,0);
			int sum=0;
			visited[0] = 1;
			//{wt,node}
			pq.push({0,0});
			while(!pq.empty()){
				auto it = pq.top();
				pq.pop();
				int node = it.second;
				int wt = it.first;
				if(visited[node]) continue;
				visited[node] =1;
				sum+=wt;
				for(auto it:adj[node]){
					int adjNode = it[0];
					int edW = it[1];
					if(!visited[adjNode]) pq.push({edW,adjNode});
				}
			}
			return sum;
		}
};
int main(){
    // Adjacency list representation of a graph
    vector<vector<pair<int, int>>> adj = {
        { {1, 2}, {3, 3} },  // edges from node 0 to node 1 with weight 2 and to node 3 with weight 3
        { {0, 2}, {2, 3} },  // edges from node 1 to node 0 with weight 2 and to node 2 with weight 3
        { {1, 3}, {3, 2} },  // edges from node 2 to node 1 with weight 3 and to node 3 with weight 2
        { {0, 3}, {2, 2} }   // edges from node 3 to node 0 with weight 3 and to node 2 with weight 2
    };
    int V = adj.size();  // Number of vertices in the graph
    Solution s;
    cout << s.spanning_tree(V, adj) << endl;
    return 0;
}
//O(E*logE)
