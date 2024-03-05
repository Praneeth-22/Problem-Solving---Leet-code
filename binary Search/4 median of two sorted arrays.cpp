//4. Median of Two Sorted Arrays
//Solved
//Hard
//Topics
//Companies
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
//The overall run time complexity should be O(log (m+n)).
//
// 
//
//Example 1:
//
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//Example 2:
//
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//
//Constraints:
//
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//-106 <= nums1[i], nums2[i] <= 106


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // o(n) , o(n)
        // int n1 = nums1.size(),n2 = nums2.size();
        // int i=0,j=0;
        // vector<int> res;
        // while(i<n1 && j<n2 ){
        //     if(nums1[i] < nums2[j]){
        //         res.push_back(nums1[i]);
        //         i++;
        //     }else{
        //         res.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // while(i < n1) res.push_back(nums1[i++]);
        // while(j < n2) res.push_back(nums2[j++]);
        // int total_size = n1+n2;
        // if(total_size%2 == 1) return res[total_size/2];
        // return (double)((double)(res[total_size/2]) + (double)(res[total_size/2-1]))/2.0;
        //
        //o (n)
        // int n1 = nums1.size();
        // int n2 = nums2.size();
        // int n = n1+n2;
        // int r_pos = n/2;
        // int l_pos = r_pos-1;
        // int el1 = -5,el2 = -5;
        // int i=0,j=0,index=0;
        // while(i<n1 && j <n2){
        //     if(nums1[i]<nums2[j]){
        //         if(index == l_pos) el1 = nums1[i];
        //         if(index == r_pos) el2 = nums1[i];
        //         index++;
        //         i++;
        //     }else{
        //         if(index == l_pos) el1 = nums2[j];
        //         if(index == r_pos) el2 = nums2[j];
        //         index++;
        //         j++;
        //     }
        // }
        // while(i<n1){
        //      if(index == l_pos) el1 = nums1[i];
        //         if(index == r_pos) el2 = nums1[i];
        //         index++;
        //         i++;
        // }
        // while(j<n2){
        //       if(index == l_pos) el1 = nums2[j];
        //         if(index == r_pos) el2 = nums2[j];
        //         index++;
        //         j++;
        // }
        // if(n%2 == 1) return el2;
        // return (double)((double)(el1+el2))/2.0;
        // o(log n)
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        if( n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int low =0,high = n1-1;
        int left = (n1+n2+1)/2;
        while(low<=high){
            int mid = (low +high)/2;
            int mid2 = left -mid;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;
            if(mid < n1) r1 = nums1[mid];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid-1>=0) l1 = nums1[mid-1];
            if(mid2-1 >=0) l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1) {
                if(n%2 == 1) return max(l1,l2);
                return ((double) (max(l1,l2) + min(r1,r2)))/2.0;
            }else if (l1 > r2) high = mid-1;
            else low = mid+1;
        }
        return 0;
    }
};
