//802. Find Eventual Safe States
//Solved
//Medium
//Topics
//Companies
//There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
//
//A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
//
//Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
//
// 
//
//Example 1:
//
//Illustration of graph
//Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
//Output: [2,4,5,6]
//Explanation: The given graph is shown above.
//Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
//Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
//Example 2:
//
//Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
//Output: [4]
//Explanation:
//Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
// 
//
//Constraints:
//
//n == graph.length
//1 <= n <= 104
//0 <= graph[i].length <= n
//0 <= graph[i][j] <= n - 1
//graph[i] is sorted in a strictly increasing order.
//The graph may contain self-loops.
//The number of edges in the graph will be in the range [1, 4 * 104].


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int start,vector<int> adj[],vector<int> &visited,vector<int> &path_visit,vector<int> &check){
        visited[start] = 1;
        path_visit[start] = 1;
        check[start]=0;
        for(auto node:adj[start]){
            if(visited[node] == 0 ){
                if(dfs(node,adj,visited,path_visit,check)== true) {
                    check[node] = 0;
                    return true;}
            }
            else if (path_visit[node] == 1){ 
                check[node] = 0;
                return true;}
        }
        check[start] = 1;
        path_visit[start] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()]; //adjacent list of given graph
        vector<int> safenodes; //result safe node
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>visited(graph.size(),0);
        vector<int>path_visit(graph.size(),0);
        vector<int>check(graph.size(),0);

        int n = graph.size();
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,path_visit,check);
            }
        }
        for(int i=0;i<n;i++)
        if(check[i] == 1) safenodes.push_back(i);
        return safenodes;
    }
};

        // Print the adjacency list
        // for (int i = 0; i < graph.size(); i++) {
        //     cout << "Adjacency list for vertex " << i << ": ";
        //     for (int j = 0; j < adj[i].size(); j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution obj;
    vector<int> result = obj.eventualSafeNodes(graph);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
