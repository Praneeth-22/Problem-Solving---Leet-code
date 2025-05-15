// 3335. Total Characters in String After Transformations I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

// If the character is 'z', replace it with the string "ab".
// Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "abcyy", t = 2

// Output: 7

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'y' becomes 'z'
// 'y' becomes 'z'
// String after the first transformation: "bcdzz"
// Second Transformation (t = 2):
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'd' becomes 'e'
// 'z' becomes "ab"
// 'z' becomes "ab"
// String after the second transformation: "cdeabab"
// Final Length of the string: The string is "cdeabab", which has 7 characters.
// Example 2:

// Input: s = "azbk", t = 1

// Output: 5

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'z' becomes "ab"
// 'b' becomes 'c'
// 'k' becomes 'l'
// String after the first transformation: "babcl"
// Final Length of the string: The string is "babcl", which has 5 characters.
 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters.
// 1 <= t <= 105

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // brute force
        //  int res=0,mod = 1e9+7;
        //   string temp;
        //  while(t>0){
        //       temp = "";
        //      for(int i=0;i<s.length();i++){
        //          if(s[i]=='z'){
        //              temp.push_back('a');
        //              temp.push_back('b');
        //          }
        //          else{
        //              char ch = s[i]+1;
        //              temp.push_back(ch);
        //          }
        //      }
        //      cout<<temp<<endl;
        //      s=temp;
        //      t--;
        //  }
        //  return temp.length()%mod;
        // optimal
        int mod = 1e9 + 7;
        array<int, 26> sfreq{};
        for (char c : s)
            sfreq[c - 'a']++;
        while (t > 0) {
            array<int, 26> next_freq{};
            for (int j = 0; j < 26; j++) {
                if (j < 25)
                    next_freq[j + 1] = sfreq[j];
                else {
                    next_freq[0] = sfreq[25];
                    next_freq[1] = (next_freq[1] + sfreq[25]) % mod;
                }
            }
            sfreq = next_freq;

            t--;
        }
        int len = 0;
        for (int i = 0; i < 26; i++)
            len = (len + sfreq[i]) % mod;
        return len;
    }
};