/*Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Example 1:
Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].

Example 2:
Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Can you do it in O(n) time and/or in-place with O(1) extra space?*/

//Runtime: 56 ms, faster than 99.48% of C++ online submissions for Wiggle Sort II.
//Memory Usage: 17.5 MB, less than 7.69% of C++ online submissions for Wiggle Sort II.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int i = (temp.size()-1)/2;
        int j = temp.size()-1;
        int k = 0;
        while(k < nums.size())
        {
            if(k&1)
                nums[k++] = temp[j--];
            else
                nums[k++] = temp[i--];
        }
    }
};
/*Sort and then write the smaller half of the numbers on the even indexes 
and the larger half of the numbers on the odd indexes, both from the back. Example:

Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5
So write nums from the back, interweaving sorted[0..4] (indexed by j) and sorted[5..9] (indexed by k)*/
void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
        nums[i] = sorted[i&1 ? k++ : j++];	//	k are larger half numbers of vector, are put at odd indices
}
//
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};
//O (n) time complexity and O (1) space complexity
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        #define A(i) nums[(1 + 2 * i) % (n | 1)]
        int n = nums.size(), i = 0, j = 0, k = n - 1;
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        while (j <= k) {
            if (A(j) > mid) swap(A(i++), A(j++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else ++j;
        }
    }
};

//Although a worst case O(n) solution is available, it would make it too challenging to write during an interview. 
//The function nth_element in C++ is readily available and is expected to have O(n) time complexity on average. 
//Need some help, though, on how to make space complexity to be O(1).
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        vector<int> res(n);
        int largeStart = n-1;
        int smallStart = (n%2) ? mid : (mid-1);
        for (int i = 0; i < n; i+=2)
            res[i] = nums[smallStart--];
        for (int i = 1; i < n; i+=2)
            res[i] = nums[largeStart--];
        nums = res;
    }
    
    // this ensures all values equal to the median is in the middle
    void threeWayPartition(vector<int> &nums, int val) {
        int i = 0, j = 0;
        int n = nums.size()-1;
        while (j <= n){
            if (nums[j] < val)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > val)
                swap(nums[j], nums[n--]);
            else
                j++;
        }
    }
};