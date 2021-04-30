class MedianFinder
{	
	vector<int> store;
	
	public:
		void addNum(int num)
		{
			store.push_back(num);
		}
		double findMedian()
		{
			sort(store.begin(), store.end());
			int n = store.size();
			return (n&1 ? store[n/2] : (store[n/2 - 1] + store[n/2])*0.5);
		}
};