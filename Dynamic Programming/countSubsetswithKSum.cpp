//Counts Subsets with Sum K
#include<bits/stdc++.h>
using namespace std;

//int rec(vector<int>&nums,int idx,int k){
//	if(k == 0) return 1;
//	if(idx == 0){
//		return (nums[0] ==k);
//	} 
//	
//	int ntPick = rec(nums,idx-1,k);
//	int pick =0;
//	if(nums[idx] <= k){
//		pick = rec(nums,idx-1,k-nums[idx]);
//	}
//	return pick +ntPick;
//}

int rec(vector<int>&nums,int idx,int k,vector<vector<int>>& dp){
	if(k == 0) return 1;
	if(idx == 0){
		return (nums[0] ==k);
	} 
	if(dp[idx][k]!= -1) return dp[idx][k];
	int ntPick = rec(nums,idx-1,k,dp);
	int pick =0;
	if(nums[idx] <= k){
		pick = rec(nums,idx-1,k-nums[idx],dp);
	}
	return dp[idx][k] = pick +ntPick;
}

int countSubsetswithKSum(vector<int>&nums,int k){
	int n = nums.size();
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
//	return rec(nums,n-1,k,dp);
	vector<int>prev(k+1,0),cur(k+1);
	prev[0]=cur[0]=1;
	if(nums[0] <=k) prev[nums[0]] = 1;
	for(int i =0;i<n;i++){
		for(int sum=0;sum<=k;sum++){
			int ntPick = prev[sum];
			int pick =0;
			if(nums[i]<=sum) pick = prev[sum-nums[i]];
			cur[sum] = ntPick+pick;
		}
		prev =cur;
	}
	return prev[k];
}
int main(){
	vector<int> arr = {1,2,3,4,2};
	cout<<countSubsetswithKSum(arr,7);
	return 0;
}
