/*Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 

Example 1:

Input: arr = [2,3,1,6,7]
Output: 4
Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
Example 2:

Input: arr = [1,1,1,1,1]
Output: 10*/

//Runtime: 4 ms, faster than 95.42% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
//Memory Usage: 7.5 MB, less than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
class Solution{
public:
  int countTriplets(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        int n = arr.size(), ans = 0;
        for (int i = 1; i < n; ++i)
            arr[i] ^= arr[i - 1];
			
        for (int i = 0; i < n; ++i){
            for (int j = i + 1; j < n; ++j){
                if (arr[i] == arr[j]) ans+= j - i - 1;
					}
				}
        return ans;
    }

};

//Runtime: 4 ms, faster than 95.42% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
//Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.

// ---i----j----k--
// if(i to j XOR == j to k XOR then i to k XOR = 0)
// ---i------k--
// if(xor till i == x and xor till k == x then i to k xor == 0)
// so we will traverse the array and store the xor value till i
// if we found a xor value that already exists in map then we
// add number of triplets to the ans;
// number of triplets from i to k will be i - k - 1 and if the same xor value appeared for the third time fourth time ans so on the the calculated no of triplets (general formula ) becomes =
// currentIndex * noOfElements(found previously with same xor) - sumOfIndicesWhereTheXorValueWasFound - noOfElements(found previously with same xor)

// ..formula 1

// example :

// if(xor value found at 1 and 5 is 3 )
// ----1---5--
// ans = 5 - 1 - 1
// = 3;
// again at 10 we found xor value to be 3
// then it can form triplets with both 1 and 5
// then( 10 - 5 - 1) + (10 - 1 -1) = 2*10 - 6 - 2
// which is formula 1


struct MyPair{
    int sumOfIndex, noOfELe;
};
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        int xorValue = 0;
        unordered_map<int,MyPair> u;
        int i;
        MyPair m;
        m.sumOfIndex = -1;
        m.noOfELe = 1;
        u[0] = m;
        for(i = 0; i < n; i++){
            xorValue ^= arr[i]; 
            if(u.find(xorValue) != u.end()){
                MyPair m = u[xorValue];
                count +=  (i) * m.noOfELe - m.sumOfIndex - m.noOfELe;
                m.sumOfIndex += i;
                m.noOfELe++;
                u[xorValue] = m;
             }else{
                MyPair m;
                m.sumOfIndex = i;
                m.noOfELe = 1;
                u[xorValue] = m;
            }
        }
        return count;
    }
};