#include<bits/stdc++.h>
using namespace std;

void find4sum(vector <int>v,int l,int target){
	vector<vector<int>> res;
	//brute force
	for(int i=0;i<l;i++){
		for(int j=i+1;j<l;j++){
			for(int k=j+1;k<l;k++){
				for(int p=k+1;p<l;p++){
					if (v[i]+v[j]+v[k]+v[p] == target){
						cout<<"values : "<<v[i]<<"\t"<<v[j]<<"\t"<<v[k]<<"\t"<<v[p]<<"\n";
						
					}
				}
			}
		}
	}
	//better
	
}
int main(){
	vector<int>v = {1,0,-1,0,-2,2};
//	int l = sizeof(arr)/sizeof(int);
	find4sum(v,v.size(),0);
	return 0;
}
