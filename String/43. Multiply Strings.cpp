// 43. Multiply Strings
// Attempted
// Medium
// Topics
// Companies
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 class Solution {
public:
    long long convertToInt(string x) {
        long long res = 0;
        for (char c : x) {
            res = res * 10 + (c - '0');
        }
        return res;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        long long n1 = convertToInt(num1);
        long long n2 = convertToInt(num2);
        long long int product = n1 * n2;
        string res = to_string(product);
        return res;
    }
};