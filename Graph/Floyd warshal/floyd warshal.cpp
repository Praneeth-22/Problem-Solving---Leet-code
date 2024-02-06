#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		void floyd_algo(vector<vector<int>>&matrix){
			int n= matrix.size();
			for(int k=0;k<n;k++){
				for(int i=0;i<n;i++){
					for(int j =0;j<n;j++){
						matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
					}
				}
			}
		bool hasNegativeCycle = false;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        if(i != j && matrix[i][j] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }
    if(hasNegativeCycle) break;
}

if(hasNegativeCycle) {
    cout << "contains -ve cycle\n";
} else {
    cout << "doesn't contain -ve cycle\n";
}
		}
};
int main(){
    // Sample adjacency matrix
    vector<vector<int>> matrix = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    Solution solution;
    solution.floyd_algo(matrix);

    return 0;
}

