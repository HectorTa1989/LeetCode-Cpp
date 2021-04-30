//https://www.tutorialspoint.com/minimum-increment-to-make-array-unique-in-cplusplus
//Suppose we have an array of integers A, here a move consists of choosing any A[i], and incrementing it by 1. 
//We have to find the least number of moves to make every value in A unique. So if the input is like [3,2,1,2,1,7], 
//then the output will be 6, as after 6 moves, the array could be [3,4,1,2,5,7], it can be shown with 5 or less moves that 
//it is impossible for the array to have all distinct values.
class Solution {
   public:
   int minIncrementForUnique(vector<int>& A) {
      int ret = 0;
      sort(A.begin(), A.end());
      set <int> visited;	//create one set called visited to keep track which value is considered before
      for(int i = 1; i < A.size(); i++){
         if(A[i] <= A[i - 1]){
            ret+= (A[i - 1] + 1) - A[i];
            A[i] = A[i - 1] + 1;
         }
      }
      return ret;
   }
};
//Method 2
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int sum = 0, next = 0;
        sort(A.begin(), A.end());
        for(int n : A){
            sum += max(next - n, 0);
            next = max(next, n) + 1;
        }
        return sum;
    }
};

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int from, diff, sum, prev;
        queue<int> dup;
        sort(A.begin(), A.end());
        
        //將重複的elements加入至queue
        sum = 0;
        prev = INT_MIN;
        for(int n : A){
            if(prev == n) dup.push(n);
            prev = n;
        }
        
        //在兩個數字中間找到空數字
        prev = INT_MIN;
        for(int n : A){
            if(prev != n && prev + 1 != n && prev != INT_MIN){
                for(from = prev + 1;!dup.empty() && from < n && from > dup.front();from++)
                    sum += abs(from - dup.front()), dup.pop();
                if(dup.empty()) 
                    break;
            }
            prev = n;
        }
        
        prev++;
        //若queue還有重複的elements，則以陣列當中最後一個數字的+1
        //開始做差值相加
        while(!dup.empty()){
            sum += prev - dup.front(), prev++;
            dup.pop();
        }
        
        return sum;
    }
};
