//3090. Maximum Length Substring With Two Occurrences
//Solved
//Easy
//Topics
//Companies
//Hint
//Given a string s, return the maximum length of a 
//substring
// such that it contains at most two occurrences of each character.
// 
//
//Example 1:
//
//Input: s = "bcbbbcba"
//
//Output: 4
//
//Explanation:
//
//The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
//Example 2:
//
//Input: s = "aaaa"
//
//Output: 2
//
//Explanation:
//
//The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
// 
//
//Constraints:
//
//2 <= s.length <= 100
//s consists only of lowercase English letters.

class Solution {
public:
    int maximumLengthSubstring(string s) {
        //atmost - 0,1,2 occurances
        int n = s.length();
        int len = 0;
        // for(int i=0;i<n;i++){
        //     vector<int> freq(26,0);
        //     for(int j=i;j<n;j++){
        //         if(++freq[s[j]-'a'] ==3) break;
        //         len = max(len,j-i+1);
        //     }
        // } 
        unordered_map<char,int> freq;
        int l=0,r=0;
        while(r<n){
            freq[s[r]]++;
            while(freq[s[r]] >2){
                 freq[s[l]]--;
                 l++;
            }
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};
