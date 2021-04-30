/*Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};
//
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// use an unordered_set as a dictionary
		// and initialize with nums1 items
        unordered_set<int> dict {nums1.begin(), nums1.end()};
        
        vector<int> result;
        for (auto x : nums2) {
            if (dict.count(x)) {
				// if item in nums2 exists in dictionary
				// add it to the result and erase it from
				// the dictionary to avoid duplicates
                result.emplace_back(x);
                dict.erase(x);
            }
        }
        
        return result;
    }
};
//Sort
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
            while(i1 > 0 && i1 < n1 && nums1[i1] == nums1[i1 - 1]) i1++;
            while(i2 > 0 && i2 < n2 && nums2[i2] == nums2[i2 - 1]) i2++;
        }
        return res;
    }
};
//Sort 2
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                if (!ans.size() || ans.back() != nums1[i])
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};