class Solution {
public:
    vector<int> ans, searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] == target) {
                if(ans.size() == 1)
                    ans.pop_back();
                
                ans.push_back(mid);
                hi--;
            }
            else {
                if(nums[mid] > target)
                    hi = mid - 1;
                else if(nums[mid] < target) {
                    lo = mid + 1;
                }
            }
        }
        
        lo = 0, hi = n - 1;
        
        while(lo <= hi) {
            int mid = hi - (hi - lo)/2;
            
            if(nums[mid] == target) {
                if(ans.size() == 2)
                    ans.pop_back();
                
                ans.push_back(mid);
                lo++;
            }
            else {
                if(nums[mid] > target)
                    hi = mid - 1;
                else if(nums[mid] < target) {
                    lo = mid + 1;
                }
            }
        }
        
        if(ans.size() == 0)
            ans.push_back(-1), ans.push_back(-1);
        
        return ans;
    }
};
