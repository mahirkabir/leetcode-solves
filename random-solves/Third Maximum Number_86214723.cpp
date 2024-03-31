class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int MIN_INT = -2147483648;
        long long first = MIN_INT, second = MIN_INT, third = MIN_INT, org = MIN_INT;
        first--, second--, third--, org--;
        bool f = false, s = false, t = false;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
                f = true;
            }
            else if(nums[i] > second && nums[i] != first) {
                third = second;
                second = nums[i];
                s = true;
            }
            else if(nums[i] > third && nums[i] != second && nums[i] != first) {
                third = nums[i];
                t = true;
            }
        }
        if(third != org) return third;
        return first;
    }
};
