//1976. Number of Ways to Arrive at Destination
//Solved
//Medium
//Topics
//Companies
//Hint
//You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
//
//You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
//
//Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
//
// 
//
//Example 1:
//
//
//Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
//Output: 4
//Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
//The four ways to get there in 7 minutes are:
//- 0 ? 6
//- 0 ? 4 ? 6
//- 0 ? 1 ? 2 ? 5 ? 6
//- 0 ? 1 ? 3 ? 5 ? 6
//Example 2:
//
//Input: n = 2, roads = [[1,0,10]]
//Output: 1
//Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
// 
//
//Constraints:
//
//1 <= n <= 200
//n - 1 <= roads.length <= n * (n - 1) / 2
//roads[i].length == 3
//0 <= ui, vi <= n - 1
//1 <= timei <= 109
//ui != vi
//There is at most one road connecting any two intersections.
//You can reach any intersection from any other intersection.



#include <vector>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = 1e9 + 7;
        while (!pq.empty()) {
            auto i = pq.top();
            int node = i.second;
            long long dis = i.first;
            pq.pop();
            for (auto it : adj[node]) {
                int adj_node = it.first;
                int ed_wei = it.second;
                if (ed_wei + dis < dist[adj_node]) {
                    dist[adj_node] = ed_wei + dis;
                    pq.push({dis + ed_wei, adj_node});
                    ways[adj_node] = ways[node];
                } else if (ed_wei + dis == dist[adj_node]) {
                    ways[adj_node] = (ways[node] + ways[adj_node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

int main() {
    Solution sol;
    int n = 200;
    vector<vector<int>> roads = {{0,1,1000000000},{1,2,1000000000},{2,3,1000000000},{3,4,1000000000},{4,5,1000000000},{5,6,1000000000},{6,7,1000000000},{7,8,1000000000},{8,9,1000000000},{9,10,1000000000},{10,11,1000000000},{11,12,1000000000},{12,13,1000000000},{13,14,1000000000},{14,15,1000000000},{15,16,1000000000},{16,17,1000000000},{17,18,1000000000},{18,19,1000000000},{19,20,1000000000},{20,21,1000000000},{21,22,1000000000},{22,23,1000000000},{23,24,1000000000},{24,25,1000000000},{25,26,1000000000},{26,27,1000000000},{27,28,1000000000},{28,29,1000000000},{29,30,1000000000},{30,31,1000000000},{31,32,1000000000},{32,33,1000000000},{33,34,1000000000},{34,35,1000000000},{35,36,1000000000},{36,37,1000000000},{37,38,1000000000},{38,39,1000000000},{39,40,1000000000},{40,41,1000000000},{41,42,1000000000},{42,43,1000000000},{43,44,1000000000},{44,45,1000000000},{45,46,1000000000},{46,47,1000000000},{47,48,1000000000},{48,49,1000000000},{49,50,1000000000},{50,51,1000000000},{51,52,1000000000},{52,53,1000000000},{53,54,1000000000}};
    int result = sol.countPaths(n, roads);
    cout << result ;  // Display result
    return 0;
}

