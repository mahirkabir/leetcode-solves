bool cmp(vector<int> a, vector<int> b) {
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        int st = 0;
        int n = intervals.size();
        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] <= ans[st][1]) {
                ans[st][1] = max(intervals[i][1], ans[st][1]);
            }
            else {
                ans.push_back(intervals[i]);
                st++;
            }
        }
        
        return ans;
    }
};
