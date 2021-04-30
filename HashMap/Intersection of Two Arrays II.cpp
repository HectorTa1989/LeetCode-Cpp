vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> resVec; 
		unordered_map<int, int> mapObj;
        for (const auto& number: nums1) {
            mapObj[number]++; // Store the count of each number
        }
        for (const auto& number: nums2) {
            mapObj[number]--; // If it appears in the second map, pop it back into the vector
            if (mapObj[number] >= 0) resVec.push_back(number); //If its count is greater than 0
        } // If the count becomes negative it means it shows up in one vector more than the other vector
        return resVec; // Under that case, we do NOT want to count it as a duplicate.
    }
	
//Method 2
vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
}


//Time: O(m + n) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};
//
//Time: O(m + n) Space: O(m)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};


//Sort and two pointers Solution:
//Time: O(max(m, n) log(max(m, n))) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
        }
        return res;
    }
};

//by kinght5857@sina
  if (nums1.size() == 0 || nums2.size() == 0) return vector<int>(0);
        
        unordered_map<int, int> numMap;
        vector<int> Result;
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        for (int i : nums1)
                numMap[i]++;

        for (int i : nums2)
        {
            if (numMap.find(i) != numMap.end() && numMap[i]-- > 0)
                Result.push_back(i);
        }
        
        return Result;
		
//by kingkong1961690748
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            if (isNumFound(nums2, nums1.at(i))) {
                res.push_back(nums1.at(i));
            }
        }

        return res;
    }

    bool isNumFound(vector<int> &arr, int target) {
        if (arr.empty()) return false;
        vector<int>::iterator left = arr.begin();
        vector<int>::iterator right = arr.end() - 1;
        while (left <= right) {
            if (*left == target) {
                arr.erase(left);
                return true;
            }
            if (*right == target) {
                arr.erase(right);
                return true;
            }
            ++left;
            --right;
        }
        return false;
    }

};