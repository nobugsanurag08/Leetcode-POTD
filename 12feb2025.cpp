/*
2342. Max Sum of a Pair With Equal Sum of Digits
*/

/*
Qn:
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j,
and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Example 1:
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
*/

// HINT:
// We can use a hashmap to store the sum of digits of each number and then use a priority queue to get the two largest numbers for each sum.
/*
APPROACH:
1. As in the question, we need to find the sum of digits of each number and then find the two largest numbers for each equal sum digit.
2. We can use a hashmap to store the sum of digits of each number and corresponding to this sum, we can store the numbers in a vector.
3. Now, we can iterate over the hashmap and for each sum, we can use a min heap (priority queue) to get the two largest numbers.
4. We can then add the two largest numbers and update the maximum sum.
5. Finally, we can return the maximum sum.  
*/

// TC: O(KlogN), where K is 2 (as we are using a min heap to get the two largest numbers)
// SC: O(N)


// How different is this from the sorting approach?
// In the sorting approach, we would need to sort the array first and then find the two largest numbers for each equal sum digit.
// This would take O(NlogN) time.
// In the current approach, we are using a hashmap and a priority queue to get the two largest numbers for each equal sum digit.
// This would take O(KlogN) time, where K is 2 (as we are using a min heap to get the two largest numbers).

// Functional Soln:

#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &a:nums){
            long long int sum=0;
            string str=to_string(a);
            for(auto &c:str){
                sum+=c-48;
            }
            mp[sum].push_back(a);
        }
        long long int mx=LONG_MIN;
        for(auto &a:mp){
            long long sum = 0;
            if(a.second.size() !=1){
                for (auto &a1:a.second){
                    pq.push(a1);
                    if(pq.size()>2){
                        pq.pop();
                    }
                }
            int element1 = pq.top();pq.pop();
            int element2 = pq.top();pq.pop();
            sum=element1 + element2;
            }
            mx=max(mx,sum);
        }

        return mx == 0 ? -1 : mx;
        
    }
};