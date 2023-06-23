/*
Find Second Smallest and Second Largest Element in an array
Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples:

Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
	Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
	Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.
*/
#include <bits/stdc++.h>
using namespace std;
#define size 100

void find(int a[],int len){
	int min = INT_MAX;
	int sec_min = INT_MAX;
	int max = INT_MIN;
	int sec_max = INT_MIN;
//	if(len<2) return -1;
	if(len == 2){
		if(a[0] < a[1]){
			sec_min = a[1];
			sec_max = a[0];
		}
	}
	else{
	
	for(int i=0;i<len;i++){
		if(a[i] < min){
			sec_min = min;
			min = a[i];
		}
		else if(a[i] < sec_min && a[i] != min){
			sec_min = a[i];
		}
	}
		for(int i=0;i<len;i++){
		if(a[i]> max){
			sec_max = max;
			max = a[i];
		}
		else if(a[i] > sec_max && a[i]!=max) sec_max = a[i];
	}
}
//	if
	cout <<"sec min :"<<sec_min<<"sec max : "<<sec_max<<endl;
}
int main(){
	int arr [size];
	int len;
	cout<<"len: - ";
	cin>>len;
	cout<< "enter array values:\t";
	for(int i=0;i<len;i++){
		cin>>arr[i];
	}
	find(arr,len);
	return 0;
}

/*
	int min = INT_MAX;
	int max = INT_MIN;
	for(int i=0;i<len;i++){
		if(min > arr[i] ){
			min = arr[i];
		}
		if(max <arr[i]) max = arr[i];
	}
//	cout<<min<<max;
	int min_diff = max - min,max_diff = max-min;
	int sec_min,sec_max;
	for(int i=0;i<len;i++){
		if(arr[i] - min < min_diff && arr[i]!= min) {
			sec_min = arr[i];
			min_diff = arr[i] - min;
		}
		if (max - arr[i] < max_diff && arr[i]!= max){
			 sec_max = arr[i];
			 max_diff = max - arr[i];
		}
		
	}
	cout<< " -",sec_min,",",sec_max;
	*/
