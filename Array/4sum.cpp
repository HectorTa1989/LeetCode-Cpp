//Method 1: https://leetcode.com/problems/4sum/discuss/8549/

vector<vector<int>> 4sum(vector<int> nums, int target)
{
	vector<vector<int>> res;
	int n = nums.size();
	
	if(n < 4)
		return res;
		
	sort(nums.begin(), nums.end());
	
	for(int i = 0; i < n-3; i++)
	{
		if(i > 0 && nums[i] == nums[i-1]) continue; //to avoid duplicates through first value
		if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
		if(nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
		
		for(int j = i + 1; j < n - 2; j++)
		{
			if(j > i+1 && nums[j] == nums[j-1]) continue; //to avoid duplicates through second value
			if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
			if(nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
			
			int left = j+1, right = n-1;
			
			while(left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] +nums[right];
				if(sum < target) left++;
				else if(sum > target) right--;
				else
				{
					res.push_back({nums[i], nums[j], nums[left], nums[right]});
					do{left++;}while(left < right && nums[left] == nums[left -1]); //to avoid duplicates through third value
					do{right--;}while(left < right && nums[right] == nums[right+1]); //to avoid duplicates through fourth value
				}
			}
		}
	}
	return res;
}

/*
//Method 2: https://leetcode.com/problems/4sum/discuss/8714/4Sum-C%2B%2B-solution-with-explanation-and-comparison-with-3Sum-problem.-Easy-to-understand.

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > res;
        if (num.size() < 4)
            return res;
        std::sort(num.begin(),num.end());
        int i, j;
        while (i < num.size() - 3)
        {
            j = i+1;
            while (j < num.size() - 2)
            {
                int target_2 = target - num[i] - num[j];
                int front = j + 1;
                int back = num.size() - 1;
                while(front < back) {
                    int two_sum = num[front] + num[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                        // Processing the duplicates of number 4 
                        while (front < back && num[back] == quadruplet[3]) --back;
                    } } // Processing the duplicates of number 2 
                while(j < num.size() - 2 && num[j + 1] == num[j++]);
            } // Processing the duplicates of number 1 
            while (i < num.size() - 3 && num[i + 1] == num[i++]);
        }
        return res;
    } 
};*/

// Method 3:
#include <unordered_map>
#include <vector>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> Pair;

// Function to check if Quadruplet exists in an array with given sum
bool quadTuple(int arr[], int n, int sum)
{
	// create an empty map
	// key -> sum of a pair of elements in the array
	// value -> vector storing index of every pair having that sum
	unordered_map<int, vector<Pair>> map;

	// consider each element except last element
	for (int i = 0; i < n - 1; i++)
	{
		// start from i'th element till last element
		for (int j = i + 1; j < n; j++)
		{
			// calculate remaining sum
			int val = sum - (arr[i] + arr[j]);

			// if remaining sum is found in the map,
			// we have found a Quadruplet
			if (map.find(val) != map.end())
			{
				// check every pair having sum equal to remaining sum
				for (auto pair : map.find(val)->second)
				{
					int x = pair.first;
					int y = pair.second;

					// if Quadruplet don't overlap, print it and return true
					if ((x != i && x != j) && (y != i && y != j))
					{
						cout << "Quadruplet Found (" 
							 << arr[i] << ", " << arr[j] << ", " << arr[x]
							 << ", " << arr[y] << ")";
						return true;
					}
				}
			}

			// insert current pair into the map
			map[arr[i] + arr[j]].push_back({i, j});
		}
	}

	// return false if Quadruplet don't exist
	return false;
}

// main function
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 20;

	int n = sizeof(arr) / sizeof(arr[0]);

	if (!quadTuple(arr, n, sum))
		cout << "Quadruplet Don't Exist";

	return 0;
}


