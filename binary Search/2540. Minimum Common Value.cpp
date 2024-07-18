//2540. Minimum Common Value
//Solved
//Easy
//Topics
//Companies
//Hint
//Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
//
//Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
//
// 
//
//Example 1:
//
//Input: nums1 = [1,2,3], nums2 = [2,4]
//Output: 2
//Explanation: The smallest element common to both arrays is 2, so we return 2.
//Example 2:
//
//Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
//Output: 2
//Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
// 
//
//Constraints:
//
//1 <= nums1.length, nums2.length <= 105
//1 <= nums1[i], nums2[j] <= 109
//Both nums1 and nums2 are sorted in non-decreasing order.

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Brute-force
        int n = nums1.size(),m = nums2.size();
        // int i =0,j;
        // bool flag = false;
        // for(;i<n;i++){
        //     for(j=0;j<m;j++){
        //         if(nums1[i] == nums2[j]) flag =true;
        //     }
        //     if(flag) return nums1[i];
        // }
        // return -1;
        //optimal solution
        for(int i=0;i<n;i++){
            int l=0,r=m-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(nums1[i] == nums2[mid]) return nums2[mid];
                else if (nums1[i] < nums2[mid]) r= mid-1;
                else l = mid+1;
            }
        }
        return -1;
        
    }
};
