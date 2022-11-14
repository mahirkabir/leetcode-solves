class Solution {
public:
    
    string str;
    int dp[1000 + 5][1000 + 5];
    map<int, string> mp;
    int DP(int st, int en) {
        if (st == en) {
            mp[1] = str[st];
            return 1;
        }
        if (st > en) {
            mp[0] = "";
            return 0;
        }
        
        int &ret = dp[st][en];
        if (ret != -1)
            return ret;
        
        int n = en - st + 1;
        int sti = st, eni = en;
        while(sti < eni) {
            if (str[sti++] != str[eni--]) {
                sti = -1;
                break;
            }
        }
        
        if (sti != -1) {
            mp[en - st + 1] = str.substr(st, en - st + 1);
            return ret = en - st + 1;
        }
                        
        int p1 = DP(st + 1, en);
        int p2 = DP(st, en - 1);
        
        return ret = max(p1, p2);
    }
    
    string longestPalindrome(string s) {
        str = s;
        memset(dp, -1, sizeof dp);
        mp.clear();
        return mp[DP(0, s.length() - 1)];
    }
};
