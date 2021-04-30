int findMin(vector<int> &nums) {
        if(nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r]){
                r = mid;  //@1
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }

/*
FAQ
why(l<r)?
we confirmed nums[r] is not answer at @1, but nums[l](return value) not confirmed, so can not make l=r.
why use nums[mid]<nums[r], but not nums[mid]<=nums[r]?
when nums[mid]=nums[r], we can not confirm answer in [l,mid] or [mid,r], example: [1,1,1,0,1], l=0, r = 4, mid=2. So only < allowed.
why use nums[mid]<nums[r], but not nums[mid]>nums[l]?
First, we need l=mid+1 or r=mid-1 to reduce [l,r] range.
Try use:
if(nums[mid] > nums[l]) {
	l = mid;
} else {
	r = mid;  //can not reduce r, may be dead loop.
	// r = mid - 1; //can not confirm nums[mid] is not answer. example: [4,5,1,2,3],l=0,r=4,mid=2 
}
*/