//547. Number of Provinces
//Solved
//Medium
//Topics
//Companies
//There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
//
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
//
//Return the total number of provinces.
//
// 
//
//Example 1:
//
//
//Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//Output: 2
//Example 2:
//
//
//Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
// 
//
//Constraints:
//
//1 <= n <= 200
//n == isConnected.length
//n == isConnected[i].length
//isConnected[i][j] is 1 or 0.
//isConnected[i][i] == 1
//isConnected[i][j] == isConnected[j][i]

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<int> adj[n];
//         vector<int> diff(n, -1);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i != j && isConnected[i][j] == 1)
//                     adj[i].push_back(j);
//             }
//         }
    
//     for (int i = 0; i < n; i++) {
//         for (int it : adj[i]) {
//             if (diff[it] != -1)
//                 diff[it] = i;
//         }
//     }
//     int cnt = 0;
//     for (int i = 0; i < n; i++) {
//         if (diff[i] == -1)
//             cnt++;
//     }
//     return cnt;
// }
// }
// ;
class Solution {
public:
    int findParent(vector<int>& diff, int node) {
        if (diff[node] == -1) return node;
        return findParent(diff, diff[node]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> diff(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    int parentI = findParent(diff, i);
                    int parentJ = findParent(diff, j);
                    if (parentI != parentJ) {
                        diff[parentJ] = parentI;
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(diff[i] == -1) cnt++;
        }
        
        return cnt;
    }
};

