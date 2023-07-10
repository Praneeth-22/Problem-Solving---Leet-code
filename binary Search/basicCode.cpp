#include <bits/stdc++.h>
using namespace std;
void binarySearch(vector<int> &v,int el){
	int mid = (v.size()-1)/2;
	int low = 0;
	int high = v.size();
	while(low<=high){
		if(v[mid] == el){
			cout<<"found at :"<<mid;
			break;
		}
		if(el < v[mid]){
			high = mid--;
		}
		else{
			low =mid++;
		}
	}
}

int main(){
	vector<int> v ={2,3,4,7,10,45};
	int el = 2;
	binarySearch(v,el);
	return 0;
}
