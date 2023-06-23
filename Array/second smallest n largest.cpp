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

void find(int arr[],int len){
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
			min = arr[i] - min;
		}
		if (max - arr[i] < max_diff && arr[i]!= max){
			 sec_max = arr[i];
			 max = max - arr[i];
		}
		
	}
	cout<< " -",sec_min,",",sec_max;
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
