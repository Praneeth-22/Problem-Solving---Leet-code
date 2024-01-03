#include <bits/stdc++.h>
using namespace std;

class Graph{
	//class variables
	int v;
	map<int,list<int>> adj;
	map<int,bool> visited;
	//constructor
	public:
	void addEdge(int s,int d){
		adj[s].push_back(d);
	}
	void dfs(int v){
		visited[v] =true;
		cout<<v<<" ";
		//recursively
		for(auto it = adj[v].begin();it!=adj[v].end();it++){
			if(!visited[*it]) dfs(*it);
		}
		
	}
};

int main(){
	
	Graph g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,5);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	
	//DFS traversal
	g.dfs(0);
	return 0;
}
