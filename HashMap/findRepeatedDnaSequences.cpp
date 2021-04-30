//https://leetcode.com/problems/repeated-dna-sequences/discuss/53878/Short-8-lines-C%2B%2B-O(n)-solution

vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> res;
	unordered_map<string, int> m;
	
	for(int i = 0; i<s.length() - 9; i++)
	{
		string seq = s.substr(i, 10);
		m[seq]++;
		if(m[seq] > 1)
			res.push_back(seq);
	}
	return res;
}