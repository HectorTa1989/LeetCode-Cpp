class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, index = 0;
        while(index <= end && start < end)
        {
            if(nums[index] == 2)
            {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            }
            else if(nums[index] == 0)
            {
                nums[index] = nums[start];
                nums[start] = 0;
                index++;
                start++;
            }
            else
                index++;
        }
    }
};
//
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int i = 0;
        while(i<=right) {
            if(nums[i]==0) 
                swap(nums[i++],nums[left++]);
            else if(nums[i]==1) 
                i++;
            else if(nums[i]==2) 
                swap(nums[i],nums[right--]);
        }
    }
};
//Method 2
//It's actually Dutch national flag problem.
//[, i): 0 
//[i, j]: 1
//(k, ...]: 2
//Once j meets k, the sorting is complete

class Solution { 
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = i, k = nums.size() - 1;
        
        while(j <= k){
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 1) j++;
            else swap(nums[k--], nums[j]);
        }
    }
}; 
//Method 3
// Usually the more variables you reserve for yourself with these types of problems 
// the more you can work with and the more agile you can become.
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, x = 0; 
        while (x <= j) {
            if (nums[x] == 0) { // Meet a 0? Send it back !
                swap(nums[x++], nums[i++]);
            } else if (nums[x] == 2) { // Meet a 2? Send it forward, but don't move forward yourself,
                swap(nums[j--], nums[x]); // You might have just swapped a two with a 0.
            } else { // In that case, you'd need to swap it back. If I wrote nums[x++], I would have missed it!
                x++; // Keep walking, x.
            }
        }
        return;
    }
	
//
void sortColors(vector<int>& nums) {
    int zero =0, l = 0, r = nums.size()-1;
    while (l <= r) {
        if (nums[l] == 0) 
            swap(nums[l++], nums[zero++]);
        else if (nums[l] == 2) 
            swap(nums[l], nums[r--]);
        else
            l++;
    }
}