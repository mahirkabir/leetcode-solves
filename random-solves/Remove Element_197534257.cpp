class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int ans = 0;
        int st = 0, en = n - 1;
        
        while(st <= en) {
            if(nums[st] == val) {
                if(nums[en] != val) {
                    int t = nums[en];
                    nums[en] = nums[st];
                    nums[st] = t;
                    st++;
                    en--;
                    ans++;
                }
                else {
                    en--;
                }
            }
            else {
                st++;
                ans++;
            }
        }
        
        
        return ans;
    }
};
