/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/
			 
//Solution 1			 
/*Time Complexity: O(n)
Space Complexity: O(min of a,b) for the unordered set. a, is the upper bound of the space complexity.
Where a: Size of the string
b: Size of the number of characters in the character-set*/

//Sliding window: 
class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_set<char> set;
    
		int i = 0, j = 0, n = s.size(), ans = 0;
    
		while( i<n && j<n)
		{
			if(set.find(s[j]) == set.end()) //If the character does not in the set
			{
				set.insert(s[j++]); //Insert the character in set and update the j counter
				ans = max(ans, j-i); //Check if the new distance is longer than the current answer
			}
			else
			{
				set.erase(s[i++]); 
				/*If character does exist in the set, ie. it is a repeated character, 
				we update the left side counter i, and continue with the checking for substring. */
			}
		}
    
		return ans;
	}
};

//Map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int maxlen = 0;
        for(int i = 0, j = 0; j < s.size(); j++){
            m[s[j]]++;
            while(m[s[j]] > 1) m[s[i++]]--;
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
//Map 2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];  
            }
            m[s[i]] = i;
            res = max(res, i - left);            
        }
        return res;
    }
};

//Better than map
//Ascii uses 7-bit encoding. So total 2^7=128 possible charcter encoding possible. So even if our string contains anything other than alphabets (%, & or anything), 
//we possibly can map each character.
//Pro Tip: Ask your interviewer if the string will only contain small letter english alphabet? if yes. Apply mod97 to ascii values and you will only need Array of size 26.
 
 int arr[128]={0};
        int i=0, j=0, count=0;
        
        while(j<s.size()){
            if(!arr[s[j]]){
                arr[s[j++]]++;
                count=max(j-i, count);
            }
            else{
                arr[s[i]]--;
                i++;
            }
        }
        return count;