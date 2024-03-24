#include<bits/stdc++.h>
using namespace std;

void SubsetSum(vector<int>&arr,int index,int sum,vector<int>&res){
	if(index == arr.size()){
		res.push_back(sum);
		return;
	}
	SubsetSum(arr,index+1,sum+arr[index],res);
	SubsetSum(arr,index+1,sum,res);
}
vector<int> findSubsetSum(vector<int>&arr){
	vector<int>res;
	SubsetSum(arr,0,0,res);
	sort(res.begin(),res.end());
	return res;
	
}
int main(){
	vector<int> arr = {3,1,2};
	vector<int> display = findSubsetSum(arr);
	for(auto it : display){
		cout<<it<<" ";
	}
	return 0;
}
