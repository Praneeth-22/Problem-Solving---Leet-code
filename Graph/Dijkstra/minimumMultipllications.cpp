//minimumMultiplications
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int miniMultiplications(vector<int>& arr,int start, int end){
			queue<pair<int,int>>q;
			q.push({start,0});
			vector<int>dist(100000,1e9);
			dist[start] = 0;
			int mod = 100000;
			while(!q.empty()){
				auto it = q.front();
				int node = it.first;
				int steps = it.second;
				q.pop();
				for(auto it:arr){
					int  num = (it *node) %mod;
					if(steps+1 < dist[num]){
						dist[num] = steps + 1;
						if(num == end)return steps + 1;
						q.push({num,steps+1});
					} 
				}
			}
			return -1;
		}
};

int main() {
    Solution solution;
    vector<int> arr = {2, 3, 5}; // Example multiplication factors
    int start = 2; // Example starting number
    int end = 40; // Example target number

    int result = solution.miniMultiplications(arr, start, end);

    if (result != -1) {
        cout << "Minimum multiplications needed: " << result << endl;
    } else {
        cout << "Target number cannot be reached." << endl;
    }

    return 0;
}
