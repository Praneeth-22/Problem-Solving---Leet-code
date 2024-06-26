//925. Long Pressed Name
//Solved
//Easy
//Topics
//Companies
//Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
//
//You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
//
// 
//
//Example 1:
//
//Input: name = "alex", typed = "aaleex"
//Output: true
//Explanation: 'a' and 'e' in 'alex' were long pressed.
//Example 2:
//
//Input: name = "saeed", typed = "ssaaedd"
//Output: false
//Explanation: 'e' must have been pressed twice, but it was not in the typed output.
// 
//
//Constraints:
//
//1 <= name.length, typed.length <= 1000
//name and typed consist of only lowercase English letters.

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1=0,p2=0;
        char prev;
        if(typed.length()<name.length()) return false;
        while(p2!=typed.length()){
            if(name[p1]==typed[p2]){
                p1++;
                prev = typed[p2];
                p2++;
            }
            else if(name[p1] !=typed[p2] &&prev == typed[p2]){
                p2++;
            }else{
                return false;
            }
        }
        if(p1 !=name.length()) return false;
        else return true;
    }
};
