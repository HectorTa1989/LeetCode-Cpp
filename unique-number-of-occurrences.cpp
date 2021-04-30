/*We create an unordered map of integers and their frequencies.
Then, we traverse the map and put the frequency values (Values in map) into a set.
Then, if all the occurences were unique, then we would have the size of set to be equal to the size of the map. */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        set<int> s;
        for(int i = 0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            s.insert(it->second);
        }
        
        if(s.size()==m.size()) return true;
        return false;
        
    }
};