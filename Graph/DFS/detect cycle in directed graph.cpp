// detecting cycle in directed graph

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		bool dfs(int start,vector<int>&visited,vector<int>&visited_path,vector<int> adj[]){
			visited[start] = 1;
			visited_path[start] = 1;
			for(auto node:adj[start]){
				if(!visited[node]){
					if(dfs(node,visited,visited_path,adj)== true) return true;
				}
				else if(visited_path[node]){
					return true;
				}
				
			}
			visited_path[start] =0;
			return false;	 	
		}
		bool is_cyclic(int v,vector<int> adj[]){
			vector<int> visited(v,0);
			vector<int> visited_path(v,0);
			for(int i=0;i<v;i++){
				if(!visited[i])
				if(dfs(i,visited,visited_path,adj) == true) return true;
			}
			return false;
		}
};

int main() {
    // Assuming a directed graph with 4 vertices and edges (0->1, 1->2, 2->3, 3->1)
    int v = 4;
    vector<int> adj[v];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    if (obj.is_cyclic(v, adj)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
