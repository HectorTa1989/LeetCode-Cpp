/*Given an array of integers and a number k, find the maximum sum of a subarray of size k.

Eg: For given array A[] = {10,30,20,50,60,40,40} of size k = 2
The maximum sum subarray would be
sum = 50 + 60 = 100.*/

int MaxSumSubarray(vector<int> v, int k)
{
	int start = 0, sum = 0, n = v.size();
	int windowSum = 0;
	for(int end = 0; end < n; end++)
	{
		windowSum += v[end];
		if(end >= k-1)
		{
			sum = max(sum, windowSum);
			windowSum -= v[start++];
		}
	}
	return sum;
}