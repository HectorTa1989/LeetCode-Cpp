class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int r1 = m-1, r2 = n-1, r = m+n-1;
        while(r1>=0 && r2>=0)
            nums1[r--] = nums1[r1]>nums2[r2]? nums1[r1--] : nums2[r2--];
        while(r2 >= 0)
            nums1[r--] = nums2[r2--];
		while(r1 >= 0)
            nums1[r--] = nums1[r1--];
    }
};
//
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pa = m-1, pb = n-1, pc = m+n-1;
        while(pa>=0 && pb>=0) {
            if(A[pa]>B[pb]) 
                A[pc--] = A[pa--];
            else
                A[pc--] = B[pb--];
        }
        while(pa>=0) A[pc--] = A[pa--];
        while(pb>=0) A[pc--] = B[pb--];
    }
};

//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n) return; // If no n, nothing needs to be done.
        if (!m) { // If no m, nums1 is equal to nums 2.
            nums1 = std::move(nums2);
            return;
        }
        // We will work backwards, comparing the last two non-zero array integers
		// and replacing the last value in nums1 with the larger of the two
        while (n) { // While there is another second array
            if (!m || nums2[n - 1] > nums1[m - 1]) { // If there isn't any number to compare to in the first array
                nums1[m + n - 1] = nums2[n - 1]; // or if the number in the second array is bigger, insert
                n--; // the number from the second array and then move one to the left on the second array
            } else { // for the next comparison.
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }
            
        }
        return;
    }
};