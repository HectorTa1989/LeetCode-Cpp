int repeatedNTimes(vector<int> v)
{
	sort(v.begin(), v.end());
	if(v[0] == v[v.size()/2 - 1];
		return v[v.size()/2 - 1];
	v[v.size()/2];
}


// Method 2
/* We know there is an element - x - that appears N times in array of size 2N.
Let us consider the average gap between consecutive x's.
Suppose the indexes of all x's is [a1<a2,...<aN]
Then the average gap is [(a2-a1)+(a3-a2)+...(aN-a(N-1))] / (N-1)
= [aN-a1]/(N-1)<= (2N-1)/(N-1) <= 3
Therefor there must exists 2 x's such that their gap is at most 3. */

int repeatedNTimes(vector<int> v)
{
	for(int k = 1; k <= 3; k++)
	{
		for(int i = 0; i < v.size() - k; i++)
		{
			if(v[i] == v[i+k])
				return v[i];
		}
	}
}