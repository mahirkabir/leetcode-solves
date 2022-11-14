class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int mnDiff = arr[1] - arr[0];
        for(int i = 2; i < n; ++i)
            mnDiff = min(mnDiff, arr[i] - arr[i - 1]);
        
        vector<vector<int>> ans;
        
        for(int i = 1; i < n; ++i) {
            if(arr[i] - arr[i - 1] == mnDiff) {
                vector<int> v;
                v.push_back(arr[i - 1]);
                v.push_back(arr[i]);
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};
