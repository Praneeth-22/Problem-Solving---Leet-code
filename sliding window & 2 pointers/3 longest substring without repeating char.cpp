//3. Longest Substring Without Repeating Characters
//Solved
//Medium
//Topics
//Companies
//Given a string s, find the length of the longest 
//substring
// without repeating characters.
//
// 
//
//Example 1:
//
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    //brute force
        // int len =0;
        // for(int i=0;i<s.size();i++){
        //     unordered_set<char> st;
        //     for(int j=i;j<s.size();j++){
        //         if(st.find(s[j])!=st.end()) break;
        //         st.insert(s[j]);
        //     }
        //     int curLen =st.size();
        //     len = max(len,curLen);
        // }
        //sliding window
        int lIdx =0, rIdx =0, len =0;
        vector<int> occ(128,0);
        while(rIdx < s.length()){
            occ[s[rIdx]]++;
            while(occ[s[rIdx]]>1){
                occ[s[lIdx]]--;
                lIdx++;
            }
            len = max(len, rIdx-lIdx+1);
            rIdx++;
        }
       return len;
    }
};
