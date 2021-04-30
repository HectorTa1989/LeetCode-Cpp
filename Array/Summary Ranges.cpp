/*Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    for (int i=0; i<nums.size(); i++) {
        int pre = nums[i];
        while (i+1<nums.size() && nums[i+1]==nums[i]+1)  
            i++;
        if (pre == nums[i])
            ret.push_back(to_string(pre));
        else
            ret.push_back(to_string(pre)+"->"+to_string(nums[i]));
    }
    return ret;
}
};
//Solution 2
//Go through the numbers, i0 is the index where the current range starts and i is the current index. At the end of a range, recognized by i == nums.size()-1 || nums[i+1] > nums[i]+1, add the range to the output and update i0 for the next range.

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    for (int i=0, i0=0; i<nums.size(); i++) {
        if (i == nums.size()-1 || nums[i+1] > nums[i]+1) {
            ranges.push_back(to_string(nums[i0]));
            if (i > i0) ranges.back() += "->" + to_string(nums[i]);
            i0 = i + 1;
        }
    }
    return ranges;
}
//Solution 3
//I saw lestrois's solution and then wrote that approach myself in C++. For each range, find its end and then add the range to the output.

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    for (int i=0, i0=0; i<nums.size(); i0=++i) {
        while (i+1<nums.size() && nums[i+1]==nums[i]+1) i++;
        ranges.push_back(to_string(nums[i0]));
        if (i > i0) ranges.back() += "->" + to_string(nums[i]);
    }
    return ranges;
}