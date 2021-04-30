using namespace std; 
 
class Solution {
public:
    void rev(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;           
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0)
            return;
        rev(nums, 0, n-k-1);
        rev(nums, n-k, n-1);
        rev(nums, 0, n-1);
    }
    
};

//Sol 2
void rotate(vector<int>& nums, int k) {
    k%=nums.size();
    vector<int> roll(nums.end()-k,nums.end());
    nums.erase(nums.end()-k,nums.end());
    nums.insert(nums.begin(),roll.begin(),roll.end());
}

// Function to print an array 
void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " "; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int d = 2; 
  
    // in case the rotating factor is 
    // greater than array length 
    d = d % n; 
  
    // Function calling 
    leftRotate(arr, d, n); 
    printArray(arr, n); 
  
    return 0; 
} 