class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        
        for (int st = 0; st < n - 2; ++st) {
            int en = n - 1;
            
            while (st < en - 1) {
                int lo = st + 1;
                int hi = en - 1;
                
                int fx = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    // cout << st << mid << en << endl;
                    if (nums[st] + nums[mid] > nums[en]) {
                        fx = mid;
                        hi = mid - 1;
                    }
                    else {
                        lo = mid + 1;
                    }
                }
                
                if (fx != -1) {
                    ans += (en - fx);
                    // cout << st << " " << fx << " " << en << endl;
                    // cout << nums[st] << "-" << nums[fx] << "-" << nums[en] << 
                        endl;
                }
                
                en -= 1;
            }
        }
        
        return ans;
    }

