class Solution {
   public:
   int maxWidthRamp(vector<int>& A) {    
      int n = A.size();
      int ret = 0;
      stack <int> st;
      for(int i = 0; i < n; i++){
         if(st.empty() || A[st.top()] > A[i]){
            st.push(i);
         }
      }
      for(int i = n - 1; i > ret; i--){
         while(!st.empty() && A[st.top()] <= A[i]){
            ret = max(ret, i - st.top());
            st.pop();
         }
      }
      return ret;
   }
};