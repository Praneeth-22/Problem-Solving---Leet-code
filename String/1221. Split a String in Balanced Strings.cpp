//1221. Split a String in Balanced Strings
//Solved
//Easy
//Topics
//Companies
//Hint
//Balanced strings are those that have an equal quantity of 'L' and 'R' characters.
//
//Given a balanced string s, split it into some number of substrings such that:
//
//Each substring is balanced.
//Return the maximum number of balanced strings you can obtain.
//
// 
//
//Example 1:
//
//Input: s = "RLRRLLRLRL"
//Output: 4
//Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
//Example 2:
//
//Input: s = "RLRRRLLRLL"
//Output: 2
//Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
//Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
//Example 3:
//
//Input: s = "LLLLRRRR"
//Output: 1
//Explanation: s can be split into "LLLLRRRR".

class Solution {
public:
    int balancedStringSplit(string s) {
        // using stack
        // stack<char> st;
        // st.push(s[0]);
        // int i =1,len = s.length()-1;
        int cnt=0;
        // while(i<=len){
        //    if(st.empty() || st.top() ==s[i] ){
        //     st.push(s[i]);
        //    }else{
        //     st.pop();
        //     if(st.empty()) cnt++;
        //    }
        //     i++;
        // }
        int iter=0;
        for(auto it : s){
            if(it == 'R') iter++;
            else iter--;

            if(iter==0) cnt++;
        }
        return cnt;
    }
};

