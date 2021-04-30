//the PeakElement is the largest in the neighbor,when our elment is small than the next one it means that the
//peak is in the [mid+1,left],else the peak is in the [right,mid].

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0;
        int right = num.size()-1;
        while(left<right){
            int mid = left + (right - left)/2;
            if(num[mid]<num[mid+1]){
                left = mid+1;
            }
            else right = mid;
        }
        return left; // or right is ok
    }
};

//https://zxi.mytechroad.com/blog/algorithms/binary-search/%e8%8a%b1%e8%8a%b1%e9%85%b1-leetcode-162-find-peak-element/
//Time complexity: O(logn)
//Space complexity: O(1)
class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int l = 0, r = num.size() - 1; // preventing OOB
    while (l < r) {
      int m = l + (r - l) / 2;
      // Find the first m s.t. num[m] > num[m + 1]
      if (num[m] > num[m + 1])
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};