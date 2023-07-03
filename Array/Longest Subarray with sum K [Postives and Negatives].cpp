#include<bits/stdc++.h>
using namespace std;
int maxLen (vector<int> nums,int k){
	int len = nums.size();
	int i=0,j=0;
	int sum = 0;
	int maxLen=0;
	int count =0;
	for(int i=0;i<len;i++){
		if(sum+nums[i] == k){
			count++;
			maxLen = max(count,maxLen);
			sum =0;
			count =0;
		}
		if(sum+nums[i] < k){
			count++;
			sum+=nums[i];
		
		}
		if(sum+nums[i] > k){
			sum-=nums[j];
			j++;

		}
	}
	return maxLen;
}
int main(){
	int arr[] = {-1,1,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::vector<int> v(arr, arr + size);
	int k = 1;
	cout<<maxLen(v,k);
	return 0;
}
