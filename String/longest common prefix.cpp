string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";
        if(strs.empty()) return prefix;
        for(int j = 0; j < strs[0].length(); ++j)
        {
            for(int i = 1; i < strs.size(); ++i){
                if(j >= strs[i].size() || strs[i][j] != strs[0][j])
                   return prefix;
            }
            prefix += strs[0][j];	// prefix.push_back(strs[0][i]);
        }
        return prefix;
    }

//by megatron99
//We first sort the array of strings.
//Then, we choose the first and last string in the array. [They are supposed to be the most different among all the pairs of strings in the sorted array]
//We just compare how many common characters match from index i = 0 of these two strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        if(n==0) return "";
        
        string ans  = "";
        sort(begin(str), end(str));
        string a = str[0];
        string b = str[n-1];
        
        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            }
            else{
                break;
            }
        }
        
        return ans;
        
    }
};
//by zefengsong	
//Solution 1

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(auto s: strs) res = match(res, s);
        return res;
    }
    
    string match(const string& pre, const string& s){
        int i = 0, len = min(pre.size(), s.size());
        for(; i < len; i++) if(s[i] != pre[i]) break;
        return pre.substr(0, i);
    }
};
//Solution 2

Using sort and only compare the first string with the last string.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs.back();
        int i = 0;
        for(; i < min(a.size(), b.size()); i++) if(a[i] != b[i]) break;
        return a.substr(0, i);
    }
};