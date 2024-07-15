// 385. Find the Distance Value Between Two Arrays
// Solved
// Easy
// Topics
// Companies
// Hint
// Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

// The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

// Example 1:

// Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
// Output: 2
// Explanation: 
// For arr1[0]=4 we have: 
// |4-10|=6 > d=2 
// |4-9|=5 > d=2 
// |4-1|=3 > d=2 
// |4-8|=4 > d=2 
// For arr1[1]=5 we have: 
// |5-10|=5 > d=2 
// |5-9|=4 > d=2 
// |5-1|=4 > d=2 
// |5-8|=3 > d=2
// For arr1[2]=8 we have:
// |8-10|=2 <= d=2
// |8-9|=1 <= d=2
// |8-1|=7 > d=2
// |8-8|=0 <= d=2
// Example 2:

// Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
// Output: 2
// Example 3:

// Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
// Output: 1
import java.io.*;

class Solution {
    public static int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int n = arr1.length;
        int m = arr2.length;
        Arrays.sort(arr2);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (Math.abs(arr2[mid] - arr1[i]) <= d)
                    break;
                else if (arr2[mid] < arr1[i])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            if (l > r)
                cnt++;
        }
        return cnt;
    }

    public static void main(String[] args) {
        int arr1[] = { 2, 1, 100, 3 };
        int arr2[] = { -5, -2, 10, -3, 7 };
        System.out.println("result : " + findTheDistanceValue(arr1, arr2, 2));

    }
}
