//20. Valid Parentheses
//Easy
//23K
//1.6K
//Companies
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
// 
//
//Example 1:
//
//Input: s = "()"
//Output: true
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//Example 3:
//
//Input: s = "(]"
//Output: false
// 
//
//Constraints:
//
//1 <= s.length <= 104
//s consists of parentheses only '()[]{}'.


#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (!st.empty()) {
                    char top = st.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;

    // Example usage:
    std::string input1 = "{[()]}";
    std::string input2 = "{[(])}";
    
    if (solution.isValid(input1)) {
        std::cout << input1 << " is valid\n";
    } else {
        std::cout << input1 << " is not valid\n";
    }

    if (solution.isValid(input2)) {
        std::cout << input2 << " is valid\n";
    } else {
        std::cout << input2 << " is not valid\n";
    }

    return 0;
}

