class Solution {
public:
    int l = 1, n, findLengthOfLCIS(vector<int>& v) {
        n = v.size();
        
        if(n == 0) return 0;
        
        for(int i = 1, c = 1; i < n; ++i) {
            if(v[i] > v[i - 1]) {
                c++;
                l = (l < c) ? c : l;
            }
            else {
                c = 1;
            }
        }
        
        return l;
    }
};
