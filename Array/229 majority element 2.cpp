
//229. Majority Element II
//Solved
//Medium
//Topics
//Companies
//Hint
//Given an integer array of size n, find all elements that appear more than ? n/3 ? times.
//
// 
//
//Example 1:
//
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//
//Input: nums = [1]
//Output: [1]
//Example 3:
//
//Input: nums = [1,2]
//Output: [1,2]
// 
//
//Constraints:
//
//1 <= nums.length <= 5 * 104
//-109 <= nums[i] <= 109

//Boyer-Moore Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // vector<int> ans;
        // map<int,int> m;
        // int n = nums.size();
        // int mini = (int)(n/3)+1;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]]== mini) ans.push_back(nums[i]);
        //     if(ans.size() == 2) break;
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        //
         int cnt1=0,cnt2=0;
         int el1 = INT_MIN,el2 = INT_MIN;
         vector<int> ans;
         for(int i=0;i<nums.size();i++){
             if(cnt1 == 0 && el2!=nums[i]){
                 cnt1=1;
                 el1= nums[i];
             }
             else if(cnt2 ==0 && el1!=nums[i]){
                 cnt2=1;
                 el2 = nums[i];
             }
             else if(nums[i] == el1) cnt1++;
             else if(nums[i] ==el2) cnt2++;
             else{
                 cnt1--;
                 cnt2--;
             }
         }
         cnt1=0,cnt2=0;
         for(int i =0;i<nums.size();i++){
             if(el1 == nums[i]) cnt1++;
             if(el2 == nums[i]) cnt2++;
         }
         int mini = (int)(nums.size()/3)+1;
         if(cnt1>=mini) ans.push_back(el1);
         if(cnt2>=mini) ans.push_back(el2);
         sort(ans.begin(),ans.end());
         return ans;
         
    }
};
