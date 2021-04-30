int searchKey(int arr[], int l, int h, int key)
{
	if(l>h) return -1;
	int mid = l + (h-l)/2;
	
	if(arr[mid] == key) return mid;
	if(arr[l] <= arr[mid])
	{
		if(key > arr[l] && key < arr[mid])
			return searchKey(arr, l, mid-1, key);
		else
			return searchKey(arr, mid+1, h, key);
	}
	if(arr[mid] < key && arr[h] > key)
		return searchKey(arr, mid+1, h, key);
	else
		return searchKey(arr, l, mid-1, key);
}