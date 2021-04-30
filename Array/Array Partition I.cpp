/*Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) 
which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sz= nums.size();
        if(sz==2) return min(nums[0],nums[1]);
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<sz; i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};

//156ms
class Solution {
public:
    int minNum(int a, int b){
        if(a > b) return b;
        else return a;
    }
    
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int x = 0; x < nums.size(); x += 2){
            count += minNum(nums[x], nums[x+1]);
        }
        
        return count;
    }
};

//176~244 ms
class Solution {
public:
    int arrayPairSum(vector<int>& num)
    {
        int maxSum=0;
        // sorting the array
        sort( num.begin(), num.end() );
        
        // summing the first member of the pair and returning it
        for(int i=0; i< num.size(); i+=2)
            maxSum += num[i];
        
        return maxSum;
        
        /*
            Example= [1,4,3,2]
            sorting= [1,2,3,4]
            min of (1,2) and (3,4) is 1 and 3
            and then we find the sum of both = 1+3 = 4 which is the answer
        */
    }
};