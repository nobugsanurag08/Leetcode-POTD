Qn:  3147. Taking Maximum Energy From the Mystic Dungeon

https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon


🔹 Brute Force Approach (Commented Out)

It tries all possible starting points (i) in the array.

For each starting point, it sums the energies at indices i, i+k, i+2k, … until the end of the array.

It keeps track of the maximum total energy found.

Time complexity: O(n²/k) (inefficient for large inputs).


🔹 DP (Dynamic Programming) Approach (Optimized)

A bottom-up approach builds results from the end of the array.

dp[i] stores the maximum energy sum starting from index i.

Formula:

dp[i] = energy[i] + (i+k<en ? dp[i+k] : 0);

This means: current energy + best energy you can get if you jump k steps ahead.

As you move backward through the array (i = en - 1 → 0), you compute each dp[i] and update the global ans with the maximum found.

Time complexity: O(n) — only one pass through the array.



Soln:
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int en = energy.size();
        //Brute Force Approach
        /*for (int i = 0; i < en; i++) {
            int tempAns = 0;
            for (int j = i; j < en; j++) {
                tempAns += energy[j];
                j = j + k - 1;
            }
            ans = max(ans, tempAns);
        }
        return ans;
        */
        //DP Approach (Optimized)
        vector<int>dp(en,0);
        for(int i = en-1;i>=0;i--){
            dp[i] = energy[i] + (i+k<en ? dp[i+k] : 0);
            ans=max(ans,dp[i]); 
        }
        return ans;
    }
};