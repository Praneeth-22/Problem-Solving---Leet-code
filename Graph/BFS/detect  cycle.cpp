#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int nodes;
		vector<vector<int>> adj;
		bool detect_cycle(int start ,vector<int>&visited){
			visited[start] = 1;
			queue<pair<int,int>> q; // <{node,parent}
			q.push({start,-1});
			while( q.empty() == false){
				int parent = q.front().second;
				int node = q.front().first;
				q.pop();
				for(auto adj_node : adj[node]){
					if(visited[adj_node]!=1){
						q.push({adj_node,node});
						visited[adj_node] = 1;
					}
					else if (visited[adj_node] == 1 && parent != adj_node){
						return true;
					}
				}
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
			vector<int> visited (nodes+1,0); // int visited[nodes] = {0}
			for(int i =1;i<=nodes;i++){
				if(visited[i] != 1){
					if(detect_cycle(i,visited)) return true;
				}
			}
			return false;
		}
		
	
};

int main(){
	Graph g;
	g.vertices(6);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,4);
	g.add_edge(3,5);
	g.add_edge(4,6);
	g.add_edge(5,6);
	cout<<g.is_cycle();
	return 0;
}
