/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
class Solution {
	private:
	vector<vector<int>> res;
public:
	void dfs(int k, int n, int idx, vector<int> path){
		if(k==0){
			res.push_back(path);
		}
		else{
			for(int i=idx+1;i<=n;i++){
				path.push_back(i);
				dfs(k-1,n,i,path);
				path.pop_back();
			}
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> path;
		dfs(k,n,0,path);
		return res;
	}
};

//Iterative
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >results;
        vector<int> res(k,0);
        int level = 0;
        int maxLevel = k-1;
        int level0_Max = n - k + 1;
        while(level >= 0){
            if(++res[level] > level0_Max + level)
                level--;
            else if(level == maxLevel)
                results.push_back(res);
            else{
                res[level+1] = res[level];
                level++;
            }
        }
        return results;
    }
};

//Let C(n,k) be the number of combinations to choose k elements out of n elements. Then there are only two cases:

element n is chosen: so we only need to choose k-1 out of first n-1 and there are C(n-1,k-1) combinations.
element n is not chosen: so we need to choose k out of first n-1 and there are C(n-1,k) combinations.
So we have equality C(n,k) = C(n-1,k-1)+C(n-1,k).

vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k == 1) { // base case
            for (int i = 1; i <= n; ++i) res.push_back({i});
            return res;
        } 
        else if (k == n) { // base case
            res.resize(1);
            for (int i = 1; i <= n; ++i) res[0].push_back(i);
            return res;
        }
        
        res = combine(n-1,k); // all combinations without n
        auto tmp = combine(n-1,k-1);
        for (auto& x:tmp) x.push_back(n); // all combinations with n
        res.insert(res.end(), tmp.begin(), tmp.end());
        return res;
    }
	
//
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k > n)
                return ans;

        vector<int> v(k, 0);
        for (int iii = 0; iii < k; iii++)
                v[iii] = iii + 1;
        ans.push_back(v);

        while (1) {
                bool finish = true;
                for (int iii = 0; iii < v.size(); iii++) {
                        if (v[iii] != n - k + iii + 1) {
                                finish = false;
                                break;
                        }
                }
                if (finish) {
                        return ans;
                }

                for (int iii = v.size() - 1; iii >= 0; iii--) {
                        if (v[iii] != n - k + iii + 1) {
                                v[iii]++;
                                for (int jjj = iii + 1; jjj < v.size(); jjj++) {
                                        v[jjj] = v[jjj - 1] + 1;
                                }
                                ans.push_back(v);
                                break;
                        }
                }

        }
    }
};