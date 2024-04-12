//231. Power of Two
//Solved
//Easy
//Topics
//Companies
//Given an integer n, return true if it is a power of two. Otherwise, return false.
//
//An integer n is a power of two, if there exists an integer x such that n == 2x.
//
// 
//
//Example 1:
//
//Input: n = 1
//Output: true
//Explanation: 20 = 1
//Example 2:
//
//Input: n = 16
//Output: true
//Explanation: 24 = 16
//Example 3:
//
//Input: n = 3
//Output: false
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int low = 0,high = n;
        // for ( int i =0;i<n;i++){
        //     if (pow(2,i) == n) return true;
        // }
        while(low<=high){
            int mid = (low+high)/2;
            if(pow(2,mid)==n) return true;
            else if(pow(2,mid)<n) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
