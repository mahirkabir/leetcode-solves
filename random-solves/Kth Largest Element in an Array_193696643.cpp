bool cmp(int a, int b) {
    return a > b;
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k - 1];
    }
};
