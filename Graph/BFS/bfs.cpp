#include <bits/stdc++.h>
using namespace std;

class Graph{
	//class variables
	int v;
	vector<list<int>> adj;
	//constructor
	public:
	Graph(int nodes){
		v = nodes;
		//resize the adj list 
		adj.resize(v);
	}
	void addEdge(int s,int d){
		adj[s].push_back(d);
	}
	void bfs(int start){
		vector<int>visited;
		visited.resize(v,false);
		list<int> queue;
		visited[start] =true;
		queue.push_back(start);
		
		while(!queue.empty()){
			//top ele
			int node = queue.front();
			cout<<node<<" ";
			queue.pop_front();
			
			for(auto it:adj[node]){
				if(!visited[it]){
					visited[it] = true;
					queue.push_back(it);
				}
				
			}
		}
	}
};

int main(){
	
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,5);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	
	//BFS traversal
	g.bfs(0);
	return 0;
}
