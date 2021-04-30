/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

class Solution {
public:
    int bs(vector<int>& a,int b,int e,int x){
        if(b>e)
            return -1;
        int mid = (b+e)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            return bs(a,b,mid-1,x);
        else
            return bs(a,mid+1,e,x);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        //found index of target
        int i = bs(nums,0,nums.size()-1,target);
        if(i==-1)
            return ans;
        int k=i;
        while(k>=0 && nums[k] == target  ){
            k--;
        }
        ans[0] = k+1;
        
        int j=i;
        while(j<nums.size() && nums[j] == target  ){
            j++;
        }
        ans[1] = j-1;
        return ans;
            
    }
};
/*Use a variable to store the temporary result during the search(let's call it ans). Every time you hit a not found condition AND if there is a 
possibility of one of the mid or its neighbours being the desired answer store it.
Reason : storing can't harm you if its constant space, the later points will show you how it reduces a burden while writing binary search. 
Also it ensures an answer.

Whenever you hit not found condition do s = mid+1 or e = mid-1 according to the condition without worrying.
Reason : You have stored your value if the loop ends, can't go wrong. This also ensures you don't go into infinite loops.

Default to writing mid = s + (e-s)/2 and NOT mid = (s+e)/2.
Reason : The later can result in an overflow when you are not searching in an array but rather on an answer space, specially because binary search 
if it can be applied is a great tool for huge numbers.

Write your if and elses well, and don't worry about adding extra conditions with the neighbours, at the same time don't forget to check whether the 
neighbour exists.
Reason : This is the only thing you should be worrying about coding right, because this depends on the problem. If it is a easy or medium sometimes 
even medium-hard, this part shouldnt cause much trouble.

If you're wondering why I have written m == s and again m == e in my conditions. 
This is because I am sure my answer cannot be outside the range s and e and if it is it has been stored. 
If you're more confortable you can replace with m == 0 or m == a.size()-1*/

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
	int s = 0, e = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == s || a[m] != a[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
		}
	}

	//last occurrence
	s = 0, e = a.size()-1;
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == e || a[m] != a[m+1]){
				ans[1] = m;
				break;
			}
			else{
				s = m+1;
				ans[1] = m+1;
			}
		}
	}
	return ans; 
}
};
//
The first solution is using C++ STL algorithms, specifically, lower_bound and upper_bound:

class Solution {
public:
    vector<int> searchRange(const vector<int>& A, int target) {
        // lower_bound returns first element greater or equal to the target
        // or last if target wasn't found
        int first = std::lower_bound(A.begin(), A.end(), target) - A.begin();
        // upper_bound returns first element greater than the target
        // or last if target wasn't found
        int last = std::upper_bound(A.begin(), A.end(), target) - A.begin();
        
        // both lower_bound and upper_bound return iterators
        // to convert iterators to index position,
        // we subtract by the beginning iterator

        // if first == last, the target wasn't found
        if (first == last) {
            return {-1, -1};
        }
        
        return {first, last - 1};
    }
};
The second solution is using a modifyied Binary Search algorithm:

class Solution {
public:
    vector<int> searchRange(const vector<int>& A, int target) {
        return {Search(A, target, true), Search(A, target, false)};
    }
private:
    // modified binary search algorithm that can get the first
    // appearence or the last appearence of a number dependeing
    // on the flag (first) that's being passed to it
    int Search(const vector<int>& A, int target, bool first) {
        int start = 0;
        int end = A.size() - 1;
        int result = -1;

        while (start <= end) {  // note (<=)
            int pivot = start + (end - start) / 2;
            if (A[pivot] == target) {
                // unlike standard binary search, we don't stop
                // if we found a match, instead, we keep going
                // in either direction depending on the flag
                result = pivot;
                first ? end = pivot - 1 : start = pivot + 1;
            } else if (A[pivot] > target) {
                end = pivot - 1;
            } else {
                start = pivot + 1;
            }
        }

        return result;
    }
};