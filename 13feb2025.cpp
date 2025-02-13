/*
3066. Minimum Operations to Exceed Threshold Value II
*/
/*
Question: You are given a 0-indexed integer array nums, and an integer k.
In one operation, you will:
Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k
*/

/*
Approach:
1. We have to use a priority queue(min heap) to keep track of the smallest elements in the array.
2. now we have at the top minimum element in the heap and after popping it we have the next minimum element in the heap.
3. now add them using given condition and push the result to the heap.
4. continue this process until all elements in the array are greater than or equal to k.
5. return the number of operations performed.
*/  

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

// Functional Solution:

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        long long ans = 0;
        for(auto &a:nums){
            pq.push(a);
        }
        while(pq.size()>0){
            long long topElement1 = pq.top();
            if(topElement1 >= k){
                break;
            }
            ans++;
            pq.pop();
            long long topElement2 = pq.top();
            pq.pop();
            long long temp = (min(topElement1,topElement2) * 2) + max(topElement1,topElement2);
            pq.push(temp);
        }
        return ans;
    }
};