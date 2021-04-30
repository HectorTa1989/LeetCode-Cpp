/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.*/
 bool isPalindrome(int x) {
        if (x<0) return false;
        int base = 1;
        while(x/base >= 10) base *= 10;
        while(x && x/base == x%10) {
            x = (x%base)/10;
            base /= 100;
        }
        return x == 0;
    }
	
//
bool isPalindrome(int x) {
        if (x < 0) return false;
        if (!(x / 10)) return true; // If the number is single digit and greater than 0
        int numDigits = floor(log10(x)) + 1; // Calculate the number of digits in a number
        int comparor = (int)pow(10, numDigits - 1); // Calculate the divisor needed to 
        while (x) { // isolate the largest digit.
            if (x / comparor != x % 10) return false;
            x %= comparor; // Remove the most significant digit
            x /= 10; // Also remove least significant digit;
            comparor /= 100; // x not has two less digits than before, 
        } // adjust the comparor to account for this
        return true;
    }