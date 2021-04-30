/*Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, 
return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]
Output: 1
Explanation: The third maximum is 1.*/
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(begin(nums), end(nums));
		reverse(begin(nums), end(nums));
		size_t i = 0, n = nums.size();
		while (i + 1 < n && nums[i + 1] == nums[i]) i++;
		if (i + 1 == n) return nums[0];
		i++;
		while (i + 1 < n && nums[i + 1] == nums[i]) i++;
		if (i + 1 == n) return nums[0];
		return nums[++i];
	}
};	
//vector
class Solution {
public:
int thirdMax(vector<int>& nums) {
    vector<int> v;
    for (int i : nums) // O(N)
    {
        if (find(v.begin(), v.end(), i) != v.end()) // O(3)
        {
            continue;
        }
        v.push_back(i);
        sort(v.begin(), v.end(), greater<int>()); //O(3)
        if (v.size() > 3)
        {
            v.resize(3);
        }
    }
    if (v.size() < 3)
    {
        return v[0];
    }
    return v[2];
}
};
//vector 2
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> top3;
        int i;
        for(auto num:nums){
            if((top3.size()<3)||(num>top3.back()&&num!=top3[0]&&num!=top3[1])){
                if(top3.size()<3){
                    if(find(top3.begin(),top3.end(),num)==top3.end())
                        top3.push_back(num);
                }
                else top3[2]=num;
                
                sort(top3.begin(),top3.end(),greater<int>());
            }
        }
        if(top3.size()<3)return top3[0];
        return top3[2];
        
    }
};
//Set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> seen{nums.begin(), nums.end()};
        int k = 3;
        if(seen.size() > k-1) {
            for(int i = 0; i < k-1; ++i) {
                seen.erase(max_element(seen.begin(), seen.end()));
            }
        }
        return *max_element(seen.begin(), seen.end());
    }
};
//HashMap
class Solution {
public:
    int thirdMax(vector<int>& num)
    {
        // using map to find the third largest
        // In cpp map data strcture only stores key is sorted order, hence we can find 3rd key
        
        map <int, int> lar;
        
        // mapping the keys with the elements in the array
        for(int i=0; i<num.size(); i++)
            lar[num[i]]++;
        
        // assigning iterator to map
        map <int, int>:: iterator it;
        
        int count=0;
        
        // looping throught the map to find size of map (ignore duplicate keys)
        for(it = lar.begin(); it != lar.end(); it++)
            count++;
        
        // target is position 3rd largest number
        int target= count-3;
        // if position becomes -ve, means map has 2 keys, hence we decrease the it by 1 and return
        if(target < 0)
        {
            // decreasing it to get the value of largest element in map as size < 3
            it--;
            return it->first;
        }
        
        for(it= lar.begin(); it != lar.end(); it++)
        {
            if(target == 0)
                break;
            else
                target--;
        }
    
        return it->first;
    }
};
//HashMap 2
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int> mp;
        for(auto a:nums)
        {
            mp[a];
        }
        if(mp.size()<3)
        {
            auto x = mp.end();
            x--;
            return x->first;
        }
        else
        {
            auto x = mp.end();
            int temp = 3;
            while(temp--)
            {
                x--;
            }
            return x->first;
        }
    }
};