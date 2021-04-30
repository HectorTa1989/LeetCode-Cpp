/*Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
 

Example 1:

Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
 

Constraints:

1 <= length <= 50000
At most 50000 calls will be made to set, snap, and get.
0 <= index < length
0 <= snap_id < (the total number of times we call snap())
0 <= val <= 10^9*/

struct SnapRecord {
    int snap_id;
    int value;
};

class SnapshotArray {
public:
    SnapshotArray(int length) {
        snap_id = 0;
        records.resize(length);
    }
    
    void set(int index, int val) {
        vector<SnapRecord>& index_records = records[index];
        
        if (!index_records.empty() && index_records.back().snap_id == snap_id) {
            index_records.back().value = val;
        } else {
            index_records.push_back(SnapRecord{snap_id, val});   
        }
    }
    
    int snap() {
        int result = snap_id;
        snap_id += 1;
        return result;
    }
    
    int get(int index, int snap_id) const {
        const vector<SnapRecord>& index_records = records[index];
        
        if (index_records.empty()) {
            return 0;
        }
        
        if (snap_id < index_records[0].snap_id) {
            return 0;
        }
        
        int left = 0;
        int right = index_records.size();
        
        while (right - left > 1) {
            int middle = (left + right) / 2;
            
            if (index_records[middle].snap_id <= snap_id) {
                left = middle;
            } else {
                right = middle;
            }
        }
        
        return index_records[left].value;
    }
    
private:
    int snap_id;
    vector<vector<SnapRecord>> records;
};

//Binary search. We store the history of snapshots. history[index] is the list of snapshots of the element at index. 
//Each elements of history[index] is a pair of the time we set the value of element[index] (snap_id) & val. 
//We only add an element to history[index] when there's at least 1 time we set the value at index. 
//There will be no new element of history[index] until we set a value for element[index] with a new snap_id.
//Each history[index] is increasing according to snap_id. To get the value of element[index] with a snap_id, 
//we can use binary search.
class SnapshotArray {
    vector<vector<pair<int, int>>> history; // pair<snap_id, val>
    int curSnap;
public:
    SnapshotArray(const int& length) { // O(length)
        history.resize(length, {{-1, 0}});
        curSnap = 0;
    }
    
    void set(const int& index, const int& val) { // amortized O(1)
        if (history[index].back().first < curSnap)
            history[index].push_back({curSnap, val});
        else
            history[index].back().second = val;
    }
    
    int snap() { // O(1)
        return curSnap++;
    }
    
    int get(const int& index, const int& snap_id) { // O(log curSnap)
        return (upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, INT_MAX)) - 1)->second;
    }
};

//Map
class SnapshotArray {
public:
    unordered_map<int,map<int,int>> m;
    int id;
    SnapshotArray(int length) {
        id = 0;
    }
    
    void set(int index, int val) {
        m[index][id] = val;
    }
    
    int snap() {
        int x = id;
        id++;
        return x;
    }
    
    int get(int index, int snap_id) {
        if(m.find(index) == m.end())return 0;
        auto pos = m[index].lower_bound(snap_id);
        if(pos->first != snap_id && pos == m[index].begin())return 0;
        if(pos->first != snap_id )pos--;
        if(pos == m[index].end())pos--;
        return pos->second;
    }
};