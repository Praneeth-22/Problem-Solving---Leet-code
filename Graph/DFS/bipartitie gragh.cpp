//Bipartite Graph : if we can color a graph in 2 different colors such that no 2 adj nodes should have same color. else return false.

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		bool dfs(int node,int col,vector<int> color,vector<int> adj[]){
			color[node] = col;
			for(auto it : adj[node]){
				if(color[it] == -1) if(dfs(it,!col,color,adj)==false) return false;
				else if ( color[it] == col) return false;
			}
			return true;
		}
		bool detect_bipartite(vector<int> adj[],int nodes){
			//dfs traversal
			vector<int> color(nodes,-1);
			for(int i=0;i<nodes;i++){
				if(color[i] == -1){
					if(dfs(i,0,color,adj) == false) return false;
				}
			}
			return true;
		}
};
int main() {
    Solution s;

    // Example usage with an undirected graph represented as an adjacency list
    int nodes = 4;
    vector<int> adj[nodes];

    // Adding edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);
	//has even edges
    if (s.detect_bipartite(adj, nodes)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
