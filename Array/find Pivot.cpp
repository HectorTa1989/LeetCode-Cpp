int findPivot(int arr[])
{
	int n = arr.length();
	if(arr == NULL & arr.length() == 0)
		return -1;
	if(arr.length() == 1 && 
	
	int start = 0, end = arr.length - 1;
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(mid < n && arr[mid] > arr[mid+1])
			return mid+1;
		else if(arr[start] < arr[mid])
			start = mid+1;
		else
			end = mid - 1;
	}
	return 0;
}