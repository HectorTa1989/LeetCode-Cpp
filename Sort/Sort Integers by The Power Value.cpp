/*The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, 
if two or more integers have the same power value sort them by ascending order.
Return the k-th integer in the range [lo, hi] sorted by the power value.
Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.

Example 1:
Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.

Example 2:
Input: lo = 1, hi = 1, k = 1
Output: 1

Example 3:
Input: lo = 7, hi = 11, k = 4
Output: 7
Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
The interval sorted by power is [8, 10, 11, 7, 9].
The fourth number in the sorted array is 7.

Example 4:
Input: lo = 10, hi = 20, k = 5
Output: 13
Example 5:

Input: lo = 1, hi = 1000, k = 777
Output: 570
 
Constraints:
1 <= lo <= hi <= 1000
1 <= k <= hi - lo + 1*/

//Find the power value of the numbers lo to hi Sort by power value and number size
class Solution {
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);   
    }
    
    int getKth(int lo, int hi, int k) {
        std::vector<pair<int, int>> res;
        std::map<int, string> m;
        for(int idx = hi;idx >= lo;idx--){
            int cnt = 0;
            int num = idx;
            while(num != 1){
                if(num & 0x01)  num = (num << 1) + num + 1;
                else            num = num >> 1;
                cnt++;
            }
            res.push_back(make_pair(cnt, idx));
        }
        sort(res.begin(), res.end(), cmp);
        
        return res[k - 1].second;
    }
};

//nth_element
class Solution {
 private:
  inline int get_steps(int num) {
    int steps = 0;
    while (num != 1) {
      ++steps;
      if (num & 1)
        num = num * 3 + 1;
      else
        num /= 2;
    }
    return steps;
  }

 public:
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int>> nums;
    nums.reserve(hi - lo + 1);
    for (int i = lo; i <= hi; ++i) {
      nums.emplace_back(get_steps(i), i);
    }

    nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
    return nums[k-1].second;
  }
};
//Map
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        map<int, int> freq;
        
        while(lo <= hi){
            int sol = getPow(lo);
            freq[lo] = sol;
            lo++;
        }
        
        vector<pair<int, int> > result;
        map<int, int>::iterator it;
        
        for(auto it : freq){
            result.push_back({it.first, it.second});
        }
        
        sort(result.begin(), result.end(),
            [](const pair<int, int> &a, const pair<int, int> &b){
                if(a.second != b.second) return (a.second < b.second);
                else return a.first < b.first;
        });
        
        return result[k - 1].first;
    }
    
    int getPow(int x){
        int count = 0;
        if(x == 1) return 1;
        while(x != 1){
            if(x % 2 == 0) x = x / 2;
            else x = (3 * x) + 1;
            count++;
        }
        
        return count;
    }
};

//We will make a vector v which will contain number of steps require for the number x to reach to 1;
//We store these steps at index x-1;
class Solution {
public:
    int find(int i,vector<int> v)
{    int c=0;
    while(i!=1)
    {  c++;
        if(i%2==0)
        {
            i/=2;
            if(i<v.size())           //if we find any number which is already in v then we will add directly its value
			//i.e for 6->3....... but 3 already contain 7 so we add 7 to c.
            {
                  c+=v[i-1];
                  break;
            }
        }
        else
        {
            i=i*3+1;
            if(i<v.size())
            {
                  c+=v[i-1];
                  break;
            }
        }
    }
    return c;
}
     void subsolution(int l,vector<int> &v)
     {
         
  v.push_back(0);v.push_back(1);    //for 1->0 step,for 2->1 step;
  for(int i=3;i<=l;i++)   //for 3 to hi;
  {
      v.push_back(find(i,v));
  }
     }
     
	 /****main function ****/
    int getKth(int lo, int hi, int k) {
        vector<int> v;    //v will contain number of steps require to turn into 1.
        subsolution(hi,v);
        
        vector<vector<int>> vec;
        for(int i=lo;i<=hi;i++)
        {
            vec.push_back({v[i-1],i});
        }
        sort(vec.begin(),vec.end());
        return vec[k-1][1];
    }
};