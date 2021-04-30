//https://www.techiedelight.com/find-triplet-given-with-given-sum/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Function to check if triplet exists in array with given sum
bool tripletExists(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// insert (element, index) pair in map for each element in the array
	for (int i = 0; i < n; i++)
		map[arr[i]] = i;

	// consider each element except last element
	for (int i = 0; i < n - 1; i++)
	{
		// start from i'th element till last element
		for (int j = i + 1; j < n; j++)
		{
			// remaining sum
			int val = sum - (arr[i] + arr[j]);

			// if remaining sum is found, we have found a triplet
			if (map.find(val) != map.end())
			{
				// if triplet don't overlap, return true
				if (map[val] != i && map[val] != j)
					return true;
			}
		}
	}

	// return false if triplet don't exists
	return false;
}

// Method 2: Knapsack 
/*

// Naive recursive function to check if triplet exists in array
// with given sum
bool tripletExists(int arr[], int n, int sum, int count)
{
	// if triplet has desired sum, return true
	if (count == 3 && sum == 0)
		return true;

	// return false if sum is not possible with current configuration
	if (count == 3 || n == 0 || sum < 0)
		return false;

	// recur with
	// 1. including current element
	// 2. excluding current element
	return tripletExists(arr, n - 1, sum - arr[n - 1], count + 1) ||
			tripletExists(arr, n - 1, sum, count);
}

// Find Triplet with given sum in an array
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 6;

	int n = sizeof(arr) / sizeof(arr[0]);

	tripletExists(arr, n, sum, 0) ? cout << "Triplet Exists":
								cout << "Triplet Don't Exist";

	return 0;
}*/

// Find Triplet with given sum in an array
int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 6;

	int n = sizeof(arr) / sizeof(arr[0]);

	tripletExists(arr, n, sum) ? cout << "Triplet Exists":
								cout << "Triplet Don't Exist";

	return 0;
}