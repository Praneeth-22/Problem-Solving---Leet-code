//345. Reverse Vowels of a String
//Solved
//Easy
//Topics
//Companies
//Given a string s, reverse only all the vowels in the string and return it.
//
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
//
// 
//
//Example 1:
//
//Input: s = "hello"
//Output: "holle"
//Example 2:
//
//Input: s = "leetcode"
//Output: "leotcede"
// 
//
//Constraints:
//
//1 <= s.length <= 3 * 105
//s consist of printable ASCII characters.


class Solution {
public:
    string reverseVowels(string s) {
        string temp = s;
        vector<char> v;
        for( auto c:s){
            if(c == 'a' || c == 'e' || c== 'i' ||c=='o' ||c=='u' ||c == 'A' || c == 'E' || c== 'I' ||c=='O' ||c=='U') v.push_back(c);
        }
        reverse(v.begin(),v.end());
        int j =0;
        for(int i =0; i< temp.length();i++){
            char c =temp[i];
            if(c == 'a' || c == 'e' || c== 'i' ||c=='o' ||c=='u' ||c == 'A' || c == 'E' || c== 'I' ||c=='O' ||c=='U'){
                temp[i] = v[j];
                j++;
            }
        }
        return temp;
    }
};
