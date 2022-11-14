class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = -1;
        int idx = 0;
        
        int n = nums.size();
        
        while (idx < n) {
            if (nums[idx] != 0) {
                if (zeroIdx != -1) {
                    int t = nums[idx];
                    nums[idx] = nums[zeroIdx];
                    nums[zeroIdx] = t;
                    
                    while (zeroIdx < n && nums[zeroIdx] != 0)
                        zeroIdx++;
                }
            }
            else if (zeroIdx == -1) {
                zeroIdx = idx;
            }
            
            idx++;
        }
    }
};
