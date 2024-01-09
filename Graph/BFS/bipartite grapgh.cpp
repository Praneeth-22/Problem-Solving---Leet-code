//Bipartite Graph : if we can color a graph in 2 different colors such that no 2 adj nodes should have same color. else return false.

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		bool detect_bipartite(vector<int> adj[],int nodes){
			vector<int>color(nodes,-1);
			queue<int> q;
			color[0] = 0;
			q.push(0); // start node
			while(!q.empty()){
				int val = q.front();
				q.pop();
				for(auto it :adj[val]){
					if(color[it] == -1){
						color[it] = !color[val];
						q.push(it);
					}
					else if (color[it]== color[val]){
						return false;
					}
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
