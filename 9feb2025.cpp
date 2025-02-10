/*
Q: 3173. Count of Pairs With Equal Sum of Digits
Link - https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
*/



/*
Approach:
1. Use a map to store the frequency of the difference between the index and the value at that index.
2. Iterate through the array and for each index, calculate the difference between the index and the value at that index.
3. Add the frequency of the difference to the answer.
4. Return the total number of pairs minus the answer.

HINT :
always swap the condition for this type of question LHS and RHS to make it easier to understand
*/

Full Soln:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve(vector<int> &v) {
    long long n = v.size();
    long long ans = 0;
    unordered_map<int, int> mp;
    long long totalPairs = (long long)n * (n-1) / 2;
    for (int i = 0; i < n; i++) {
        int valueDiff = i - v[i];
        ans+=mp[valueDiff];
        mp[valueDiff]++;
    }
    return totalPairs - ans;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(v) << endl;
    return 0;
}
