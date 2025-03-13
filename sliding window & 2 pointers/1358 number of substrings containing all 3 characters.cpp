//1358. Number of Substrings Containing All Three Characters
//Solved
//Medium
//Topics
//Companies
//Hint
//Given a string s consisting only of characters a, b and c.
//
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.
//
// 
//
//Example 1:
//
//Input: s = "abcabc"
//Output: 10
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
//Example 2:
//
//Input: s = "aaacb"
//Output: 3
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
//Example 3:
//
//Input: s = "abc"
//Output: 1
// 
//
//Constraints:
//
//3 <= s.length <= 5 x 10^4
//s only consists of a, b or c characters.
class Solution {
    public:
        int numberOfSubstrings(string s) {
            //brute force 53/54
            //unordered_map<char,int> mp;
            // int cnt=0;
            // for(int i=0;i<s.length();i++){
            //     for(int j=i;j<s.length();j++){
            //         mp[s[j]]++;
            //         if(mp.size() == 3) {
            //             cnt+=(s.length()-j);
            //             break;
            //         }
            //     }
            //     mp.clear();
            // }
            // return cnt;
            //optimal
            int freq[3] = {0,0,0};
            int cnt=0,curCnt=0,l=0,r=0,n=s.length();
            while(r<n){
                char c = s[r];
                freq[c-'a']++;
                if(freq[c-'a'] == 1) curCnt++;
                while(curCnt ==3){
                    cnt+=(n-r);
                    char c = s[l];
                    if(--freq[c-'a'] == 0)curCnt--;
                    l++;
                }
                r++;
            }
            return cnt;
        }
    };
