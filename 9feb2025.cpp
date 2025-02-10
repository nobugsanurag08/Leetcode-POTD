/*
Q: 3173. Count of Pairs With Equal Sum of Digits
Link - https://leetcode.com/problems/count-of-pairs-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-09
*/

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

/*
Approach:
1. Use a map to store the frequency of the difference between the index and the value at that index.
2. Iterate through the array and for each index, calculate the difference between the index and the value at that index.
3. Add the frequency of the difference to the answer.
4. Return the total number of pairs minus the answer.

HINT :
always swap the condition for this type of question LHS and RHS to make it easier to understand
*/