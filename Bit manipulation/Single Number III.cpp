/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear 
exactly twice. Find the two elements that appear only once.

Example:
Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x_xor_y = 0;
    for (int n: nums) {
        x_xor_y ^= n;
    }
    // find the last set bit - 
    // The last bit that x =/= y
    int mask = x_xor_y & ~(x_xor_y - 1);
    int x = 0;
    int y = 0;
    // x: XOR of a,a,b,b,x
    // y: XOR of c,c,y
    for (int n: nums) {
        if (n & mask) {
            x ^= n;
        } else {
            y ^= n;
        }
    }
    return vector<int> {x, y};
    }
};
/*1.assume that A and B are the two elements which we want to find;

2.use XOR for all elements,the result is : r = A^B,we just need to distinguish A from B next step;

3.if we can find a bit '1' in r,then the bit in corresponding position in A and B must be different.
We can use {last = r & (~(r-1))} to get the last bit 1 int r;

4.we use last to divide all numbers into two groups,then A and B must fall into the two distrinct groups.
XOR elements in eash group,get the A and B.

[VISUALIZATION]
honestly, i really spent a lot of time to understand this. here is the visualization that i hope latecomers get the idea

first run ^ to get the a^b
search the position to do partitioning in binary representation of a^b
partition the array by this position and get a and b correspondingly
e.g. [1,2,1,3,2,5]

1 = 001
2 = 010
1 = 001
3 = 011
2 = 010
5 = 101

after 1st step, we found out that a^b = 3^5 = 6 which is 110
110 means that there are 2 digits on the left are different in binary representation of our result
let's use any one of the digit to partition our array

if we use the middle one, we can see that there are 2 sets of numbers that we can just use the simple single number to find out the single in each partition
1 = 001
1 = 001
5 = 101 ✅
2 = 010
2 = 010
3 = 011 ✅

if we use the leftmost one, we can still partition the array into the sets and do simple single number on it
1 = 001
2 = 010
1 = 001
3 = 011✅
2 = 010
5 = 101✅*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0, n = nums.size(), i = 0, last = 0;
        vector<int> ret(2, 0);
        
        for (i = 0; i < n; ++i) 
            r ^= nums[i];
        
        last = r & (~(r - 1));
        for (i = 0; i < n; ++i)
        {
            if ((last & nums[i]) != 0)
                ret[0] ^= nums[i];
            else
                ret[1] ^= nums[i];
        }
        
        return ret;
    }
};

/*In exercise Finding a Number That Appears Once in Array of Duplicated Numbers we have discussed a simple method to 
isolate one number which appears once when all other elements appear exactly twice. The solution was to XOR all the 
array elements. Since K XOR K is zero for any integer K, we are sure that all duplicated numbers will zero themselves 
out. The only number which does not cancel itself is the one which appears once. So the result of the operation is 
that one number.

However, this solution cannot be applied directly to finding two numbers that appear once each. Suppose that these 
numbers that appear once are J and K, and all other numbers appear twice. If we decide to XOR all the array's elements, 
the overall result would actually be J XOR K. Unfortunately, there is no way to extract J and K out of their XOR. 
But there is one thing that we can do. Since J and K are different, we are sure that J XOR K is different than zero. 
This information is valuable in sense that we know pieces of information that differ. If we pick up any bit that is 
1 in J XOR K, we can use it as a mask to test each element of the array. Obviously, that mask will be the discriminator 
between J and K - only one of them will have value 1 at that particular position.

Now that we have the mask with exactly one bit set to 1, we can walk through the array once again. But this time 
we are going to maintain two XORed results. One for numbers that have bit 1 at the mask's position and another for 
numbers that have bit 0 at that position. In this way, we are sure that all duplicates will go into the same pile. 
But likewise, we are sure that J and K will go into separate piles. The overall result is that the first XORed result 
will be equal to J and the second XORed result will be equal to K (or the other way around, but it really doesn't matter).*/
vector<int> singleNumber(vector<int>& A) {
    int n=A.size();
    int mask=1;
    int Xor=0;
    for(int i=0;i<n;i++)
    {
        Xor^=A[i];
        
    }
    
    while((Xor &mask)==0)
    {
        mask<<=1;
    }
    
    int j=0,k=0;
    
    for(int i=0;i<n;i++)
    {
        if((mask & A[i])==0) j^=A[i];
        else k^=A[i];
        
    }
    cout<<mask;
    
    vector<int>ans;
    ans.push_back(j);
     ans.push_back(k);
    return ans;
}
//
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0, mask = 1;
        for (int num: nums) {
            XOR ^= num;
        }
        while ((mask & XOR) == 0) {
            mask = mask<<1;
        }

        int a = 0, b = 0;
        for (int num: nums) {
            if (num & mask) a ^= num;
            else b ^= num;
        }
        return {a, b};
    }
};