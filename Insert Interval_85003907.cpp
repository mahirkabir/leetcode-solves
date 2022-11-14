/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector <Interval> ret;
    
        if(newInterval.end < newInterval.start) {
            int t = newInterval.end;
            newInterval.end = newInterval.start;
            newInterval.start = t;
        }
        
        Interval curr = newInterval;
        int n = intervals.size();
        bool flag = true;
        
        for(int i = 0; i < n; ++i) {
            if(intervals[i].end < curr.start) ret.push_back(intervals[i]);
            else if(intervals[i].start > curr.end) {
                ret.push_back(curr);
                curr = intervals[i];
                flag = false;
            }
            else {
                curr = Interval(min(curr.start, intervals[i].start), max(curr.end, 
                    intervals[i].end));
            }
        }
        
        ret.push_back(curr);
        
        return ret;
    }
};
