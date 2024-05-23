//316. Remove Duplicate Letters
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
//the smallest in lexicographical order
// among all possible results.
//
// 
//
//Example 1:
//
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//
//Constraints:
//
//1 <= s.length <= 104
//s consists of lowercase English letters.

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> isSelected(26,false);
        vector<int> lastOccurance(26,-1);
        string res;
        for(int i =0;i<n;i++){
            lastOccurance[s[i] - 'a'] = i; 
        }
        //monotonically increasing
        for(int i=0;i<n;i++){
            char ch = s[i];
            int idx = ch - 'a';
            if(isSelected[idx]) continue;
            while(res.length()> 0 &&res.back() > ch && lastOccurance[res.back()-'a'] > i){
                isSelected[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            isSelected[idx] = true;
        }
        return res;
    }
};
