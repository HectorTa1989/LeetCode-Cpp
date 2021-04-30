/*A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1*/

class Solution {
public:
    bool isHappy(int n) {
    if (n <= 1 || n == 4) return n == 1;
    int sum = 0;
    while (n != 0) {
        sum += static_cast<int>(pow(n % 10, 2));
        n /= 10;
    }
    return isHappy(sum);
    }
};

//Hash: The common choice is to use map or set to check if there is a loop. since the maximum sum is no greater than 2x2 + 9x9x9 (2,999,999,999), 
//we can use a 1000 lengh hashtable . It's not O(1) space but it's faster than the fast-slow pointer solution.
class Solution {
public:
    int tran(int n){
        int ans = 0;
        while(n){
            ans += pow(n%10, 2);
			n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        bool rep[1000];
        memset(rep, 0, sizeof(rep));
		n = tran(n);
        while(!rep[n]){
			rep[n] = true;
            if(n == 1)
                return true;   
			n = tran(n);
        }
        return false;
    }
};
//
bool isHappy(int n) {
while(n / 10 > 0){
	int sum = 0;
	while(n > 0){
		int rem = n % 10;
		sum = rem * rem + sum;
		n = n / 10;
	}
  n = sum;
}

if(n == 1 || n == 7) // from 2 to 9 only 7 is happy number. (handling corner case) 
	return true;
else
	return false;

}
//Here, we are using the concept of detecting loop in a linked list.
//If there is a loop in sequence then they meet at some point before reaching 1
int get(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        int slow = n;
        int fast = get(n);
        
        while(slow != fast)
        {
            slow = get(slow);
            fast = get(get(fast));
        }
        
        if(slow==1)
            return true;
        
        return false;
        
    }
	
//
class Solution {
public:
    bool isHappy(int n) {
        
        // base case; if its 0, it will never be happy (:
        if(n == 0)
        {
            return false;
        }
        
        
        vector<int> seen_before;    // a vector of answers we've computed before from an
                                    // iteration of this outer while loop.
        
        int num = 0;                // extracted digit from 'n'
        int num_sq = 0;             // extracted digit from 'n', squared.
        vector<int> digits;         // for each extracted digit 
        int answer = 0;
        
        // keep trying this until we hit 1, which means its happy!
        while(answer != 1)
        {
            answer = 0;
     
            // 1) extract the digits from n, square it, then push it into 'digits' vector.
            while(n>0)
            {
                num = n%10;
                num_sq = num * num;
                digits.push_back(num_sq);
                n = n/10;
            }
            
            // 2) add the squared digits up as our answer.
            for(int i = 0; i < digits.size(); i++)
            {
                answer = answer + digits[i];
            }
            
            // 3) Observe:
            // - All numbers that are NOT happy repeat a cycle when we do this.
            // - So IF WE NOTICE WE GET NUMBERS THAT WE'VE ALREADY GOTTEN before,
            //   we can end it and conclude that its not a happy number.
            // - If the number is happy, it will eventually hit 1.
            for(int i = 0; i < seen_before.size(); i++)
            {
                if(seen_before[i] == answer)
                {
                    return false;
                }
            }
            
            // 4) Clean up work
            // - Store the answer we've seen because its unique.
            // - clear the digits vector for extracted digits.
            // - set n = answer to run loop again.
            seen_before.push_back(answer);
            digits.clear();
            n = answer;
        }
        
       return true;
    }
};