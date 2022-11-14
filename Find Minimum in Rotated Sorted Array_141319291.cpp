class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            //cout << l << " " << r << endl;
            
            if(r - l == 1) {
                return min(nums[l], nums[r]);
            }
            
            if(nums[l] < nums[r]) {
                return nums[l];
            }
            else {
                int mid = (l + r) / 2;
                
                if(nums[mid] < nums[l]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
        }
        
        return nums[l];
    }
};
