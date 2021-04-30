//recursive
class Solution {
private:
    void search(int left, int right, string path, vector<string>& v) {
        if(!left && !right) { v.push_back(path); return ; }
        if(left > 0) search(left-1, right, path+"(", v);
        if(left < right) search(left, right-1, path+")", v);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        search(n, n, "", v);
        return v;
    }
};

//backtracking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allComb;
        string comb;
        findParenthesis(n, 0, 0, comb, allComb);
        return allComb;
    }
    
    void findParenthesis(int n, int nleft, int nright, string &comb, vector<string> &allComb) {
        if(nleft==n && nright==n) {
            allComb.push_back(comb);
            return;
        }
        
        if(nleft<n) {
            comb.push_back('(');
            findParenthesis(n, nleft+1, nright, comb, allComb);
            comb.pop_back();
        }
        
        if(nright<nleft) {
            comb.push_back(')');
            findParenthesis(n, nleft, nright+1, comb, allComb);
            comb.pop_back();
        }
    }
};

//DP
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< vector<string> > dp(n+1, vector<string>());
        dp[0].push_back("");
        for(int i=1; i<=n; ++i){
            for(int k=0; k<i; ++k){
                for(string s1: dp[k]){
                    for(string s2: dp[i-1-k])
                        dp[i].push_back("("+s1+")"+s2);
                }
            }
        }
        return dp[n];
    }
};

//Recursive (backtracking)
//We use l and r to denote the number of (s and )s. If l < n, we can add a (. If r < l, we can add a ).

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parens;
        string paren;
        generate(n, 0, 0, paren, parens);
        return parens;
    }
private:
    void generate(int n, int l, int r, string paren, vector<string>& parens) {
        if (l == n && r == n) {
            parens.push_back(paren);
        } else {
            if (l < n) {
                generate(n, l + 1, r, paren + '(', parens);
            }
            if (r < l) {
                generate(n, l, r + 1, paren + ')', parens);
            }
        }
    }
};

//Iterative
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (!n) {
            return {""};
        }
        vector<string> parens;
        for (int i = 0; i < n; i++) {
            for (string l : generateParenthesis(i)) {
                for (string r : generateParenthesis(n - 1 - i)) {
                    parens.push_back('(' + l + ')' + r);
                }
            }
        }
        return parens;
    }
};