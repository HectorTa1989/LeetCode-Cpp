/*Given an int array nums and an int target. 
Find two integers in nums such that the sum is closest to target.

Example 1:

Input: nums = [1, 2, 3, 4, 5], target = 10
Output: [4, 5]
Example 2:

Input: nums= [-1, 2, 1, -4], target = 4
Output: [2, 1]
*/
pair<int,int> minLeft(vector<int>& A, int C) {
   sort(A.begin(),A.end());
   int N=A.size();
   assert(N>1);
   int left=0,right=N-1;
   int minSpace=INT_MAX,bestLeft=0,bestRight=0;
   while(left<right) {
      int sum = A[left]+A[right];
      if(sum>C)right--;
      else {
         if(C-sum<minSpace) {
            minSpace=C-sum;
            bestLeft = left;
            bestRight = right;
         }
         left++;
      }
   return {A[bestLeft],A[bestRight]};
}