//1143. Longest Common Subsequence
//Medium
//Topics
//Companies
//Hint
//Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
//
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//
//For example, "ace" is a subsequence of "abcde".
//A common subsequence of two strings is a subsequence that is common to both strings.
//
// 
//
//Example 1:
//
//Input: text1 = "abcde", text2 = "ace" 
//Output: 3  
//Explanation: The longest common subsequence is "ace" and its length is 3.
//Example 2:
//
//Input: text1 = "abc", text2 = "abc"
//Output: 3
//Explanation: The longest common subsequence is "abc" and its length is 3.
//Example 3:
//
//Input: text1 = "abc", text2 = "def"
//Output: 0
//Explanation: There is no such common subsequence, so the result is 0.
class Solution {
public:
    int rec(string text1,int idx1,string text2,int idx2,vector<vector<int>> &dp){
        //recusive
        if(idx1 <0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1] == text2[idx2]) return 1+rec(text1,idx1-1,text2,idx2-1,dp);
        return dp[idx1][idx2] = max(rec(text1,idx1-1,text2,idx2,dp),rec(text1,idx1,text2,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m = text2.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return rec(text1,n-1,text2,m-1,dp);
    }
};
