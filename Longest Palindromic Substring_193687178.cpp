class Solution {
public:
    int dp[1000 + 5][1000 + 5];
    map<int, string> mp;
    string s;
    
    string isPal(int st, int en) {
        int _st = st, _en = en;
        string res = "";
        while(st < en) {
            if(s[st] != s[en])
                return "";
            
            st++, en--;
        }
        return s.substr(_st, _en - _st + 1);
    }
    
    int DP(int st, int en) {
        if(st == en) {
            mp[1] = s[st];
            return 1;
        }
        if(st > en) {
            mp[0] = "";
            return 0;
        }
        
        int &ret = dp[st][en];
        if(ret != -1)
            return ret;
        
        string strPal = isPal(st, en);
        if(strPal != "") {
            mp[en - st + 1] = strPal;
            return ret = en - st + 1;
        }
        
        int p1 = DP(st, en - 1);
        int p2 = DP(st + 1, en);
        
        return ret = max(p1, p2);
    }
    
    string longestPalindrome(string _s) {
        s = _s;
        memset(dp, -1, sizeof dp);
        mp.clear();
        
        int ans = DP(0, s.length() - 1);
        
        return mp[ans];
    }
};
