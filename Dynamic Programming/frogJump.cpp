#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&step,int n,vector<int>&dp){
	int right = INT_MAX;
	if(n==0 )return 0;
	if(dp[n]!= -1) return dp[n];
	int left = find(step,n-1,dp) + abs(step[n] - step[n-1]);
	if(n>1) int right = find(step,n-2,dp) + abs(step[n] - step[n-2]);
	dp[n] = min(left,right);
	return dp[n];
}
int frogJump(vector<int> &step,int n){
//	vector<int> dp(n+1,-1);
//	return find(step,n-1,dp);
//	vector<int> dp(n,0);
//	dp[0] = 0;
//	for(int i = 1;i<n;i++){
//		int left = dp[i-1] + abs(step[i] - step[i-1]);
//		int right = INT_MAX;
//		if(i > 1)right = dp[i-2]+ abs(step[i] - step[i-2]);
//		dp[i] = min(left,right);
//	}
//	return dp[n-1];
	int prev = 0,prev2=0;
	for(int i = 1;i<n;i++){
		int left = prev + abs(step[i] - step[i-1]);
		int right = INT_MAX;
		right = prev+ abs(step[i] - step[i-2]);
		int cur = min(left,right);
		prev2 = prev;
		prev = cur;
	}
	return prev;
}
int main(){
	vector<int> step = {10,20,10,20,40,30,20};
	cout<<frogJump(step,step.size());
	return 0;
}
