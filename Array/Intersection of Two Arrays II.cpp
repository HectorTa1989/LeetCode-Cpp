/*Given two arrays, write a function to compute their intersection.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]*/

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