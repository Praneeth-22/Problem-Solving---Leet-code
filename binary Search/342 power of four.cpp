//342. Power of Four
//Solved
//Easy
//Topics
//Companies
//Given an integer n, return true if it is a power of four. Otherwise, return false.
//
//An integer n is a power of four, if there exists an integer x such that n == 4x.
//
// 
//
//Example 1:
//
//Input: n = 16
//Output: true
//Example 2:
//
//Input: n = 5
//Output: false
//Example 3:
//
//Input: n = 1
//Output: true
// 
class Solution {
public:
    bool isPowerOfFour(int n) {
             int low = 0,high = n;
        // for ( int i =0;i<n;i++){
        //     if (pow(4,i) == n) return true;
        // }
        while(low<=high){
            int mid = (low+high)/2;
            if(pow(4,mid)==n) return true;
            else if(pow(4,mid)<n) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
