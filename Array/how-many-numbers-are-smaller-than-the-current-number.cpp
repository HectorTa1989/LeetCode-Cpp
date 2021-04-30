// Method 1: Brute-force
//We loop through the vector nums, and whenever we find any smaller no. 
//other than the current one (i.e. nums[i]>nums[j]) then we increment our counter (k++). 
//Finally after finding no. of smaller numbers for the current one (k), we store it into our result vector (c.push_back(k)) 
//and initialize k=0 again for next current no. and the process repeats till we have checked for every number.
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n=nums.size(),i,j,k;
        vector<int>c;
        for(i=0;i<n;i++)
        {k=0;
            for(j=0;j<n;j++)
            {
                if((i!=j)&&(nums[i]>nums[j]))
                {
                    k++;
                }
            }c.push_back(k);
        }
        return c;
    }
};

//Method 2: sort and map
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) == map.end()) {
                map[arr[i]] = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = map[nums[i]];
        }
        return nums;
    }
//Map no sort
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> vec;
        for(auto &num:nums)
        {
            mp[num]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            for(auto &nn:mp)
                if(nn.first!=nums[i] && nn.first<=nums[i])
                    count+=nn.second;
            vec.push_back(count);
            
        }
        return vec;
    }
};

//
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& vec) {
        vector<int> copy = vec;
        unordered_map<int, int> hash;
        sort(copy.begin(), copy.end());
        int size = vec.size();
        for (int i = 0; i < size; i++)
        {
            if (!i) hash[copy[i]] = i;
            else if (copy[i - 1] != copy[i])
                hash[copy[i]] = i;
        }
        for (int i = 0; i < size; i++)
            copy[i] = hash[vec[i]];
        return copy;
    }
};
	
//prefix sum 100% space optimized
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>a(101);
        vector<int>b(101);
        int n=nums.size();
        for(int i=0;i<n;i++)  // making the frequency array
            a[nums[i]]++;
        for(int i=1;i<101;i++)  //filling the prefix sum array
            b[i]=b[i-1]+a[i-1];
        vector<int>ans(n);  // final solution array
        // for(int i=0;i<10;i++)
        //     cout<<b[i]<<" ";
        for(int i=0;i<n;i++){
            ans[i]=b[nums[i]];
        }
        return ans;
    }
};