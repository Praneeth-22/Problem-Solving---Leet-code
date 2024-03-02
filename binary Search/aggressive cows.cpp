//You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
//You are also given an integer 'k' which denotes the number of aggressive cows
//You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
//Print the maximum possible minimum distance.
//Example:
//Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
//
//Output: 2
//
//Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
//Detailed explanation ( Input/output format, Notes, Images )
//Sample Input 1 :
//6 4
//0 3 4 7 10 9
//
//
//Sample Output 1 :
//3
//
//
//Explanation to Sample Input 1 :
//The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

//Sample Input 2 :
//5 2
//4 2 1 3 6
//
//
//Sample Output 2 :
//5
//
//
//Expected time complexity:
//Can you solve this in O(n * log(n)) time complexity?
//
//
//Constraints :
//2 <= 'n' <= 10 ^ 5
//2 <= 'k' <= n
//0 <= 'arr[i]' <= 10 ^ 9




#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int aggressiveCows(vector<int> &nums,int k){
			sort(nums.begin(),nums.end());
			int n=nums.size();
			int low = 1,high = nums[n-1] - nums[0];
			while(low<=high){
				int mid = (low+high)/2;
				if(canPlace(nums,mid,k) == true){
					low=mid+1;
				}else{
					high = mid-1;
				}
			}
			return high;
		}
		bool canPlace(vector<int> nums,int dist,int k){
			int cnt =1,last = nums[0];
			for(int i=0;i<nums.size();i++){
				if(nums[i] - last >=dist){
					cnt++;
					last = nums[i];
				}
				if(cnt >= k) return true;
			}
			return false;
		}
};
int main(){
	vector<int> v= {0,3,4,7,10,9};
	Solution s;
	cout<<s.aggressiveCows(v,4);
	return 0;
}
