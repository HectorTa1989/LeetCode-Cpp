class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
		int n = A.size();
		vector<int> res(n);
		int l = 0, r = n - 1;
		for(int k = n - 1; k >= 0; k--)
		{
			if(abs(A[r]) > abs(A[l]))
				res[k] = A[r]*A[r--];
			else
				res[k] = A[l]*A[l++];
		}
		return res;
	}
};