//326. Power of Three
//Solved
//Easy
//Topics
//Companies
//Given an integer n, return true if it is a power of three. Otherwise, return false.
//
//An integer n is a power of three, if there exists an integer x such that n == 3x.
//
// 
//
//Example 1:
//
//Input: n = 27
//Output: true
//Explanation: 27 = 33
//Example 2:
//
//Input: n = 0
//Output: false
//Explanation: There is no x where 3x = 0.
//Example 3:
//
//Input: n = -1
//Output: false
//Explanation: There is no x where 3x = (-1)

class Solution {
public:
    bool isPowerOfThree(int n) {
        int low = 0,high = n;
        // for ( int i =0;i<n;i++){
        //     if (pow(3,i) == n) return true;
        // }
        while(low<=high){
            int mid = (low+high)/2;
            if(pow(3,mid)==n) return true;
            else if(pow(3,mid)<n) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
