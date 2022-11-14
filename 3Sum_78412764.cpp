class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set <vector<int>> res;
        vector <vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i && nums[i] == nums[i - 1]) continue;
            int st = i + 1;
            int en = n - 1;
            while(st < en) {
                if(nums[i] + nums[st] + nums[en] < 0) st++;
                else if(nums[i] + nums[st] + nums[en] > 0) en--;
                else {
                    vector <int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[st]);
                    v.push_back(nums[en]);
                    
                    res.insert(v);
                    st++;
                    en--;
                }
            }
        }
        
        for(set <vector <int>>::iterator it = res.begin(); it != res.end(); it++) {
            ret.push_back(*it);
        }
        
        return ret;
    }
};
