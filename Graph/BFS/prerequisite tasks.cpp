//Prerequisite tasks

#include<bits/stdc++.h>
using namespace std;

class task{
	public:
		bool is_possible(int n,vector<pair<int,int>> & preq){
			vector<int> adj[n];
			for(auto it: preq){
				adj[it.first].push_back(it.second);
			}
			vector<int> in_deg(n,0);
			for(int i=0;i<n;i++){
				for(auto it: adj[i]){
					in_deg[it]++;
				}
			}
			queue<int>q;
			for(int i =0;i<n;i++){
				if (in_deg[i]==0)q.push(i);
			}
			vector<int>top_order;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				top_order.push_back(node);
				for(auto it:adj[node]){
					in_deg[it]--;
					if(in_deg[it]==0)q.push(it);
				}
			}
			return top_order.size()==n;
		}
};

int main() {
    int n = 4;
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    task obj;
    bool possible = obj.is_possible(n, prerequisites);

    cout << (possible ? "Possible" : "Not possible") << endl;

    return 0;
}
