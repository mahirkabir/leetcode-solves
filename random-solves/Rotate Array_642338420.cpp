class Solution {
public:
    /*int get_final_pos(int n, int k, int pos) {
        if (pos + k < n)
            return pos + k;
        return (pos + k) - n;
    }*/
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        //1, 2, 3, 4, 5, 6 => 2, 3, 4, 5, 6, 1
        vector<int> ans = nums;
        
        int st = 0;
        int en = n - 1;
        
        for (int i = k - 1; i >= 0; --i)
            ans[i] = nums[en--];
        
        for (int i = k; i < n; ++i)
            ans[i] = nums[st++];
        
        nums = ans;
    }
};
