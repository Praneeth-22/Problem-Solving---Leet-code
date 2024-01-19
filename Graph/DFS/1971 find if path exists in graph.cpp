//1971. Find if Path Exists in Graph
//Solved
//Easy
//Topics
//Companies
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
//
//You want to determine if there is a valid path that exists from vertex source to vertex destination.
//
//Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
//
// 
//
//Example 1:
//
//
//Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
//Output: true
//Explanation: There are two paths from vertex 0 to vertex 2:
//- 0 ? 1 ? 2
//- 0 ? 2
//Example 2:
//
//
//Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
//Output: false
//Explanation: There is no path from vertex 0 to vertex 5.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int start,int dest,vector<int> adj[],vector<int> &visited){
        visited[start] = 1;
        for(auto node : adj[start]){
            if(!visited[node]){
                if(dfs(node,dest,adj,visited) == true) return true;
            }
            if(node == dest) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // int n = edges.size();
        if(n ==1) return true;
        int m = edges[0].size();
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        return dfs(source,destination,adj,visited);
    }
};

int main() {
    Solution solution;

    // Example usage
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};
    int source = 0;
    int destination = 4;

    bool result = solution.validPath(n, edges, source, destination);

    if (result) {
        cout << "There is a valid path from source to destination." << endl;
    } else {
        cout << "There is no valid path from source to destination." << endl;
    }

    return 0;
}
