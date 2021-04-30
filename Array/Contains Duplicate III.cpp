/*Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false*/

//16ms
class Solution {
    public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector< pair<long, int> > vec;
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back(make_pair(nums[i], i));
        }
        sort(vec.begin(), vec.end());
		
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            while(j < nums.size() && vec[j].first-vec[i].first <= t) {
                if (abs(vec[j].second-vec[i].second) <= k) return true;
                j++;
            }
        }
        return false;
    }
};

//idea is to preserve a sliding window containing nearest k numbers, and check if next number collides to the numbers in the window
//32ms
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k == 0) return false;
        set<long> windows;       
        int l = 0;               
        for(int i = 0; i < nums.size(); i++){
            if(i - l > k){     
                windows.erase(nums[l++]);
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);          
            if(it != windows.end() && *it <= ((long)nums[i]+(long)t))    
                return true;
            windows.insert(nums[i]);             // not found
        }
        return false;
        
    }

//2nd sliding window
class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if ((nums.size() < 2) || (k <= 0) || (t < 0))
        {
            return false;
        }
        
        // This multiset is essentially a BST which stores all the numbers 
        // within the window of size k + 1. Note that we have to use long 
        // instead of int since we have to handle the possible overflow of 
        // nums[i] + t.
        multiset<long> numBst;
        
        for (int i = 0; i < nums.size(); i++)
        {   
            if (i >= k + 1)
            {
                // Delete the number which falls out of the window of size k + 1.
                auto itDelete = numBst.find(static_cast<long>(nums[i - (k + 1)]));
                numBst.erase(itDelete);
            }
            
            // Check whether numBst contains some number between nums[i] - t 
            // and nums[i] + t (inclusive).
            auto itLower = numBst.lower_bound(
                static_cast<long>(nums[i]) - static_cast<long>(t));
            if ((itLower != numBst.end()) && 
                (*itLower <= static_cast<long>(nums[i]) + static_cast<long>(t)))
            {
                return true;
            }
            
            // Insert nums[i] into the BST.
            numBst.insert(static_cast<long>(nums[i]));
        }
        
        return false;
    }
};
//Bucket sort
// time: O(n); space: O(n)
class Solution {
    long long getBucketId(long long i, long long w) {
        return i < 0 ? (i + 1) / w - 1 : i / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k < 1 || t < 0)
        {
            return false;
        }

        unordered_map<long long, long long> buckets;
        long long width = (long long)t + 1;
        for (int i = 0; i < n; i++)
        {
            long long id = getBucketId(nums[i], width);

            // found the value in the same bucket
            if (buckets.find(id) != buckets.end())
            {
                return true;
            }

            // found the value in the adjacent bucket
            if ((buckets.find(id - 1) != buckets.end() && nums[i] - buckets[id - 1] < width) ||
                (buckets.find(id + 1) != buckets.end() && buckets[id + 1] - nums[i] < width))
            {
                return true;
            }

            // insert current value to buckets
            buckets[id] = nums[i];

            if (i >= k)    // remove out of range element
            {
                buckets.erase(getBucketId(nums[i - k], width));
            }
        }

        return false;
    }
};
//http://yucoding.blogspot.com/2015/10/leetcode-question-contains-duplicate-iii.html
//O(n^2)
/*Let's take an example, say the array is A = [3,6,0,4], and we set t = 2, k =2.
Let's sort the array according to the value,
the values of the array becomes:  A' = [0, 3, 4, 6]
the indices of the array becomes:  I' = [2, 0, 3, 1]
We rewrite them into one array:
P = [(0,2), (3,0), (4,3), (6,1)]
Now we are searching the pairs, starting from the first pair:
(0, 2) where 0 is the value 2 is the index.

Now we have pair  P[i] = (0,2), i = 0, we need P[j] to check if  P[i] and P[j] satisfy the constrains that
abs(P[i][0] - P[j][0]) < = t and abs(P[i][1] - P[j][1]) < = k.

In this example:
1. Compare (0,2) and (3,0),   abs(0-3) >t
2. Compare (3,0) and (4,3),   abs(3-4) <=t , abs(0-3) > k
3. Compare (3,0) and (6,1),   abs(6-3) > t
4..Compare (4,3) and (6,1),   abs(4-6) <=t, abs(3-1)<=k, satisfied. Return True.
*/
class Solution {
public:
    static bool pcomp(pair<int,int> a, pair<int,int> b) {
        return a.first < b.first ;
    }
     
    bool search(vector<pair<int,int> > l, int t, int k){
        int po = 0;
        while (po < l.size()){
            int i = po + 1;
            while (i < l.size()){
                if ((abs(long(l[i].first) - long(l[po].first)) <= t)&&(abs(l[i].second - l[po].second)<= k)){
                    return true;
                }else{
                    if (abs(long(l[i].first) - long(l[po].first)) > t){
                        break;
                    }else{
                        i+=1;
                    }
                }
            }
            po += 1;
        }
        return false;
    }
     
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() == 0 ){
            return false;
        }
        vector<pair<int,int> > pp;
        for (int i=0;i<nums.size();i++){
            pp.push_back(make_pair(nums[i], i));
        }
        sort(pp.begin(),pp.end(),pcomp);
        return search(pp, t, k);
    }
};