/*Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]*/

//Sol 1: 
//high is the bigger digit at the less significant bit to be swapped to a more significant bit.
//highBase is the base of the bit corresponding to high.
//low is the smaller digit at a more significant bit to be swapped with high at a less significant bit.
//lowBase is the base of the bit corresponding to low.

//for example:
//2736
//high: 7
//highBase: 100
//low: 2
//lowBase: 1000
//the result would be: 2736 + (7-2) * (1000-100) = 7236

int maximumSwap(int num) {
        int temp = num, base = 1, high = 1, low = 1, lowBase = 1, highBase = 1, maxDigit = 0, maxBase = 1;
        while(temp > 0)
        {
            int current = temp % 10;
            if(current<maxDigit)
            {
                low = maxDigit;
                lowBase = maxBase;
                high = current;
                highBase = base;
            }
            if(current > maxDigit)
            {
                maxDigit = current;
                maxBase = base;
            }
            base *= 10;
            temp /= 10;
        }
        return num + (low-high)*(highBase-lowBase);
    }
	
//O(n) runtime O(1)space
class Solution {
public:
	int maximumSwap(int num) {
		int N[9] = {0,0,0,0,0,0,0,0,0};
		int n = num;
		int i = 0;
		while (n){
			N[i] = n%10;
			n /=10;
			i++;
		}
		int s1 = -1;
		int max_swap_index = -1;
		for (int j = i-2; j >-1; j --){
			if (s1 == -1) {
				if (N[j] > N[j+1]){
				s1 = j;
				max_swap_index = j;
				}
			}
			else if (N[max_swap_index] <= N[j]){
				max_swap_index = j;
			}
		}
		if (max_swap_index == -1) return num;
		for (int j = i-1; j >s1; j --){
			if (N[max_swap_index] > N[j]){
				int tmp = N[j];
				N[j] = N[max_swap_index];
				N[max_swap_index] = tmp;
				break;
			}
		}
		int ans = 0;
		for (int j = i-1; j >-1; j --){
			ans = ans * 10 + N[j];
		}
		return ans;
	}
};
	
//Sol 3: to_string
class Solution {
public:
    int maximumSwap(int num) {
        if(num < 12) {
            return num;
        }
        string num_s = to_string(num);
        int l = num_s.length();
        vector<pair<int,int>> vp(l, {0,0});
        
        // iterating from end to start, store the element with the max value 
        // and its index, which comes after the current index
        vp[l-1] = {num_s[l-1]-48, l-1};
        for(int i = l-2; i >= 0 ; --i) {
            int n = num_s[i] - 48;
            if(n > vp[i+1].first) {
                vp[i] = {n, i};
            } else {
                vp[i] = vp[i+1];
            }
        }
        
        // starting from first element, check the stored max values
        // if it is bigger than the current value, swap them and return the value
        for(int i = 0; i < l; ++i) {
            if(num_s[i]-48 < vp[i].first) {
                auto tmp = num_s[i];
                num_s[i] = vp[i].first+48;
                num_s[vp[i].second] = tmp;
                break;
            }
        }
        
        return stoi(num_s);
    }
};
//another to_string Sol
class Solution {
public:
    int maximumSwap(int num)
    {
        string t = to_string(num);
        int i,j,n=t.length(),ind;
        if(n==1)
            return num;
        for(i=0;i<n-1;i++)
        {
            char max='0';
            for(j=i+1;j<n;j++)
            {
                if(t[i]<t[j] && max<=t[j])
                {
                    ind=j;
                    max=t[j];
                }
            }
            if(max!='0')
            {
                char temp=t[i];
                t[i]=t[ind];
                t[ind]=temp;
                int k=stoi(t);
                    return k;
            }
        }
        return num;
    }
};