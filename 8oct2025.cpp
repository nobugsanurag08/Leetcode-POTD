solution - CPP
QN - https://leetcode.com/problems/fraction-to-recurring-decimal/description/

🔹 Approach

Handle zero and division-by-zero cases

If numerator == 0, return "0".

If denominator == 0, it’s invalid (can return "NaN" or handle separately).

Determine the sign of the result

If exactly one of (numerator, denominator) is negative, the result is negative.

This is checked using XOR:

if ((num < 0) ^ (den < 0)) ans += "-";


Then, convert both numbers to positive long long values using llabs() to handle overflow cases like INT_MIN.

Compute the integer part

Divide numerator by denominator:

q = n / d;
ans += to_string(q);


If there’s no remainder (r == 0), return ans — no fractional part exists.

Compute the fractional part

Add a decimal point (.) to the result.

Use a hash map (unordered_map<long long, int>) to track each remainder and the index in the result string where that remainder first appeared.

Multiply remainder by 10, divide by den, append the quotient to ans, and update the remainder.

Detect repeating decimals

If the same remainder appears again, it means the decimal has started repeating.

Insert '(' at the position stored in the map and add ')' at the end.

Break the loop.

Return the final result string

🔹 Complexity

Time Complexity: O(n) — each remainder is processed once (up to den unique remainders).

Space Complexity: O(n) — for storing remainders in the map.

🔹 Example Walkthrough

Input: numerator = -50, denominator = 8

Sign → negative ('-')

Absolute values: n = 50, d = 8

Integer part: 50 / 8 = 6, remainder = 2 → "6."

Fractional part:

Remainder 2 → 2 * 10 / 8 = 2 → append "2", new remainder = 4

Remainder 4 → 4 * 10 / 8 = 5 → append "5", remainder = 0

Final result = "-6.25"



CODE :

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            string ans = recurringDec(numerator, denominator);
            return ans;
        }
    
        string recurringDec(int num, int den) {
            if (num == 0) {
                return "0";
            }
            string ans = "";
            if ((num < 0) ^ (den < 0)) ans += "-";
    
            long long n = llabs((long long)num);  
            long long d = llabs((long long)den);  
            long long q = n / d;
            long long r = n % d;
    
            ans += to_string(q);
            if (r == 0) {
                return ans;
            } else {
                ans += '.';
                unordered_map<long long, int> mp;
                while (r != 0) {
                    if (mp.count(r)) { 
                        ans.insert(mp[r], "(");
                        ans += ")";
                        break;
                    } else {
                        mp[r] = ans.length();
                        r *= 10;
                        q = r / d;
                        r = r % d;
                        ans += to_string(q);
                    }
                }
            }
            return ans;
        }
    };
    