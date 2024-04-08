//395. Longest Substring with At Least K Repeating Characters
//Medium
//Topics
//Companies
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//
//if no such substring exists, return 0.
//
// 
//
//Example 1:
//
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//Example 2:
//
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

class Solution {
public:
    int longestSubstring(string s, int k) {
        //
        unordered_map<char,int> mp;
        int cnt=0;
        for( int i=0;i<s.length();i++){
            // mp[s[i]]++;
            mp.clear();
            for(int j =i;j<s.length();j++){
                mp[s[j]]++;
                if(mp.size()<=k){
                    cnt = max(cnt,j-i+1);
                }else break;
            }
        }
        return cnt;
    }
};
