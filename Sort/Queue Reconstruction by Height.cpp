/*Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.
 
Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]*/

//DP
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        
        for (auto& v : people) {
            v[0] = -v[0];
        }
        sort(people.begin(), people.end());
        
        for (auto& v : people) {
            v[0] = -v[0];
            result.insert(result.begin() + v[1], v);
        }
        return result;
    }
};
//https://www.cnblogs.com/grandyang/p/5928417.html
// For each inserted person, it takes O(n) time to move the person behind him back one position, so it will take the O(n^2) time for all people.
class Solution {	
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};
//
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        for (int i = 0; i < people.size(); i++) {
            auto p = people[i];
            if (p[1] != i) {
                people.erase(people.begin() + i);
                people.insert(people.begin() + p[1], p);
            }
        }
        return people;
    }
};
/*Runtime: 280 ms, faster than 33.72% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for Queue Reconstruction by Height.*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++){
            res.insert(res.begin()+people[i][1], people[i]);
        }
        return res;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]>p2[0];
        else return p1[1]<p2[1];
    }
};

//Runtime: 76 ms, faster than 88.08% of C++ online submissions for Queue Reconstruction by Height.
//Memory Usage: 12 MB, less than 100.00% of C++ online submissions for Queue Reconstruction by Height.
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](auto&a,auto&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<vector<int>>sol(people.size(),vector<int>(2,-1));
        int positions=0,index=0;
        for(auto& person:people){
            positions=0;
            index=0;
            while(sol[index][0]!=-1)index++;
            while(positions<person[1]){
                if(sol[index][0]==-1)positions++;
                index++;
            }
            while(sol[index][0]!=-1)index++;
            sol[index]=person;
        }
        return sol;
    }
};

//Binary Search
//Runtime: 40 ms, faster than 99.42% of C++ online submissions for Queue Reconstruction by Height.
//Memory Usage: 12.1 MB, less than 100.00% of C++ online submissions for Queue Reconstruction by Height.
class Solution {
public:
    vector<int> BIT;
    int n;
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int>(n+1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
        for(int i = 2; i <= n; i++) update(i, 1);  // BIT[1] is the 0th empty position, so we didn't add 1
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(n, vector<int>());
        for(int i = 0; i < n; i++){
            int l=0, r=n;
            while(l<r){
                int mid=l+(r-l)/2;
                if(getsum(mid+1)<people[i][1]) l=mid+1; // we need get the index mid empty information, but actually it's stored in BIT[mid+1]
                else r=mid;
            }
            res[l]=people[i];
            update(l+1, -1);
        }
        return res;
    }
    void update(int x, int v){
        for(int i = x; i <= n; i+=(i&-i)){
            BIT[i]+=v;
        }
    }
    int getsum(int x){
        int sum=0;
        for(int i = x; i > 0; i-=(i&-i)){
            sum += BIT[i];
        }
        return sum;
    }
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
};