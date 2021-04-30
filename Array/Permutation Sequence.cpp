/*The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"*/

//since n will be between 1 and 9 inclusive. pre-calculate the factorials is faster.
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // {1,1,2, 2*3, 6*4, 24*5...}
		//static const  int factor[] = {1,1,2,6,24,120,720,720*7,720*7*8}; //n!
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }
        return res;
    }
};

//
string getPermutation(int n, int k) {
    int pTable[10] = {1};
    for(int i = 1; i <= 9; i++){
        pTable[i] = i * pTable[i - 1];
    }
    string result;
    vector<char> numSet;
    numSet.push_back('1');
    numSet.push_back('2');
    numSet.push_back('3');
    numSet.push_back('4');
    numSet.push_back('5');
    numSet.push_back('6');
    numSet.push_back('7');
    numSet.push_back('8');
    numSet.push_back('9');
    while(n > 0){
        int temp = (k - 1) / pTable[n - 1];
        result += numSet[temp];
        numSet.erase(numSet.begin() + temp);
        k = k - temp * pTable[n - 1];
        n--;
    }
    return result;
}

//Since n! = n * (n-1)! we can imagine that the possible permutations are divided into n groups of size (n-1)! each
//Now we have to find the right group where kth permutation exists which we find by using int idx = k % f == 0 ? k/f - 1 : k/f;
//Now within the group of (n-1)! total permutations we want to find k = k-(idx*f); th permutation and for that we apply the same logic again
class Solution {
public:
    int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    
    string getPermutation(int n, int k) {
        
        string temp = "";
        for(int i=1; i<=n; i++){
            temp += '0'+i;
        }
  
        vector<int> indices;
        
        while(n){
            int f = fact[n-1];
            int idx = k % f == 0 ? k/f - 1 : k/f;
            k = k-(idx*f);
            n--;
            indices.push_back(idx);
        }
        
        string ans = "";
        for(int i : indices){
            ans += temp[i];
            temp.erase(i,1);
        }
        
        return ans;
    }
};

//I want to use nextPermutation in the begining, then it comes to me that this problem is just a simple calculation. 
//You can store all numbers(from 1 to n) and print them into the string according the value of k. For example, for n=3, you have three numbers: 1, 2, 3 . 
//If (k-1)/(2!)=1，corresponding to k=3,k=4, you must have the first number to be 2, which is nums[1]. You can keep doing this and removing from the stored numbers. 
//The numbers are sorted in the begining, so you can get the number in O(n) time.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        string s;
        if(n==0) return s;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        if(k==0){
            for(int i=0;i<n;i++)
                s.push_back(nums[i]);
            return s;
        }
        k--;
        while(s.size()!=n){
            int base=1;
            for(int i=nums.size()-1;i>0;i--)
                base*=i;
            int a=k/base;
            k=k%base;
            s.push_back('0'+nums[a]);
            nums.erase(nums.begin()+a);
        }
        return s;
    }
};

//zefengsong
Solution 1. Backtracking
Run Time: 266ms

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "", res = "";
        for(int i = 1; i <= n; i++) s.push_back(i + '0');
        string path = s;
        int count = 0;
        DFS(s, 0, count, n, k, path, res);
        return res;
    }
    
    void DFS(string& s, int pos, int& count, int n, int k, string& path, string& res){
        if(count >= k || pos == n){
            if(++count == k) res = path;
            return;
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '0') continue;
            path[pos] = s[i];
            s[i] = '0';
            DFS(s, pos + 1, count, n, k, path, res);
            s[i] = path[pos];
        }
    }
};
Solution 2. Using STL
Run Time: 119ms

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++) s.push_back(i + '0');
        while(--k) next_permutation(s.begin(), s.end());
        return s;
    }
};
Solution 3. Math. C++ version of this thread

Run Time: 3ms

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "", res = "";
        vector<int>factorial(n + 1, 1);
        int sum = 1;
        for(int i = 1; i <= n; i++){
            s.push_back(i + '0');
            sum *= i;
            factorial[i] = sum;
        }
        k--;
        for(int i = 1; i <= n; i++){
            int index = k / factorial[n - i];
            res.push_back(s[index]);
            s.erase(s.begin() + index);
            k %= factorial[n - i];
        }
        return res;
    }
};