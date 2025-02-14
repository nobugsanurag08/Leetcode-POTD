/*
1352. Product of the Last K Numbers
*/
/*
Question: Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

*/

/*
Approach:
1. As we have to maintain the products of previous numbers, we can use a prefix product array.
2. We can use a prefix product array to store the products of the previous numbers.
3. if we encounter a 0, we can reset the prefix product array.
4. if we encounter a number, we can append multiple of it to the prefix product array.
5. now we can use the prefix product array to get the product of the last k numbers.
6. if the product is 0, we can return 0.
7. else we can return the product of the last k numbers using the prefix product array.
*/  

/*
Time Complexity: O(1) for add and getProduct.
Space Complexity: O(n) for the prefix product array.
*/

#include <vector>
#include <algorithm>

using namespace std;

// Function Solution :

class ProductOfNumbers {
public:
    vector<int> list;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0){
            list.clear();
        }else{
            list.push_back(num * (list.empty() ? 1 : list.back()));
        }
    }
    
    int getProduct(int k) {
        int n =list.size();
        if(n<k || n==0){return 0;}
        if(k == n){return list.back();}
        return list.back() / list[n - k - 1];
    }
};
