/*Given an array of integers arr and two integers k and threshold.
Return the number of sub-arrays of size k and average greater than or equal to threshold.

Example 1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. 
All other sub-arrays of size 3 have averages less than 4 (the threshold).

Example 2:
Input: arr = [1,1,1,1,1], k = 1, threshold = 0
Output: 5	*/
class Solution {
public:
   int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      double sum = 0;
      double div = k;
      int n = arr.size();
      for(int i = 0; i < k; i++){
         sum += arr[i];
      }
      int ret = 0;
      for(int i = 0, j = k; j < n; i ++, j++){
         if(sum / div >= threshold ){
            ret++;
         }
         sum -= arr[i];
         sum += arr[j];
      }
      if(sum / div >= threshold ){
         ret++;
      }
      return ret;
   }
};
//
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
  threshold *= k;
  int sum = accumulate(arr.begin(), arr.begin() + k, 0);
  int result = (sum >= threshold);
  for (int i = k; i < arr.size(); ++i) {
    sum += arr[i] - arr[i-k];
    result += (sum >= threshold);
  }
  return result;
}
};

//https://zxi.mytechroad.com/blog/sliding-window/leetcode-1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
      sum += arr[i];
      if (i + 1 >= k) {
        if (threshold * k <= sum) ++ans;
        sum -= arr[i + 1 - k];
      } 
    }
    return ans;
  }
};