#include<bits/stdc++.h>
using namespace std;
vector<int> Leader(int arr[],int n){
	int left = 0;
	int right = 1;
	vector<int> res;
	for(int i=0;i<n-1;i++){
		int j= i+1;
		int flag =0;
		int gt = arr[i];
		while(j<n){
			
			if(arr[j] > arr[i]){
				flag = false;
				break;
			}
			j++;}
		if(flag) res.push_back(arr[i]);
	}
	return res;
}
int main (){
	int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = Leader(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}
