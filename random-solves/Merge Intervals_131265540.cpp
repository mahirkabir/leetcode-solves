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
        if(a.start == b.start)
            return a.end > b.end;
        return a.start < b.start;
    }
    
    vector<Interval> ans, merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        int n = intervals.size();
        int k = -1;
        
        for(int i = 0; i < n; ++i) {
            if(ans.empty())  {
                ans.push_back(intervals[i]);
                ++k;
            }
            else {
                if(intervals[i].start  > ans[k].end) {
                    ans.push_back(intervals[i]);
                    ++k;
                }
                else {
                    ans[k].end = max(ans[k].end, intervals[i].end);
                }
            }
        }
        
        return ans;
    }
};
