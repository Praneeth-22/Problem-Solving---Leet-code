// 738. Monotone Increasing Digits
// Attempted
// Medium
// Topics
// Companies
// Hint
// An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

// Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

 

// Example 1:

// Input: n = 10
// Output: 9
// Example 2:

// Input: n = 1234
// Output: 1234
// Example 3:

// Input: n = 332i
// Output: 299


class Solution {
public:
bool isSatisfies(int n) {
        int k = 10;
        while (n > 0) {
            if (k < n % 10) {
                return false;
            } else {
                k = n % 10;
                n /= 10;
            }
        }
        return true;
    }
    int monotoneIncreasingDigits(int n) {
        while (!isSatisfies(n)) {
            n--;
        }
        return n;
    }
};