/*
Given an array of integers and a number k, find maximum sum of a subarray of size k.

Examples :

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/

// O(n) solution for finding maximum sum of 
// a subarray of size k 
#include <iostream> 
using namespace std; 
  
// Returns maximum sum in a subarray of size k. 
int maxSum(int arr[], int n, int k) 
{ 
    // k must be greater 
    if (n < k) 
    { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    int res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
  
    // Compute sums of remaining windows by 
    // removing first element of previous 
    // window and adding last element of  
    // current window. 
    int curr_sum = res; 
    for (int i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
    } 
  
    return res; 
} 
   
// Driver code 
int main() 
{ 
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20}; 
    int k = 4; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxSum(arr, n, k); 
    return 0; 
} 