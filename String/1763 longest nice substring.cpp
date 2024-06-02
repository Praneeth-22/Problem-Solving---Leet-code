//
//1763. Longest Nice Substring
//Solved
//Easy
//Topics
//Companies
//Hint
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
//
// 
//
//Example 1:
//
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        if(s.length()<=1)return "";
        unordered_set<char> st;
        for(auto i: s) st.insert(i);
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(st.find(tolower(ch))==st.end() || st.find(toupper(ch))== st.end()){
                string left = longestNiceSubstring(s.substr(0,i));
                string right = longestNiceSubstring(s.substr(i+1,n));
                if(left.size()>=right.size()) return left;
                return right;
            }
        }
        return s;
    }
};
