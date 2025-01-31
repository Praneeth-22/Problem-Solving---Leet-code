// 5. Longest Palindromic Substring
// Solved
// Medium
// Topics
// Companies
// Hint
// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l + 1, r - 1};
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s; 

        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            auto [l1, r1] = expandAroundCenter(s, i, i);
            // Even-length palindrome
            auto [l2, r2] = expandAroundCenter(s, i, i + 1);
            if (r1 - l1 + 1 > maxLen) {
                maxLen = r1 - l1 + 1;
                start = l1;
            }
            if (r2 - l2 + 1 > maxLen) {
                maxLen = r2 - l2 + 1;
                start = l2;
            }
        }

        return s.substr(start, maxLen);
    }
};
