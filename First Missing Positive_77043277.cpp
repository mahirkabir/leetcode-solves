class Solution {
public:
    vector <int> v;
    int n;
    void fix(int pos) {
        if(v[pos] >= 1 && v[pos] <= n && v[pos] != pos + 1) {
            int idx = v[pos] - 1;
            if(v[idx] == v[pos]) return;
            int t = v[pos];
            v[pos] = v[idx];
            v[idx] = t;
            fix(pos);
        }
        else {
            return;
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        v = nums;
        if(v.empty()) return 1;
        n = v.size();
        for(int i = 0; i < n; ++i) {
            fix(i);
        }
        for(int i = 0; i < n; ++i) {
            if(v[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
