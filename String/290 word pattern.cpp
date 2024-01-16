//290. Word Pattern
//Solved
//Easy
//Topics
//Companies
//Given a pattern and a string s, find if s follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
//
// 
//
//Example 1:
//
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Example 2:
//
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//
//Constraints:
//
//1 <= pattern.length <= 300
//pattern contains only lower-case English letters.
//1 <= s.length <= 3000
//s contains only lowercase English letters and spaces ' '.
//s does not contain any leading or trailing spaces.
//All the words in s are separated by a single space.


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int slen = s.length();
        vector<string> words;
        int i =0,j=1;
        while(i < slen && j < slen){
            if(s[j] == ' '){
                string temp = s.substr(i,j-i);
                words.push_back(temp);
                i=j+1;
                j++;
            }else{
                j++;
            }
        }
        string temp = s.substr(i,j-1);
        words.push_back(temp);
        int n = words.size();
        int plen = pattern.length();
        if(n!=plen) return false;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for(int i=0; i<n; i++){
            if(mp1.count(pattern[i]) == 0 && mp2.count(words[i]) == 0){
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
            else if(mp1.count(pattern[i]) != 0 && mp2.count(words[i]) == 0){
                return false;
            }
            else if(mp1.count(pattern[i]) == 0 && mp2.count(words[i]) != 0){
                return false;
            }
            else if(mp1.count(pattern[i]) != 0 && mp2.count(words[i]) != 0){
                if(mp1[pattern[i]] == words[i] && mp2[words[i]] == pattern[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return true;

    }
};
