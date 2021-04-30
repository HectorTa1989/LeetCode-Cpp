// Method 1: pair struct
class Solution {
public:
    typedef struct{
        int index, value;
    } Pair;
    
    struct sortByValue { inline bool operator() ( const Pair &r1, const Pair &r2 ) { return ( r1.value < r2.value ? true : false ); } };
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return vector<int>();
        vector<int> res(arr.size(), 0);
        vector<Pair> p;
        int idx = 0;
        for(int n : arr) p.push_back({idx++, n});
        sort(p.begin(), p.end(), sortByValue());
        
        int rank = 1, prev = p[0].value;
        for(Pair element : p){
            if(prev != element.value) rank++;
            res[element.index] = rank;
            prev = element.value;
        }
        
        return res;
    }
};


// Method 2
vector<int> arrayRankTransform(vector<int> arr)
{
	set<int> s(arr.begin(), arr.end());
	unordered_map<int, int> rank;
	int position = 1;
	
	for(int x : s) //store unique elements
	{
		rank[x] = position++;  //store index of elements starting from 1 at key value
	}
	for(auto &num : arr)
	{
		num = rank[num];	//put index  on place of values
	}
	return arr;
}