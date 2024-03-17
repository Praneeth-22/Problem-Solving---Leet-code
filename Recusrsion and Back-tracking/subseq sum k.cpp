#include<bits/stdc++.h>
using namespace std;

void findSum(int index,vector<int> temp,int tempSum,int sum,int arr[],int n){
	if(index == n){
		if(tempSum == sum){
			for(auto it:temp) cout<<it<<" ";
			cout<<endl;
		}
		return ;
	}
	temp.push_back(arr[index]);
	tempSum+= arr[index];
	findSum(index+1,temp,tempSum,sum,arr,n);
	tempSum-=arr[index];
	temp.pop_back();
	findSum(index+1,temp,tempSum,sum,arr,n);
}
int main(){
	int arr[] = {1,2,1};
	int n = 3;
	int sum =2;
	vector<int> temp;
	findSum(0,temp,0,sum,arr,n);
	return 0;
}
