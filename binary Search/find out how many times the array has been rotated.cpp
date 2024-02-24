//Find out how many times the array has been rotated
//Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 
//
//Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm
//
//Examples
//Solution:
//How does the rotation occur in a sorted array?
//
//Let’s consider a sorted array: {1, 2, 3, 4, 5}. If we rotate this array 2 times, it will become: {4, 5, 1, 2, 3}. In essence, we moved the element at the last index to the front, while shifting the remaining elements to the right. We performed this process twice.
//
//
//Observation: 
//
//We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
////So, in order to solve this problem, we have to find the index of the minimum element.

#include<bits/stdc++.h>
using namespace std;

class solution{
	public:
		int find_out(vector<int> &v){
			int index=-1;
			int mini = INT_MAX;
			int low = 0,high =v.size()-1;
			while(low <= high){
				int mid = (low + high)/2;
				if(v[low]<=v[mid]){
					mini = min(mini,v[low]);
					if(v[low]<=mini) index = low;
					low = mid+1;
				}
				else{
					mini = min(mini,v[mid]);
					if(v[mid]<=mini) index = mid;
					high = mid-1;
				}
			}
			return index;
		}
};

int main(){
	vector<int> v= {6,7,8,9,10,1,2,3,4,5};
	solution s;
	cout<<s.find_out(v);
	return 0;
}
