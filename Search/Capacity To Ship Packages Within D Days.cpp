//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
/*A conveyor belt has packages that must be shipped from one port to another within D days.

The i-th package on the conveyor belt has a weight of weights[i].  Each day, we load the ship with packages on the conveyor belt 
(in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: 
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like 
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed. 

Example 2:
Input: weights = [3,2,2,4,1,4], D = 3
Output: 6
Explanation: 
A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4*/

//https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-1011-capacity-to-ship-packages-within-d-days/
// Author: Huahua, running time: 52 ms, 11.9 MB
//Time complexity: O(n * log(sum(weights))
//Space complexity: O(1)
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int D) {
    int l = *max_element(begin(weights), end(weights));
    int r = accumulate(begin(weights), end(weights), 0) + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int d = 1;
      int t = 0;
      for (int w : weights)
        if ((t += w) > m) {
          t = w;
          ++d;
        } 
      d > D ? l = m + 1 : r = m;        
    }
    return l;
  }
};
//96ms
//If we have unlimited days, the answer will be max(weights).
//If we just have one day, the answer will be sum(weights).
//Now, we have an interval between max(weights) and sum(weights).
//sorted list or interval => we can use the binary search!
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        if(weights.empty() || D == 0) return 0;
        int left = 0, right = 0;
        for(auto w: weights) left = max(left, w), right += w;
        if(D == weights.size()) return left;
        while(left < right) {
            int mid = (left + right) / 2;
            int curr_days = 1, curr_bagsize = 0;
            for(auto w : weights) {
                if(curr_bagsize + w > mid) { //exceeds our current bag limit i.e mid
                    //add further weights to the next bag
                    //and test if it fits within the given D days
                    curr_days++; curr_bagsize = 0;
                }
                curr_bagsize += w;
            }
            if(curr_days > D) left = mid + 1; //we need bigger bag sizes to accomodate
            else right = mid; //lets test smaller bag sizes as it looks we've maybe got some extra space OR right is the answer itself
        }
        return left;
    }
};
/*
RT : Time - O(w lg n) -> where n == totalSum - maxEl; w = no. of weights
(in every binary search we move left/right based upon the caclulations in our for loop which
takes O(w) time)
Space : O(1) -> inplace
*/

//Solution 2 : 1952ms
//http://programmersought.com/article/33091105999/;jsessionid=DA438F501E4C52D316E894FE358105AC
//This question is also quite simple. First, the direct double for loop can judge the result, but the maximum value of the data is estimated to time out.
//So you should think about the maximum value of the array first, and then try again and again, not one.
//It should be noted that you may forget to add one to the number of days when processing the last item.

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int len=weights.size();
        int num=0,sum=0;
        for(int i=0;i<len;i++){
            if(weights[i]>num)num=weights[i];
        }
        while(true){
            sum=0;
            int b=weights[0];
            for(int i=1;i<len;i++){
                if(b+weights[i]<=num)b+=weights[i];
                else{
                    b=weights[i];
                    sum++;
                    if(sum>D){
                        num++;
                        break;
                    }
                }
                if(i==len-1){//The last item is being processed at this time, so whether or not b exceeds num, sum has to add one.
                    sum++;
                    if(sum>D){
                        num++;
                        break;
                    }
                }
            }
            if(sum<=D)return num;
        }
    }
};