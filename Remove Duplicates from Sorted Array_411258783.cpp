class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return n;
        
        int st = 0;
        int en = 1;
        int len = 1;
        
        while(en < n) {
            if(nums[en] != nums[st]) {
                st++;
                
                int t = nums[st];
                nums[st] = nums[en];
                nums[en] = t;
                len++;
            }
            en++;
        }
        
        int popcnt = n - (st + 1);
        while(popcnt-- > 0)
            nums.pop_back();
        
        return len;
    }
};
