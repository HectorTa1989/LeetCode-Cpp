/*Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)
Given an array A of integers, return the length of the longest mountain. 
Return 0 if there is no mountain.

Example 1:
Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:
Input: [2,2,2]
Output: 0
Explanation: There is no mountain.*/

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int i = 0;
        int start = 0;
        int peak = 0;
        int end = 0;
        int answer = 0;
        while(i + 1 < A.size())
        {
            // go to local min
            while(i + 1 < A.size() && A[i] > A[i + 1])
            {
                i++;
            }
            // record starting index
            start = i;
            // going up
            while(i + 1 < A.size() && A[i] < A[i + 1])
            {
                i++;
            }
            // record peak index
            peak = i;
            // going down
            while(i + 1 < A.size() && A[i] > A[i + 1])
            {
                i++;
            }
            //record end index
            end = i;
            // if start, peak, end, have different index, there is a mountain
            if(start != peak && peak != end)
            {
                answer = max(answer, i + 1 - start);
            }
            // if is flat, move one step
            if(i + 1 < A.size() && A[i] == A[i + 1])
            {
                i++;
            }
        }
        return answer;
    }
};

//three auxillary variables
class Solution {
public:
    int longestMountain(vector<int>& A) 
    {
        if (A.size() < 3)
            return 0;        
        A.push_back(10001);
		int p = 0, v = 0, m = 0;
		
        for (int i=1; i<A.size()-1; ++i)
        {
            p = A[i-1] < A[i] && A[i] > A[i+1] ? i : p;
            if (A[i-1] >= A[i] && A[i] <= A[i+1])
            {
                if (v < p)
                    m = max(i - v + 1, m);
                v = i;
            }
        }
		A.pop_back();
        return m;
	 }
};

//two auxillary variables + flag
class Solution {
public:
    int longestMountain(vector<int>& A) 
    {
        int p = 0, m = 0;
        bool asc = true;
                
        for (int i=1; i<A.size(); ++i)
        {
            if (i == p+1 && A[i] <= A[i-1])
                p++;
            else if (asc) 
            {
                if (A[i] == A[i-1]) 
                    p=i;
                else if (A[i] < A[i-1])                  
                    asc = false; 
            }
            else if (A[i] >= A[i-1])
            {
                asc = true;
                m = max(i-p, m);
                p = (A[i] >  A[i-1]) ? i-1: i;
            }
        }
            
        if (!asc) m = max(int(A.size())-p, m);     
        return m;
	 }
};

//Runtime: 40 ms, faster than 43.68% of C++ online submissions for Longest Mountain in Array.
//Memory Usage: 19.7 MB, less than 14.29% of C++ online submissions for Longest Mountain in Array.
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) return 0;
        
        vector<int> lr(A.size(), 1), rl(A.size(), 1);
        
        for(int i=1;i<A.size();i++) {
            if(A[i] > A[i-1]) {
                lr[i] = lr[i-1] + 1;
            }
            else {
                lr[i] = 1;
            }
        }        
        
        for(int i=A.size()-2;i>=0;i--) {
            if(A[i] > A[i+1]) {
                rl[i] = rl[i+1] + 1;
            }
            else {
                rl[i] = 1;
            }
        }
        
        int ans = 0;
        for(int i=0;i<A.size();i++) {
            int val = lr[i] + rl[i] - 1;
            if(val >= 3 && lr[i] >= 2 && rl[i] >= 2)
                ans = max(ans, val);
        }
        
        return ans;
    }
};