/*Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums, vector<pair<int, int>> v = {}) {
	for (int i = 0; i < nums.size(); ++i) v.push_back({nums[i], i});
	sort(begin(v), end(v), greater<pair<int, int>>());
	vector<string> res (v.size());
	for (int i = 0; i < v.size(); ++i) 
		res[v[i].second] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i + 1);
	return res;
}
};