//796. Rotate String
//Easy
//3.4K
//131
//Companies
//Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
//
//A shift on s consists of moving the leftmost character of s to the rightmost position.
//
//For example, if s = "abcde", then it will be "bcdea" after one shift.
// 
//
//Example 1:
//
//Input: s = "abcde", goal = "cdeab"
//Output: true
//Example 2:
//
//Input: s = "abcde", goal = "abced"
//Output: false
// 
//
//Constraints:
//
//1 <= s.length, goal.length <= 100
//s and goal consist of lowercase English letters.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        if(s.length()<=2) return false;
        s +=s;
        int cnt=1;
        char c = s[0];
        for(int i =1; i<s.length();i++){
            if(s[i]!=c) cnt++;
        }
        if (cnt==1) return false;
        if(s.find(goal)!= s.npos) return true;
        else return false;
    }
};

int main(){
	Solution s;
	cout<<s.rotateString("abcde","cdeab");
	return 0;
}
