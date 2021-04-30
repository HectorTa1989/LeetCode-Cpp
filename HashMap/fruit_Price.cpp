class Fruit
{
	int TotalPrice;
	int minPrice, maxPrice;
	int count;
	
	public:
		Fruit();
		~Fruit();
		int getMinprice()
		{
			return minPrice;
		}
		void addPrice()
		{
			TotalPrice++;
		}
		
};

void calculatePrices(vector<pair<string, int>> fruits)
{
	map<string, Fruit> fruitMap;
	for(int i=0; i<fruits.size(); i++)
	{
		if(fruitMap.find(fruits[i].first) != fruitMap.end())
			fruitMap[fruits[i].first].addPrice(fruits[i].second);
		else
			fruitMap[fruits[i].first]
	
}