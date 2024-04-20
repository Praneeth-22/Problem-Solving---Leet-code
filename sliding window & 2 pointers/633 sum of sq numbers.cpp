//633. Sum of Square Numbers
//Solved
//Medium
//Topics
//Companies
//Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
//
// 
//
//Example 1:
//
//Input: c = 5
//Output: true
//Explanation: 1 * 1 + 2 * 2 = 5
//Example 2:
//
//Input: c = 3
//Output: false
// 
//
//Constraints:
//
//0 <= c <= 231 - 1

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a=0,b=sqrt(c);
        while(a<=b){
            if((a*a)+(b*b)==c) return true;
            else if((a*a)+(b*b)<c) a++;
            else b--;
        }
        return false;
    }
};
