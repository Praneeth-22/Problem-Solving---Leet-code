//
//1941. Check if All Characters Have Equal Number of Occurrences
//Solved
//Easy
//Topics
//Companies
//Hint
//Given a string s, return true if s is a good string, or false otherwise.
//
//A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
//
// 
//
//Example 1:
//
//Input: s = "abacbc"
//Output: true
//Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
//Example 2:
//
//Input: s = "aaabb"
//Output: false
//Explanation: The characters that appear in s are 'a' and 'b'.
//'a' occurs 3 
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        //hash map
        unordered_map<char,int> mp;
        for(auto it: s) mp[it]++;
        int flag = true;
        int temp = mp[s[0]];
        for(auto it:mp){
            int freq = it.second;
            if(freq!=temp) return false;
        }
        return true;
    }
};
