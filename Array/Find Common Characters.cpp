/*Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  
For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
You may return the answer in any order.

Example 1:
Input: ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: ["cool","lock","cook"]
Output: ["c","o"]*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        map<char,int> ans;
        for(auto ch: A[0]){
            ans[ch]++;
        }
        map<char,int>cur;
        for(auto& word:A){
            cur.clear();
            for(auto ch:word){
                cur[ch]++;
            }
            for(auto& it:ans){
                it.second = min(it.second,cur[it.first]);
            }
        }
        vector<string> sol;
        string s;
        for(auto& it:ans){
            while(it.second!=0){
                s=it.first;
                sol.push_back(s);
                it.second--;
            }
        }
        return sol;
    }
};
//
/*
O(N*K + 26*N) = O(N)
S(N*26) = S(N)
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // first round, count frequency of 26 characters of each string
        // O(N*K), N : number of strings, K: max size of a string
        vector<vector<int>> ctr(A.size(), vector(26, 0));
        for(int i = 0; i < A.size(); ++i) {
            for(char &c : A[i]) {
                ctr[i][c - 'a'] += 1;
            }
        }
        // second round, find out all duplicate numbers and append to the output vector
        // O(26*N) 
        vector<string> res;
        for(int i = 0; i < 26; ++i) {
            int temp = INT_MAX;
            for(int j = 0; j < A.size(); ++j) {
                temp = min(temp, ctr[j][i]);
            }
            for(int k = 0; k < temp; ++k) {
                char t = 'a' + i;
                res.push_back(string(1,t));
            }
        }
        return res;
    }
};


// optimization, O(n), s(1)

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // S(26) = S(1)
        vector<int> global_ctr(26, INT_MAX);
        
        // O(N*K) + O(N*26) = O(N)
        for(string &s : A) {
            vector<int> local_ctr(26, 0);
            // O(K) for each string
            for(char &c : s) {
                ++local_ctr[c - 'a'];
            }
            // O(26) to update global_ctr
            for(int i = 0; i < 26; ++i) {
                global_ctr[i] = min(global_ctr[i], local_ctr[i]);
            }
        }
        
        // O(26)
        vector<string> res;
        for(int i = 0; i < 26; ++i) {
            vector<string> temp(global_ctr[i], string(1, 'a' + i));
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};

//Essentially, We can create a matrix of size(numberOfString by 26), where 26 means 26 characters in alphabet.

Then, we can count the number of occurences of each character in each string and store them in the matrix.

Lastly, for each character, find the minimum frequency of each character across all strings.

i.e. ["abb","aba","aaa"]
For String::abb, the frequences are:
a => 1;
...

For String::aba, the frequences are:
a => 2;
...

For String::aaa, the frequences are:
a=> 3;
...

Once we find out that for character 'a', the minimum frequency if 'a' across all strings is 1. 
Which means we need to add one 'a' to the list of chars that are common across all strings.

Adding one 'a' to the list of chars that are common across all strings is because every other string MUST HAS at least 1 'a' in their string.

class Solution {
public:
    vector<string> commonChars(vector<string>& A) 
    {
		// Frequency of each char in each string.
        int freq[A.size()][26] = {0};
		
		// A list of common chars across all strings.
        vector<string> common;
        
        // Count the frequency of each char from each string.
        for (int idx = 0; idx < A.size(); ++idx)
        {
            for (auto ch : A[idx])
            {
                freq[idx][ch - 'a']++;
            }
        }
        
        for (char ch = 0; ch < 26; ++ch)
        {
			// Minimum frequency of current char. 100 comes from question assumption.
            int minFreq = 100;
			
            for (int idx = 0; idx < A.size(); ++idx)
            {
                if (minFreq > freq[idx][ch])
                {
                    minFreq = freq[idx][ch];
                }
            }
            
			// Append minFreq number of chars to the 'common' vector.
            for (int idx = 0; idx < minFreq; ++idx)
            {
                common.push_back(string(1, ch + 'a'));
            }
        }
        
        return common;
        
    }
};