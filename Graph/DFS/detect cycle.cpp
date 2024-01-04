#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int nodes;
		vector<vector<int>> adj;
		bool dfs(int node,int parent ,vector<int>&visited){
			//
			visited[node] = 1;
			for(auto adj_node : adj[node]){
				if(visited[adj_node] == 0){
					if(dfs(adj_node,node,visited) == true) return true;
				}
				else if (visited[adj_node] == 1 && parent != adj_node) return true;
			}
			return false;
		}	
	public:
		void vertices(int n){
			nodes = n;
			adj.resize(nodes);
		}
		void add_edge(int src,int dest){
			adj[src].push_back(dest);
		}
		bool is_cycle(){
			//
			vector<int> visited(nodes);
			for(int i=0;i<nodes;i++){
				if(visited[i] == 0){
					if(dfs(i,-1,visited)== true) return true;
				}
			}
			return false;
		}
		
	
};

int main(){
	Graph g;
	g.vertices(6);
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	g.add_edge(4,5);
	g.add_edge(3,5);
	cout<<g.is_cycle();
	return 0;
	//time complexity : O(v+ 2e) + O(n)
}
