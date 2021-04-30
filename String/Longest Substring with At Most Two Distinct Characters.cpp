/*Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: tis "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: tis "aabbb" which its length is 5.*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i]];
            while (m.size() > 2) {
                if (--m[s[left]] == 0) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
//Solution 2
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > 2) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
//Solution 3: Sliding window
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left = 0, right = -1, res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) continue;
            if (right >= 0 && s[right] != s[i]) {
                res = max(res, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        return max(s.size() - left, res);
    }
};
//Solution 4: Similar to Fruit Into Baskets
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, cur = 0, cntLast = 0;
        char first, second;
        for (char c : s) {
            cur = (c == first || c == second) ? cur + 1 : cntLast + 1;
            cntLast = (c == second) ? cntLast + 1 : 1;
            if (c != second) {
                first = second; second = c;
            }
            res = max(res, cur);
        }
        return res;
    }
};