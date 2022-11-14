class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque < pair < int, int > > d;
        int width = 0;
        vector < int > ans;
        for( int i = 0; i < n; ++i ) {
            if( !d.empty() ) {
                pair < int, int > curr = d.front();
                if( i - curr.first == k ) d.pop_front();
            }
            while( !d.empty() && d.back().second < nums[i] ) d.pop_back();
            d.push_back(make_pair(i, nums[i]));
            width++;
            if( width >= k ) ans.push_back(d.front().second); 
        }
        return ans;
    }
};
