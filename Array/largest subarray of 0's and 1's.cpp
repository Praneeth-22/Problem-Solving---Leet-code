
#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // brute force
        for(int i =0;i<N;i++){
            if(arr[i] == 0) arr[i] = -1;
        }
        int len =0;
//        for(int i=0;i<N;i++){
//            int lastZero=-1;
//            int sum = arr[i];
//            for(int j = i+1;j<N;j++){
//                sum+=arr[j];
//                if(sum == 0) lastZero = j;
//            }
//            len = max(len,lastZero-i+1);
//        }
 		
 		
		 // hash map
 		unordered_map<int,int> mp;
 		int sum=0;
 		int lastIndex=-1;
 		for(int i=0;i<N;i++){
 			sum+=arr[i];
 			if(sum == 0){
 				len = i+1;
 				lastIndex= i;
			 }
			 if(mp.find(sum)!=mp.end()){
			 	if(len < i - mp[sum]){
			 		len = i-mp[sum];
			 		lastIndex = i;
				 }
			 }else mp[sum]= i;
		 }
        return len;
        
    }
   
};
int main() {
    Solution solution;
    int arr[] = {0,1,1,0,1,1,1,0,1,0,1,0,1};
    int N = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum length of subarray with zero sum is " << solution.maxLen(arr, N) << endl;
    return 0;
}
