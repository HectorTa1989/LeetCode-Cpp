//https://leetcode.com/problems/binary-subarrays-with-sum/

//Method 1: hash
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        
        int n = A.size();
        int sum = 0, res = 0;
        unordered_map<int, int>hm;
        hm[0] = 1;
        
        
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (hm.find(sum-S) != hm.end())
                res += hm[sum-S];
            hm[sum]++;
        }
        
        return res;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ret = 0, sum = 0;
        unordered_map<int, int> presum; // presum to number
        for( int i=0; i<A.size(); i++ )
        {
            sum += A[i];
            if ( sum == S )
                ret++;
            if ( sum >= S)
                ret += presum[sum - S];
            presum[sum]++;	// preSum[sum] ~ presum[0] ~ presum[sum - S] when sum = S -> presum[sum - S] will be increased 1
        }
        return ret;
    }
};

// Hash
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        if (A == null || A.length == 0) return 0;
        // key: prefix sum value, value: count of key that have been seen so far
        Map<Integer, Integer> counter = new HashMap<>();
        int sum = 0;
        int ans = 0;
        counter.put(0, 1);  // don't forget this trivial case
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            int target = sum - S;
            ans += counter.getOrDefault(target, 0);
            counter.put(sum, counter.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
// Use array instead of Hash
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        if (A == null || A.length == 0) return 0;
        // because A consist of only 1 and 0, the maximum possible prefix sum
        // value is A.length, add 1 to make room for the value of 0
        int[] preSum = new int[A.length + 1];
        preSum[0] = 1;  // subarray of length 0 will have sum of 0
        int ans = 0, sum = 0;
        for (int num : A) {
            sum += num;
            // don't forget to validate the index
            if (sum - S >= 0) ans += preSum[sum - S];
            preSum[sum] += 1;
        }
        return ans;
    }
}

//Method 2: Sliding window
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int res = 0, sum = 0, left = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            while (left < i && sum > S) sum -= A[left++];
            if (sum < S) continue;
            if (sum == S) ++res;
            for (int j = left; j < i && A[j] == 0; ++j) {
                ++res;
            }
        }
        return res;
    }
};
// Sliding window 2
int numSubarraysWithSum(vector<int>& A, int S) {
	int begin {0}, end {-1}, one_pos {-1}, res {0}, sum {0};
	while (end<int(A.size())) {
		if (sum < S) {
			++end;      // increase window to the right by one
			if (end == A.size()) {
				break;  // end of array
			}
			if (A[end] == 1) {
				++sum;
			}
			continue;
		}

		if (sum > S) {
			// shrink window from left
			if (A[begin] == 1) {
				--sum;
			}
			++begin;
			continue;
		}

		// the goal of the above filters is to get here only when subarray [begin:end] has exactly S ones
		// here sum == S.

		// set one_pos to the nearest 1 since begin
		while (one_pos<end && (one_pos<begin || A[one_pos]==0)) {
			// one_pos is position of the first 1 since begin.
			// for example: 0,0,1,0,1. if begin is 0: one_pos must be 2.
			++one_pos; 
		}

		// example: 0,0,1 and S=1. lets say end=2,
		// then 0,0,1 and 0,1 and 1 are all qualifying subarrays. here is the count:
		res += one_pos-begin+1;

		++end;
		if (end<A.size() && A[end]==1) {
			++sum; // we increased end and A[end] is 1: increment sum
		}
	}
	return res;
}

//Method 3: Three Pointer
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int iLo = 0, iHi = 0;
        int sumLo = 0, sumHi = 0;
        int ans = 0;

        for (int j = 0; j < A.length; ++j) {
            // While sumLo is too big, iLo++
            sumLo += A[j];
            while (iLo < j && sumLo > S)
                sumLo -= A[iLo++];

            // While sumHi is too big, or equal and we can move, iHi++
            sumHi += A[j];
            while (iHi < j && (sumHi > S || sumHi == S && A[iHi] == 0))
                sumHi -= A[iHi++];

            if (sumLo == S)
                ans += iHi - iLo + 1;
        }

        return ans;
    }
}
//Time Complexity: O(N)O(N), where NN is the length of A.
//Space Complexity: O(1)O(1).