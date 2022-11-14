class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(mp[nums[i]] &&  i - mp[nums[i]] + 1 <= k) return true;
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};
