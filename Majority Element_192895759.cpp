class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            if(mp[nums[i]] >= (n / 2))
                return nums[i];
            mp[nums[i]]++;
        }
        
        return nums[0];
    }
};
