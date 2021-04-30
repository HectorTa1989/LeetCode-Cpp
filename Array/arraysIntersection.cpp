// Method 1: https://hwchang0417.wordpress.com/2019/10/06/leetcode-1213-intersection-of-three-sorted-arrays/

class Solution {
public:
    
    void count(map<int, int>& freq, vector<int>& arr){
        for(int n : arr){
            freq[n]++;
        }
    }
    
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> freq;
        vector<int> res;
        
        count(freq, arr1);
        count(freq, arr2);
        count(freq, arr3);
        
        for(pair<int, int> p : freq){
            if(p.second == 3){
                res.push_back(p.first);
            }
        }
        
        return res;
    }
};


// Method 2: geeksforgeeks
void findCommon(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
	int i=0, j=0, k=0;
	while(i<n1 && j<n2 && k<n3)
	{
		if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
		{
			cout << arr1[i] << " "; 
			i++;
			j++;
			k++;
		}
		if(arr1[i] < arr2[j])
			i++;
		else if(arr2[j] < arr3[k])
			j++;
		else
			k++;
	}
}