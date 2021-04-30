class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        
        while(n > 1){
            if(n % 2 != 0){
                return false;
            }
            n /= 2;
        }
        
        return true;
    }
};
//
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 1) {
            if (n % 2) return false;
            n >>= 1;
        }
        return n > 0;
    }
};

//Just a binary trick:

2^n = 1{000...0 - n times}, binary.
2^2 = 4 (decimial) = 100 binary - two zeros.
2^5 = 32 (decimial) = 100000 binary - five zeros.

2^n - 1 = {111...1 - n times}
2^3 - 1 = 8 - 1 = 7 (decimial) = 111 = three ones.
2^5 - 1 = 32 - 1 = 31 (decimial) = 11111 = five ones.

Based on this two rules, if n is power of two (2^n) if we apply bitwise AND all corresponding bits will be different and we'll receive zero, for example:

1) n = 2^5
32 & (32 - 1) = 32 & 31:

-- 100000
--- 11111
--- 00000 == 0
2) n = 2^3
8 & (8 - 1) = 8 & 7:

-- 1000
--- 111
--- 000 == 0
3) 25?
25 & (25 - 1) = 25 & 24:

-- 11001‬
-- 11000
-- 11000 != 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? !(n & n-1) : false;
    }
};