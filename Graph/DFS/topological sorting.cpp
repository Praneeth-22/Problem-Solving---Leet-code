//Topological sorting
#include<bits/stdc++.h>
using namespace std;

class Sort{
	public:
		void dfs(int start,vector<int> adj[],vector<int> & visited,stack<int> &s){
			visited[start] = 1;
			for(auto node : adj[start]){
				if(!visited[node]) dfs(node,adj,visited,s);
			}
			s.push(start);
		}
		vector<int> topological_sort(int v,vector<int> adj[]){
			vector<int>visited(v,0);
			stack<int> s;
			for(int i=0;i<v;i++){
				if(!visited[i]){
					dfs(i,adj,visited,s);
				}
			}
			vector<int> ans;
			while(!s.empty()){
				ans.push_back(s.top());
				s.pop();
			}
			return ans;
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
