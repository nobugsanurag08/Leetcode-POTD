Clear Digits Link - https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
/*
3174. Clear Digits Link - https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
Ques: You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/
<<<<<<< Updated upstream
Soln: 
=======
#include <string>
#include <stack>
using namespace std;
>>>>>>> Stashed changes

class Solution {
public:
    string clearDigits(string s) {
        string st = "";
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            st= stk.top() + st;
            stk.pop();
        }
        return st;
    }
};

/*
Approach:
1. Use a stack to store the characters of the string.
2. If the character is a digit, pop the stack.
3. If the character is not a digit, push it onto the stack.
4. After processing all characters, the stack will contain the characters in reverse order.
5. Pop the stack and append the characters to the result string.
6. Return the result string.
*/
