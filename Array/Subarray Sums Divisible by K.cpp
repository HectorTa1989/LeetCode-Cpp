/*Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

Example 1:
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/

/* Solution 1
The solution makes use of a hashMap and works in a single pass.
The solution section gives something that is confusing for me so here is a more understandable solution:

curr_sum here is denoting the traditional cumulative sum at any point during the traversal of the arrray
Now curr_sum%k at any point gives the remainder,this can either be 0 or any other number.
Whatever the remainder is we are simply putting in the map thereby preparing a mapping of all the possible remainders from all the possible sum and storing their frequency as the values.
The only thing and the most important this is to understand why this line of code works and why it gives the desired outputs.
if(mp.find(rem)!=mp.end())
count+=mp[rem];
We are increasing the count by the number of times the given remainder has been seen.
I am considering it a fact that :
If the remainders of array upto i and array upto j are equal (ri=rj),
then subarray from i to j has a remainder of 0,
which means It's the type of subarrays we're looking for!
Look here: https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/413234/DETAILED-WHITEBOARD!-BEATS-100-(Do-you-really-want-to-understand-It)
Now lets dry run the code with this concept to drill it in.

A = [4,5,0,-2,-3,1], K = 5
A = 4, curr_sum = 4, curr_sum%K = 4 map now is: 0-->1, 4-->1 RESULT: []

A = 5, curr_sum = 9, curr_sum%K = 4 map now is: 0-->1, 4-->2 So this means we found a remainder that was already there! count+=1 RESULT: ([5], ) 
(added one more)

A = 0, curr_sum = 9, curr_sum%K = 4 map now is: 0-->1, 4-->3 So this means we found a remainder that was already there! count+=2 RESULT: ([5,0], [5], [0]) 
(added two more)

A = -2, curr_sum = 7, curr_sum%K = 2 map now is: 0-->1, 4-->3, 2-->1
RESULT: ([5,0], [5], [0])

A = -3, curr_sum = 4, curr_sum%K = 4 map now is: 0-->1, 4-->4, 2-->1 So this means we found a remainder that was already there! count+=3 
RESULT: ([5,0], [5], [0], [5,0,-2,-3], [0,-2,-3], [-2,-3]) (added three more)

A = 1, curr_sum = 5, curr_sum%K = 0 map now is: 0-->2, 4-->4, 2-->1 So this means we found a remainder that was already there! count+=1 
RESULT: ([5,0], [5], [0], [5,0,-2,-3], [0,-2,-3], [-2,-3], [4,5,0,-2,-3,1]) (added one more)
*/
//Runtime: 132 ms, faster than 21.22% of C++ online submissions for Subarray Sums Divisible by K.
//Memory Usage: 31.9 MB, less than 8.33% of C++ online submissions for Subarray Sums Divisible by K.
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        if(n==0) return 0;
        
        int i = 0, count = 0;
        int curr_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        
        while(i<n)
        {
            curr_sum+= A[i++];
            int rem = curr_sum % K;
            if(rem<0) rem += K;
            
            if(mp.find(rem)!=mp.end())
                count+=mp[rem];
            
            mp[rem]++;
            
        }
        return count;
    }
};

/*Intuition
If we have a prefix sums array S where S[i] is the sum of all elements from 0..i, we know that we can get the sum of any subarray A[i..j] 
by S[j+1]-S[i-1] (from the first problem).

If we want to figure out if A[i..j] is divisible by k, all we have to do is check for A[i..j] % k == 0. This means anytime S[j+1] % k == S[i-1] % k, 
then everything in between must be divisible by k i.e. A[i..j] % k == 0.

Caveat (C++)
% is remainder operator in C++ (and not a proper modulus). To get a positive number, we have to add by the base: a mod b = ((a % b) + b) % b.

Solution
Look for anytime S[j+1] % k == S[i-1] % k and you know everything in between [i...j] must be divisible by K!!*/

//Runtime: 272 ms, faster than 5.24% of C++ online submissions for Subarray Sums Divisible by K.
//Memory Usage: 32.1 MB, less than 8.33% of C++ online submissions for Subarray Sums Divisible by K.
class Solution {	//Time Complexity: O(N), Space: O(N)
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int N = A.size();
        int sum = 0; // running prefix sum
        map<int,int> seen; // num -> count
        seen[0] = 1;
        int total = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            int target = ((sum % K) + K) % K;
            if (seen.count(target) > 0) {
                total += seen[target];
            }
            if (seen.count(target) > 0) {
                seen[target]++;
            } else {
                seen[target] = 1;
            }
        }
        return total;
    }
};
