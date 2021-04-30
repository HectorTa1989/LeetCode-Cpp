//Method 1
/*This is a pattern repeating problem

This pattern repeats for every 14 days, if we take out day 0 from the pattern
Day 0 never repeats beacuse of corners allways become zero
calculate cells for one day
From here everything repeats
Since I advanced by one day so i will subtract one day from N days
The days needs to be calculated are (N - 1) % 14*
*/

class Solution {

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N == 0) return cells;
        prison(cells, 1);              //Prison cells for one day, The pattern repeats from day 1 - 14
        prison(cells, (N - 1) % 14);         //Simply day 14 = day 1, Day 0 never repeats because of corners  
        return cells;                               
    }
    void prison(vector<int>& cells, const int& N){
        for(int i = 0; i < N; i++){
            vector<int> v(8,0);
        for(int i = 1; i < 7; i++)
            if(cells[i - 1] == cells[i + 1])
                v[i] = 1;
            else v[i] = 0;
        cells = v;
        }
    }
};

//Method 2: 0ms, O(1) space, O(1) time
class Solution {
public:
    int countNeighbors(const vector<int>& cells, const int n) {
        int count = 0;
        if (n > 0 && cells[n-1] >= 1)
            ++count;
        if (n < cells.size()-1 && cells[n+1] >= 1)
            ++count;
        return count;
    }
    
    // Output: 2 if currently occupied but will be vacant, -1 if
    // currently vacant but will be occupied, 1 if stay occupied,
    // or 0 if stay vacant.
    int getAction(const vector<int>& cells, const int n) {
        int currentState = cells[n];
        if (n == 0 || n == cells.size()-1) {
            if (currentState == 1)
                return 2;
            return 0;
        }
        int neighborCount = countNeighbors(cells, n);
        if (neighborCount == 2 || neighborCount == 0) {
            if (currentState == 1)
                return 1;
            return -1;
        }
        if (currentState == 0)
            return 0;
        return 2;
    }

    void prisonAfter1Day(vector<int>& cells) {
        int len = cells.size();
        
        // Assign actions to cells given the current state.
        for (int i = 0; i < len; ++i) {
            cells[i] = getAction(cells, i);
        }
        
        // Transitions to the next state based on actions.
        for (int i = 0; i < len; ++i) {
            if (cells[i] == 2)
                cells[i] = 0;
            else if (cells[i] == -1)
                cells[i] = 1;
        }
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        // After the first iteration, the cycle repeats itself
        // every 14 days.
        for (int i = 0; i <= (N-1)%14; ++i) {
            prisonAfter1Day(cells);         
        }
        return cells;
    }
};

//Method 3
/*Key Observations:

The cell state next day is ocmpletely determined by today and only today.
The total number of all possibly different states for the 8 cells is 2<<8 = 256. So as days go by, there must be repeating patterns for cell states (Pigeonhole Principle).
Therefore, we do NOT need to iterate all N days to compute all state. As days go by, we keep a hash map to map state to day index and also an array to track day index to state. 
Once a state is seen before, use mod % to get state on day N directly.

NOTE:

A 8-cell state is small enough to be coverred by an int, whose bits indicate each cell status, respectively.
I did NOT go deep to mathematically prove exactly what is the repeating pattern (i.e., length of cycle, starting day of first cycle) since the algorithm below is already O(1) in both 
time and space.*/
    
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {      
      // map day to cell state (day 0 is initial state)
      int day2state[(2<<8)+1]; // 2<<8: number of all states
      
      // map cell state to day
      unordered_map<int, int> state2day;
      
      // initial state
      int state = 0;
      for (int cell : cells)
        (state<<=1) += cell;
            
      int day = 0;
      while (day < N && state2day.count(state) == 0) {
        state2day[state] = day;
        day2state[day] = state;
        
        nextState(state);
        day++;
      }
      
      // found a repeat state
      if (state2day.count(state) > 0) {
        int prev_day = state2day[state];
        state = day2state[(N-prev_day)%(day-prev_day) + prev_day];
      }
            
      // convert state to cells
      for (int i = 0; i < 8; i++) {
        cells[7-i] = state & 1;
        state >>= 1;
      }
      
      return cells;
    }
  
    // get next state by the rules 
    void nextState(int& state) {
      int next = 0;
      for (int bit_pos = 1; bit_pos < 7; bit_pos++) {
        if (((state>>(bit_pos+1)) & 1) == ((state>>(bit_pos-1)) & 1))
          next |= (1<<bit_pos);
      }
      state = next;
    }