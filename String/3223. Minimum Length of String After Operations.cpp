// 3223. Minimum Length of String After Operations
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s.

// You can perform the following process on s any number of times:

// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.

 

// Example 1:

// Input: s = "abaacbcbb"

// Output: 5

// Explanation:
// We do the following operations:

// Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
// Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
// Example 2:

// Input: s = "aa"

// Output: 2

// Explanation:
// We cannot perform any operations, so we return the length of the original string.

 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of lowercase English letters.

class Solution {
public:
    int leftSide(char c,int l,int r,string s ){
        for(int i=l;i>=r;i--){
            if(s[i] == c) return i;
        }
        return -1;
    }
    int rightSide(char c,int l,int r,string s ){
        for(int i=l;i<r;i++){
            if(s[i] == c) return i;
        }
        return -1;
    }
    int minimumLength(string s) {
        //brute force approach : 674/702
        // int n = s.length();
        // int  left,right;
        // for(int i=1;i<n-1;i++){
        //     if( s[i]=='0') continue;
        //      int lId = leftSide(s[i],i-1,0,s);
        //      int rId = rightSide(s[i],i+1,n,s);
        //      if(lId!= -1 && rId != -1){
        //         s[lId] = '0';
        //         s[rId] = '0';
        //      }
        // }
        // string res;
        // for(auto it: s){
        //     if(it !='0') res.push_back(it);
        // }
        // return res.length();

        //optimal : odd occurance -> 1 and even occurance -> 2
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        int res =0;
        for(auto it: mp){
            if (it.second%2 == 1) res+=1;
            else res+=2;
        }
        return res;
    }
};