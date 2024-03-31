class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char, int> mp;
        int st = 0;
        int en = 0;
        
        int ans = 0;
        int curr = 0;
        
        while(en < n) {
            mp[s[en]]++;
            curr++;
            
            if(mp[s[en]] > 1) {
                while(mp[s[st]] == 1) {
                    mp[s[st]]--;
                    st++;
                }
                
                st++;
                curr = en - st + 1;
                mp[s[en]]--;
            }
            
            ans = max(curr, ans);
            en++;
        }
        
        ans = max(curr, ans);
        
        
        return ans;
    }
};
