/*Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
You may return any answer array that satisfies this condition.

Example 1:
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i,j=1,n=A.size();
        for(i=0;i<n;i+=2)
        {
            if(A[i]%2)
            {
                while(A[j]%2)
                    j+=2;
                swap(A[i],A[j]);
            }   
        }
        return A;
    }
};
//
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
	int oddIndex = 1, evenIndex = 0;
	vector<int> res(A.size());
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] % 2 == 0)
		{
			res[evenIndex] = A[i];
			evenIndex += 2;
		}
		else
		{
			res[oddIndex] = A[i];
			oddIndex += 2;
		}
	}
	return res;
}
};