#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int ind = n - 1;
        string res = "";
        while (ind >= 0) {
            if (s[ind] == ' ') {
                ind--;
                continue;
            }
            int temp = ind;
            string str ="";
            while (temp >= 0 && s[temp] != ' ') {
                str += s[temp];
                temp--;
            }
            reverse(str.begin(), str.end()); 
            res += str + " "; 
            ind = temp - 1;
        }
        if (!res.empty()) {
            res.pop_back();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "hello world";
    cout << "Reversed words: " << sol.reverseWords(s) << endl;
    return 0;
}

