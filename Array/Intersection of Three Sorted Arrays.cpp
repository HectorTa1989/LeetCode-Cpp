//Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
//Output: [1,5]

class Solution {
public:

void count(map<int, int>& freq, vector<int> v)
{
	for(int x : v)
		freq[x]++;
}

vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
	map<int, int> freq;
	vector<int> res;
	count(freq, arr1);
	count(freq, arr2);
	count(freq, arr3);
	
	for(pair<int, int> p : freq)
	{
		if(p.second == 3)
			res.push_back(p.first);
	}
	return res;
}
};