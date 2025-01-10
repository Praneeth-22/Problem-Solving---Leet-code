// 214. Shortest Palindrome
// Attempted
// Hard
// Topics
// Companies
// You are given a string s. You can convert s to a 
// palindrome
//  by adding characters in front of it.

// Return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.

class Solution {
public:
    bool isPalindrome(string s) {
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        return s == reversed_s;
    }
    string shortestPalindrome(string s) {
        // brute force: find the longest palindrome string in s and append the
        // characters after it in reversed order as prefix.
        // for (int i = s.size() - 1; i >= 0; i--) {
        //     if (isPalindrome(s.substr(0, i+1))) {
        //         string sufx = s.substr(i + 1, s.length());
        //         reverse(sufx.begin(), sufx.end());
        //         return sufx + s;
        //     }
        // }
        // return "";
        //Rabin Karp algo:
        
    }
};