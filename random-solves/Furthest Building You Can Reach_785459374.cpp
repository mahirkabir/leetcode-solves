class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int ans = 0;
        int n = heights.size();
        for(int i = 1; i < n; ++i) {
            int d = heights[i] - heights[i - 1];
            if (d > 0 && ladders > 0) {
                pq.push(d);
                ladders -= 1;
            }
            else if (d > 0) {
                pq.push(d);
                int top = pq.top();
                pq.pop();
                
                // cout << top << endl;
                
                if (top <= bricks) {
                    bricks -= top;
                }
                else {
                    break;
                }
            }
            ans = i;
        }
        
        return ans;
    }
};
