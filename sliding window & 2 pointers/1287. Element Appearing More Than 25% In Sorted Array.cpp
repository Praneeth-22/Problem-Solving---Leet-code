// 1287. Element Appearing More Than 25% In Sorted Array
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

// Example 1:

// Input: arr = [1,2,2,6,6,6,6,7,10]
// Output: 6
// Example 2:

// Input: arr = [1,1]
// Output: 1
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 105
class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            //brute force
            int quart = ceil(arr.size()/4);
            // unordered_map<int,int> mp;
            // for(auto it: arr) mp[it]++;
            // int res = -1;
            // for(auto it : mp){
            //     if (it.second > quart) res = it.first;
            // }
            // return res;
            //Optimal
            int el= arr[0],cnt = 1,res=-1;
            for(int i=0;i<arr.size()-quart;i++){
              if (arr[i] == arr[i+quart]) return arr[i];
            }
            return -1;
        }
    };