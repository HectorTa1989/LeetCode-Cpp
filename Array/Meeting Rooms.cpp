/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 class Solution
 {
	public:
		bool canAttendMeetings(vector<Interval>& intervals) { 
			sort(intervals.begin(), intervals.end(), compare);
			for(int i = 0; i < intervals.size() - 1; i++)
			{
				if(overlap(intervals[i], intervals[i + 1]))
					return false;
			}
			return true;
		}
	private:
		static bool compare(Interval& interval1, Interval& interval2)
		{
			return interval1.start < interval2.start;
		}
		bool overlap(Interval& interval1, Interval& interval2)
		{
			return interval1.end > interval2.start;
		}
 };