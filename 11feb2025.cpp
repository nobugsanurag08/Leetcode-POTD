/*
1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

*/

/*
HINT :
1. Use a string function erase and substr and iterate through the string s.
/*
Approach:
1. Use a loop to iterate through the string s .
2. check a condition if the substring part is found in the string s, for it you have to check temp string length is greater than or equal to part string length.
3. if it is found(use substr function) then remove the substring part from the string s , for it you can use the erase function of the string class.
4. return the string s after removing all occurrences of part.
*/


// Functional Solution :
#include <string>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int partLen = part.length();
        int stringLen = s.length();
        string ans = "";
        for (int i = 0; i < stringLen; i++) {
            ans.push_back(s[i]);
            if (ans.length() >= partLen &&
                ans.substr(ans.length() - partLen) == part) {
                ans.erase(ans.length() - partLen);
            }
        }
        return ans;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)
