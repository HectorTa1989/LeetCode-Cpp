//fastest
class Solution {
public:
    bool validMountainArray(vector<int>& vec) {
        bool inc = 0;
        bool dec = 0;
        for (size_t i = 1; i < vec.size(); i++)
        {
            if (vec[i] > vec[i - 1] && !dec)
                inc = true;
            else if (vec[i] >= vec[i - 1])
            {
                inc = false;
                break;
            }
            else if (vec[i] < vec[i - 1] && inc)
                dec = true;
            else if (vec[i] <= vec[i - 1])
            {
                dec = false;
                break;
            }
        }
        return inc && dec;
    }
};
//2 pointers
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int low = 0, high = n - 1;
        while(low < n-1 && A[low] < A[low+1]) low++;
        while(high > 0 && A[high-1] > A[high]) high--;
        return low > 0 && high < n-1 && low == high;
    }
};
//
bool validMountainArray(vector<int>& A) {
	//A mountain array can exist only when there are 3 or more elements
    if(A.size()<3) return false;
    //We will use a pointer to go through the entire vector
    int pointer=1;
    while(pointer<A.size()){
    	//We check if we are climbing the mountain
    	//It is supposed that we are climbing only when the element i is greater than element i-1
    	if(A[pointer-1]<A[pointer]) pointer++;
    	//If we are not climbing anymore, we break the loop
    	else break;
	}
	
	//Now, after climbing we check 2 cases:
	//1) The pointer is at the last element, which means that there are no elements more, so the mountain
	//is only increasing in height and never decreasing
	//2) The pointer has not been increased, which means that vector[0]>=vector[1] (like [90, 14, 16, 17 ... ]
	if(pointer==A.size()||pointer==1) return false;
	//Then, we are looking for the slope (height decreasing)
	while(pointer<A.size()){
		if(A[pointer-1]>A[pointer]){
			pointer++;
		} else break;
	}
	//Now, if the i==A.size it means that it is a mountain array because it has been only decreasing since the peak was met.
	//Otherwise, it's not a mountain.
	if(pointer==A.size()) return true;
	else return false;
	//If it was helpful for you, don't forget to smash that upvote button <3
}
//
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n<3)
            return false;
        int p1 = 0;
        int p2 = n-1;
        int x,y;
       
        while(p1<A.size()-1&&A[p1+1]>A[p1])
            p1++;
        while(p2>0&&A[p2-1]>A[p2])
            p2--;
        
        cout<<p1<<" "<<p2;
        
        
        return (p1==p2)&&(p1>0)&&(p1<n-1)?true:false;
    }
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};
/*My code assumes the array is a mountain . It binary searches for the peak .
If along the way one of the elements breaks the invariant (i.e is neither increasing nor decreasing) we return false.
At the end , if no peak is found we return false.
If a peak is found we use a heuristic in order to avoid linearly searching .
The longest "true" mountain array possible is 0,1,2..n,n-1,n-2...0 , as such if the index of the peak is strictly greater
then it's value it means that a repetition must have occured along the way.Same for size-peakIndex > peak but for the 
second half.
If both binary search and the heuristic fail to return an answer then we do an O(N) linear search in orderd to check 
the invariant.
The best running time I got was 28ms (98.26%) without any stdio sync tricks , it is highly variable though.
The worst case asymptotic running time is O(N) + O(logN) = O(N) , it precisely happens when the array actually is a 
mountain array.*/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int left =1;
	 int size = A.size();
    int right = size-2;
    int mid;
    bool found = false;
    int val;
    int next;
    int prev;
    while(left <= right){
        mid = left + (right-left)/2;
         val = A[mid];
        next = A[mid+1];
        prev = A[mid-1];
        if(val>prev && val > next ){
            found = 1;
            break; 
        }
        if( (val>next) ){
            right = mid-1;
        }else
        if(val<next){
            left = mid+1;
        }else return false;
    }
    if(found == false) return false;
    if(mid>val) return false;
    if(size-mid>val)return false;
	//another heuristic in case we landed on a local maximum
	if(mid>=2){
    int prevF = A[mid/2-1];
         int nextF = A[(mid+size-1)/2+1];
    if(val<=prevF || val<=nextF || mid/2-1>prevF  ) return false;
    }
    int peak = mid;
    for(int i=0;i<peak-1;++i){
        if(A[i]>=A[i+1] ){
            return false;
        }
    }
    for(int i=peak+1;i<size-1;++i){
        if(A[i]<= A[i+1]){
            return false;
        }
    }
  
    return true;
    }
};