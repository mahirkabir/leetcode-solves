class Solution {
public:
    string s;
    string p;
    
    int sn, pn;
    int dp[1000 + 5][1000 + 5];
    
    bool isSame(int i, int j) {
        return s[i] == p[j] || p[j] == '.';
    }
    
    int DP(int i, int j) {
        //cout << i << " s " << s[i] << endl;
        //cout << j << " p " << p[j] << endl;
        
        if(j < 0) {
            return i < 0;
        }
        if(i < 0) {
            if(j < 0)
                return 1;
            if(j == 0)
                return 0;
            if(p[j] == '*')
                return DP(i, j - 2);
            return 0;
        }
        
        int &ret = dp[i][j];
        if(ret != -1)
            return ret;
        
        int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
        
        if(isSame(i, j)) {
            p1 = DP(i - 1, j - 1);
        }
        else if(p[j] == '*') {
            if(isSame(i, j - 1)) {
                p2 = DP(i - 1, j); //take multiple times
                p3 = DP(i - 1, j - 2); //take once
            }
            p4 = DP(i, j - 2); //do not take
        }
        
        return ret = p1 + p2 + p3 + p4 + p5;
    }
    
    bool isMatch(string _s, string _p) {
        s = _s;
        p = _p;
        
        sn = s.length();
        pn = p.length();
        
        memset(dp, -1, sizeof(dp));
        
        return DP(sn - 1, pn - 1) >= 1;
    }
};
