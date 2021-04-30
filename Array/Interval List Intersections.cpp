/*Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  
The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)*/

vector<vector<int>> res;
for(int i = 0, j = 0; i < A.size() && j < B.size();) {
	int lo = max(A[i][0], B[j][0]), hi = min(A[i][1], B[j][1]);
	if(lo <= hi) res.push_back({lo, hi});
	if(hi == A[i][1]) i++;
	else j++;
}
return res;

//
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
       // merge(intA, intB) = max(intA[0], intB[0]), min(intA[1], intB[1]);
        
        int i=0, j=0;
        int N = A.size(); int M = B.size();
        
        vector<vector<int>> result;
          
        while(i<N && j<M){
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            
            if(start <= end) result.push_back(vector<int>{start, end});
            A[i][1] > B[j][1] ? j++: i++;
        }
        
        
        return result;
        
    }

//Time complexity: O(m + n)
//Space complexity: O(m + n)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> result {};
        
        while (i < A.size() && j < B.size()) {
            const auto& interval_0 = A[i];
            const auto& interval_1 = B[j];
            
            // check for intersection
            if (interval_1[0] <= interval_0[1] && interval_1[1] >= interval_0[0]) {
                int start = max(interval_0[0], interval_1[0]);  // get max lower-bound
                int end = min(interval_0[1], interval_1[1]);  // get min upper-bound
                
                // insert result, use emplace_back for in-place construction
                result.emplace_back(vector<int>({start, end}));
            }
            
			// move to the next potential intersection
            interval_0[1] < interval_1[1] ? ++i : ++j;
        }
        
        return result;  
    }
};