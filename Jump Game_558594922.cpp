class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        int highest = nums[0]; // highest accessible index;
        
        int curr = 1;
        while(curr < n) {
            if (curr > highest)
                return false;
            highest = max(highest, curr + nums[curr]);
            curr++;
        }
        
        return true;
    }
};
