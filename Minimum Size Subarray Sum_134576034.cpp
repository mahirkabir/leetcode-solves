class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n = nums.size();
        
        int st = 0;
        int len = n;
        int cnt = 0;
        
        for(int i = 0; i < n; ++i) {
            
            cnt += nums[i];
            
            if(cnt >= s) {
                
                //cout << cnt << " " << st << " " << nums[st] << endl;
                
                while(cnt - nums[st] >= s && st <= i) cnt -= nums[st++];
                
                //cout << cnt << " " << st << " " << nums[st] << endl << endl;
                
                len = min(len, i - st + 1);
            }
        }
        
        return (cnt >= s) ? len : 0;
    }
};
