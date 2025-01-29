// 684. Redundant Connection
// Solved
// Medium
// Topics
// Companies
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

//  class disJointSet{
//     public:
//     vector<int> parent;
//     vector<int> size;
//     disJointSet(int n){
//         parent.resize(n+1,0);
//         size.resize(n+1,0);
//         for(int i=0;i<n;i++){
//             parent[i]=i;
//             size[i]=1;
//         }
//     }
//     int findParent(int node){
//         if(node == parent[node]) return node;
//         return parent[node] = findParent(parent[node]);
//     }
//     void unionBySize(int u,int v){
//         int uParent = findParent(u);
//         int vParent = findParent(v);
//         if(uParent == vParent) return;
//         if(size[uParent]<size[vParent]){
//             parent[uParent] =vParent;
//             size[vParent] +=size[uParent];
//         }else{
//             parent[vParent] =uParent;
//             size[uParent] +=size[vParent];
//         }
//     }
// };
class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //DSU (Disjoint Set Union): We will maintain a parent and size array to keep track of connected components.
        vector<int> ans(2,0);
        disJointSet ds(n);
        for(auto it:edges){
            if(ds.findParent(it[0]) == ds.findParent(it[1])) return {it[0],it[1]};
        ds.unionBySize(it[0],it[1]);
        }
        return {};
    }
};