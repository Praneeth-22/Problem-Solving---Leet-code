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
        int arr[3]= {-1,-1,-1};
        int n = s.length(),cnt=0,l=0,r=0;
        //
        // for(int i=0;i<n;i++){
        //     mp.clear();
        //     for(int j=i;j<n;j++){
        //         mp[s[j]]++;
        //         if(mp.size() == 3){
        //             cnt++;
        //         }
        //     }
        // }
        //
        while(r<n){
            arr[s[r]-'a'] = r;
            if(arr[0] != -1 && arr[2]!=-1 && arr[1] !=-1){
                cnt+=(1+min(arr[0],min(arr[1],arr[2])));
            }
            r++;
        }
        return cnt;
    }
};
