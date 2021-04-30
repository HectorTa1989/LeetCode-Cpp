/*For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

 

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234*/

//Iterate backward through the input vector. Add the element at that index to the input K, then mod by 10 and set the index to the new value. 
//You don't have to check for carries each loop if you do it this way. Long Kbuf is needed just in case a value near int_max is passed, preventing overflow. 
//If K ends up being larger than the input array, then its digits are continually inserted at the beginning of the array. No need for reversal.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        long Kbuf = K;
        for(int index = A.size()-1; index >= 0 && Kbuf > 0; index--, Kbuf/=10){
            Kbuf += A.at(index);
            A.at(index) = Kbuf % 10;
        }
        for(int input = Kbuf; input > 0; input /= 10)
            A.insert(A.begin(), input%10);
        return A;
    }
};