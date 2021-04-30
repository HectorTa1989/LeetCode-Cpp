
/*Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), 
the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, 
return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation: 
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.*/


Define a std::map to map from event start to end which is perfect for events since it is sorted by keys automatically.

NOTE: once found a potential insertion i location for new event, use emplace_hint to speed up insertion.
//Runtime: 176 ms, faster than 53.72% of C++ online submissions for My Calendar I.
//Memory Usage: 38.8 MB, less than 16.67% of C++ online submissions for My Calendar I.
class MyCalendar 
{
private:
    map<int, int> _events;
    
public:
    MyCalendar() { }
    
    bool book(int s, int e) {
        auto i = _events.lower_bound(s);
        if (i != _events.end() && i->first < e || i != _events.begin() && (--i)->second > s) return false;
        _events.emplace_hint(i, s, e);
        return true;
    }
};

//Runtime: 580 ms, faster than 5.46% of C++ online submissions for My Calendar I.
//Memory Usage: 43.7 MB, less than 16.67% of C++ online submissions for My Calendar I.
class MyCalendar {
private:
    map<int,int> m;
public:
   bool canAdd(){//check for double-booking
       int count=0;
       for (auto entry: m){
           count+=entry.second;
           if(count>1) return false;
       }
       return true;
   }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        if (canAdd()) return true;
        else{//restore the original values since we are not booking this room
            m[start]--;
            m[end]++;
            return false;
        }
    }
};