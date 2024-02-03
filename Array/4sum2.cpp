#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> sum(vector<int> v,int val){
	int n = v.size();
	vector<vector<int>>res;
	sort(v.begin(),v.end());
	for(int i =0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int rem = val - v[i] - v[j];
			int left = j+1;
			int right = n-1;
			while(left <= right){
				int sum2 = v[left] + v[right];
				if(sum2 < rem){
					left++;
				}else if (sum2 > rem) right--;
				else{
					res.push_back({v[i],v[j],v[left],v[right]});
					while(left<right && v[left+1]==v[left]) left++;
					while(left<right && v[right-1] == v[right]) right--;
					left++;
					right--;
				}
			}
			while(j+1 <n && v[j+1] == v[j]) j++;
		}
		while(i+1 < n && v[i]==v[i+1]) i++;
	}
	return res;
}
int main(){
	vector<int> v = {1,2,4,5,7,3,11,4,5,2,5,2,1,4,5};
	int val = 10;
	vector<vector<int>> res = sum(v,val);
	for(int i =0;i<res.size();i++){
		for(int j =0;j<res[0].size();j++){
			cout<< res[i][j]<<"\t";
		}
		cout<<"\n";
	}
	return 0;
}
