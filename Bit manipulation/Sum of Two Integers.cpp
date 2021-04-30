/*Sum of two bits can be obtained by performing XOR (^) of the two bits. Carry bit can be obtained by performing AND (&) of two bits.
It is simple logic that can be used to add 2 single bits. We can extend this logic for integers. If x and y don’t have set bits at same position(s), 
then bitwise XOR (^) of x and y gives the sum of x and y. To incorporate common set bits also, bitwise AND (&) is used. 
Bitwise AND of x and y gives all carry bits. We calculate (x & y) << 1 and add it to x ^ y to get the required result.*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        
        return sum;
    }
};

//Method 2
/*Brief explanation here:

using bit manipulation to split the a+b process
100 + 011 = 111 using ^ can help us to add different bits
100 + 100 = (100 & 100) << 1 = 1000 using & can help us handle the same bits
*/
class Solution {
public:
    int getSum(int a, int b) 
    {
        return b? getSum(a^b, (a&b)<<1):a;
    }
};
An intuitive math solution is also enclosed here.

class Solution {
public:
    int getSum(int a, int b) 
    {
        if(a < b) swap(a, b);
        if(a==INT_MAX && b==INT_MIN) return -1;
        return (log(pow(1.1, b)*pow(1.1,a))/log(1.1));
    }
};