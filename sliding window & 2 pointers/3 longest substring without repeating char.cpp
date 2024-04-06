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
        //fails for non-char
    //     set<char> st;
    //     int i =0;
    //     int n = s.length();
    //     int cnt=0;
    //     while(i!=n){
    //         if(st.find(s[i])!=st.end()){
    //             int l = st.size();
    //             cnt = max(cnt,l);
    //             st.erase(s[0]);
    //             st.insert(s[i]);
    //         }
    //         else st.insert(s[i]);
    //         i++;
    //     }
    //     return cnt;
    // }
    vector<int> check(255,-1);
    int l=0,r=0,n=s.size(),cnt=0;
    while(r<n){
        int e=0;
        if(check[s[r]]!=-1){
            if(check[s[r]]>=l) l = check[s[r]]+1;
        }
        e = r-l+1;
        cnt = max(cnt,e);
        check[s[r]] = r;
        r++;
    }
    return cnt;
    }
};
