//1291. Sequential Digits
//Solved
//Medium
//Topics
//Companies
//Hint
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
//
// 
//
//Example 1:
//
//Input: low = 100, high = 300
//Output: [123,234]
//Example 2:
//
//Input: low = 1000, high = 13000
//Output: [1234,2345,3456,4567,5678,6789,12345]


#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int i =1;i<=9;i++){
            int nxt_digit = i+1;
            int num = i;
            while(num<=high && nxt_digit <=9){
                num = num*10+nxt_digit;
                if(low<=num && num <=high) res.push_back(num);
                nxt_digit++;
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
