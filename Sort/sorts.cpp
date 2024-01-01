#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[5] = {13,555,22,17,6};
//	for(int i=1;i<5;i++){
//		int j =i-1;
//		int val = arr[i];
//		while(j>0  ){
//			if(arr[j] > val){
//				int temp = arr[j];
//				arr[j] = val;
//				val = temp;
//			}
//			arr[i] =val;
//			j--;
//		}
//	}
	for(int i=1;i<5;i++){
		int j =i;
//		int val = arr[i];
		while(j>0  ){
			if(arr[j-1] > arr[j]){
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		
			j--;
		}
	}
	for(int i=0;i<5;i++) cout <<arr[i]<<" ";
	return 0;
}
