class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> res;
        
        if(a.empty() || b.empty()) return res;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int st = b[0];
        
        int lo = 0, hi = a.size() - 1;
        
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            
            if(a[mid] == st) {
                lo = mid;
                break;
            }
            else if(a[mid] < st) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        
        if(lo >= a.size()) return res;
        
        int ib = 0;
        
        for(int i = lo, n = a.size(), nb = b.size(); i < n; ++i) {
            if(i == lo || a[i] != a[i - 1]) {
                while(b[ib] < a[i] && ib < nb) ib++;
                if(ib < nb && b[ib] == a[i]) res.push_back(b[ib]);
                if(ib == nb) break;
            }
        }
        
        return res;
    }
};
