//Topological sorting - bfs ( kahn's algorithm)
#include<bits/stdc++.h>
using namespace std;
//DAG
//topological sorting is linear ordering of the vertices such that if there is an edge between u and v, u appears before
//v in the ordering.
class Sort{
	public:
		vector<int> topological_sort(int v,vector<int> adj[]){
			vector<int> in_deg(v,0);
			for(int i=0;i<v;i++){
				for(auto it:adj[i]){
						in_deg[it]++;
				}
			}
			queue<int> q;
			for(int i=0;i<v;i++){
				if(in_deg[i] ==0 ) q.push(i);
			}
			vector<int>order;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				order.push_back(node);
				for(auto it :adj[node]){
					in_deg[it]--;
					if(in_deg[it] == 0) q.push(it);
				}
				
			}
			return order;

		}
};
int main(){
	int nodes =6;
	vector<int> adj[nodes];
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(1);
	adj[4].push_back(1);
	adj[4].push_back(0);
	
	Sort s;
	vector<int>res = s.topological_sort(6,adj);
	
	for(auto i:res){
		cout<<i<<" -> ";
	}
	return 0;
}
