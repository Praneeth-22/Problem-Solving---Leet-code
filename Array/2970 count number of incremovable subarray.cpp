//2970. Count the Number of Incremovable Subarrays I
//Solved
//Easy
//Topics
//Companies
//Hint
//You are given a 0-indexed array of positive integers nums.
//
//A subarray of nums is called incremovable if nums becomes strictly increasing on removing the subarray. For example, the subarray [3, 4] is an incremovable subarray of [5, 3, 4, 6, 7] because removing this subarray changes the array [5, 3, 4, 6, 7] to [5, 6, 7] which is strictly increasing.
//
//Return the total number of incremovable subarrays of nums.
//
//Note that an empty array is considered strictly increasing.
//
//A subarray is a contiguous non-empty sequence of elements within an array.
//
// 
//
//Example 1:
//
//Input: nums = [1,2,3,4]
//Output: 10
//Explanation: The 10 incremovable subarrays are: [1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4], and [1,2,3,4], because on removing any one of these subarrays nums becomes strictly increasing. Note that you cannot select an empty subarray.
//Example 2:
//
//Input: nums = [6,5,7,8]
//Output: 7
//Explanation: The 7 incremovable subarrays are: [5], [6], [5,7], [6,5], [5,7,8], [6,5,7] and [6,5,7,8].
//It can be shown that there are only 7 incremovable subarrays in nums.
//Example 3:
//
//Input: nums = [8,7,6,6]
//Output: 3
//Explanation: The 3 incremovable subarrays are: [8,7,6], [7,6,6], and [8,7,6,6]. Note that [8,7] is not an incremovable subarray because after removing [8,7] nums becomes [6,6], which is sorted in ascending order but not strictly increasing.
// 

//
//class Solution {
//public:
//    int incremovableSubarrayCount(vector<int>& nums) {
//        int cnt=0;
//        for(int i=0;i<nums.size();i++){
//            for(int j =i;j<nums.size();j++){
//                int flag = 1;
//                int prev = -1;
//                for(int k=0;k<nums.size();k++ ){
//                    if(k>=i && k<=j) continue;
//                    if(prev >= nums[k]){
//                        flag = 0;
//                        break;
//                    }
//                    prev = nums[k];
//                }
//                if(flag) cnt++;
//            }
//        }
//        return cnt;
//    }
//};

class Solution {
public:
    bool check(vector<int> tmp){
        for(int i=1;i<tmp.size();i++){
            if(tmp[i] <= tmp[i-1]) return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> tmp;
                for(int k=0;k<i;k++){
                    tmp.push_back(nums[k]);
                }
                for(int k=j+1;k<n;k++){
                    tmp.push_back(nums[k]);
                }
                if(check(tmp)){
                    res++;
                }
            }
        }
        return res;
    }
};
