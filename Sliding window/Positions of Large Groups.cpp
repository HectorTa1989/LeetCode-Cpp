/*In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.

Example 1:
Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.

Example 2:
Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.*/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int fast = 0, slow = 0;
        while (fast < S.size()) {
            while (S[fast] == S[slow]) fast++;
            if (fast - slow >= 3) ans.push_back({slow, fast-1});
            slow = fast;
        }
        return ans;
    }
};

//Runtime: 4 ms, faster than 98.57% of C++ online submissions for Positions of Large Groups.
//Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Positions of Large Groups.
vector<vector<int>> largeGroupPositions(string S) {
        
        int n = S.length();
        
        vector<vector<int>> res;
        vector<vector<int>> :: iterator it;
        
        for(int i=0; i<n-1; i++)
        {
            if(S[i] == S[i+1])
            {
                int start = i;
                int end;
                while(S[i] == S[start])
                    i++;
                i--;
                end = i;
                
                if(end - start + 1 >= 3)
                { 
                    vector<int> newEntry{start, end};
                    res.push_back(newEntry);
                }
            }
        }
        
        return res;
    }
//
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int idx = 0, count = 1;
        vector<vector<int>> result;
        
        for(int i = 0; i < S.length() - 1; i++){
            if(S[i] == S[i + 1]){
                count++;
                if(i == S.length() - 2){
                    if(count >= 3) result.push_back({idx, i + 1});
                }
            }
            else {
                if(count >= 3) result.push_back({idx, i});
                idx = i + 1;
                count = 1;
            }
        }
        
        return result;
    }
};