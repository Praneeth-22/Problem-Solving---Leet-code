// 202. Happy Number
// Solved
// Easy
// Topics
// Companies
// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

 

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false
 

// Constraints:

// 1 <= n <= 231 - 1


class Solution {
public:
    int findSquare(int temp) {
        int sum = 0;
        while (temp > 0) {
            int rem = temp % 10;
            sum += pow(rem, 2);
            temp /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // extra space
        // unordered_set<int> st;
        // int num = n;
        // while (st.find(num) == st.end()) {
        //     st.insert(num);
        //     num = findSquare(num);
        // }
        // floyd's tortoise
        int slow = n, fast = n;
        do {
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        } while (slow != fast);
        return slow == 1 ? true : false;
    }
};