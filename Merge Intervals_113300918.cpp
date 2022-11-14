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
    static bool cmp(Interval a, Interval b) {
        if(a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int n = intervals.size();
        
        vector <Interval> ans;
        
        Interval curr = intervals[0];
        for(int i = 1; i < n; ++i) {
            Interval tmp = intervals[i];
            
            if(curr.end >= tmp.start) {
                curr.end = max(curr.end, tmp.end);
            }
            else {
                ans.push_back(curr);
                curr = tmp;
            }
        }
        
        ans.push_back(curr);
        
        return ans;
    }
};
