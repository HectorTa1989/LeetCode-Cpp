/*Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0*/

//Runtime: 368 ms, faster than 43.04% of C++ online submissions for 4Sum II.
//Memory Usage: 43.9 MB, less than 31.82% of C++ online submissions for 4Sum II.
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> absum;
        auto cnt = 0;
        
        for (auto a: A)
            for (auto b: B)
                absum[a + b]++;
        
        for (auto c: C)
            for (auto d: D)
                cnt += absum[0 - c - d];

        return cnt;
    }
};
//Runtime: 628 ms, faster than 17.03% of C++ online submissions for 4Sum II.
//Memory Usage: 32.2 MB, less than 54.55% of C++ online submissions for 4Sum II.
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count;
        map<int, int> AB;
        
        for(int a : A)
            for(int b : B)
                AB[a + b]++;
        
        count = 0;
        for(int c : C)
            for(int d : D){
                int sum = -c - d; 
                if(AB.find(sum) != AB.end())
                    count += AB[sum];
            }
        
        return count;
    }
};