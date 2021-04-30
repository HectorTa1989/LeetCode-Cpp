/*Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, 
and B[j] is the size of the j-th bar of candy that Bob has.
Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

Example 1:
Input: A = [1,1], B = [2,2]
Output: [1,2]

Example 2:
Input: A = [1,2], B = [2,3]
Output: [1,2]

Example 3:
Input: A = [2], B = [1,3]
Output: [2,3]

Example 4:
Input: A = [1,2,5], B = [2,4]
Output: [5,4]
 
Note:
1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
It is guaranteed that Alice and Bob have different total amounts of candy.*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector <int> ans;
        int aSum,bSum;
        aSum = bSum = 0;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        aSum = accumulate(A.begin(),A.end(),0);
        bSum = accumulate(B.begin(),B.end(),0);
        int target = (aSum-bSum)/2;
        
        
            for(int i=0;i<A.size();i++)
            {
               // here apply binary search on B
                int left = 0;
                int right = B.size()-1;
                while(left<=right)
                {
                    int mid = (left+right)/2;
                    
                    if(B[mid]==A[i]-target)
                    {
                        ans.push_back(A[i]);
                        ans.push_back(B[mid]);
                        return ans;
                    }else if(A[i]-target<B[mid]){
                        right = mid -1;
                    }else{
                        left = mid+1;
                    }
                }
            }
        
                 
        return ans;         
    }
};
//Using bitset for marking all items in array A.
//After we calculate difference between sum of all elements in array A and array B
//We calculate diff=half of sums difference.
//After we just find such b in B so there exist a in A that b - a = diff => b - diff = a, in other words we are checking dict[a] or dict[b - diff].
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sizeA = 0, sizeB = 0;
        bitset<100001> dict(0);
        for (int a: A) {
            sizeA += a;
            dict.set(a);
        }
        for (int b: B) sizeB += b;
        
        int diff = (sizeB - sizeA) / 2, num;
        for (int b: B) {
            num = b - diff;
            if (num > 0 && num <= 100000 && dict[num])
                return vector<int> {b - diff, b};
        }
        return vector<int> {};
    }
};